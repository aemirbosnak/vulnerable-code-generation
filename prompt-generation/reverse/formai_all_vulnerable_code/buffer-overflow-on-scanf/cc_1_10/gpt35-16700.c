//FormAI DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXCHAR 1000

// This function checks if the bit at a particular position is 1 or 0
bool getBit(char byte, int position) {
    return (byte & (1 << position)) != 0;
}

// This function sets the bit at a particular position to 1 or 0
char setBit(char byte, int position, bool value) {
    if (value)
        byte |= (1 << position);
    else
        byte &= ~(1 << position);
    return byte;
}

// This function hides a message in an image
void hideMessage(char* input_image_filename, char* secret_message) {

    // Open the input file
    FILE* input_image = fopen(input_image_filename, "rb");
    if (input_image == NULL) {
        printf("Error opening input image file.\n");
        exit(1);
    }

    // Open the output file
    FILE* output_image = fopen("stego_image.bmp", "wb");
    if (output_image == NULL) {
        printf("Error opening output image file.\n");
        exit(1);
    }

    // Read and write the header
    char header[54];
    fread(header, sizeof(char), 54, input_image);
    fwrite(header, sizeof(char), 54, output_image);

    // Hide the message in the data
    int message_length = strlen(secret_message);
    char message[MAXCHAR];
    strcpy(message, secret_message);
    strcat(message, "$"); // Add a delimiter to the end of the message
    int message_position = 0;
    bool end_of_message = false;

    // Loop through each pixel in the input image
    char pixel[3];
    while (fread(pixel, sizeof(char), 3, input_image) == 3) {

        // Loop through each bit in the pixel
        for (int i = 0; i < 3; i++) {
            char byte = pixel[i];
            if (!end_of_message && message_position < message_length * 8) {
                bool bit = getBit(byte, 0);
                bit = getBit(message[message_position/8], message_position%8) ? bit : !bit; // Flip the bit if necessary
                byte = setBit(byte, 0, bit);
                message_position++;
                if (message_position == message_length * 8 + 8) // Check for end of message
                    end_of_message = true;
            }
            fwrite(&byte, sizeof(char), 1, output_image);
        }
    }

    // Close the files
    fclose(input_image);
    fclose(output_image);
    printf("Steganography complete!\n");
}

// This function extracts a message from an image
void extractMessage(char* stego_image_filename) {

    // Open the input file
    FILE* input_image = fopen(stego_image_filename, "rb");
    if (input_image == NULL) {
        printf("Error opening stego image file.\n");
        exit(1);
    }

    // Extract the message from the data
    int message_position = 0;
    bool end_of_message = false;
    char message[MAXCHAR];
    memset(message, 0, sizeof(message));

    // Loop through each pixel in the input image
    char pixel[3];
    while (fread(pixel, sizeof(char), 3, input_image) == 3) {

        // Loop through each bit in the pixel
        for (int i = 0; i < 3; i++) {
            char byte = pixel[i];
            bool bit = getBit(byte, 0);
            message[message_position/8] = setBit(message[message_position/8], message_position%8, bit);
            message_position++;
            if (message[message_position/8] == '$' && message_position%8 == 0) // Check for end of message
                end_of_message = true;
            if (end_of_message)
                break;
        }
        if (end_of_message)
            break;
    }

    // Close the file
    fclose(input_image);

    // Print the message
    printf("The secret message is: %s\n", message);
}

int main() {
    printf("Welcome to my image steganography program!\n\n");
    printf("Do you want to hide a message or extract a message? (hide/extract): ");
    char option[10];
    scanf("%s", option);

    if (strcmp(option, "hide") == 0) {
        printf("\nEnter the name of the input image file (bmp only): ");
        char input_image_filename[100];
        scanf("%s", input_image_filename);

        printf("\nEnter the secret message you want to hide: ");
        char secret_message[MAXCHAR];
        scanf(" %[^\n]s", secret_message);

        hideMessage(input_image_filename, secret_message);
    }
    else if (strcmp(option, "extract") == 0) {
        printf("\nEnter the name of the stego image file (bmp only): ");
        char stego_image_filename[100];
        scanf("%s", stego_image_filename);

        extractMessage(stego_image_filename);
    }
    else {
        printf("Invalid option. Please try again.\n");
    }

    return 0;
}