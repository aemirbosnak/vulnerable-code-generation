//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1000
#define MAX_FILENAME_SIZE 100

// Function to open the image file in binary mode
FILE* open_image(const char* filename, const char* mode) {
    FILE* image = fopen(filename, mode);
    if (image == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    return image;
}

// Function to embed a message into the image
void embed_message(const char* img_filename, const char* msg, const char* output_filename) {
    FILE* img = open_image(img_filename, "rb");
    FILE* output_img = open_image(output_filename, "wb");
    
    unsigned char byte;
    int msg_len = strlen(msg);
    int msg_index = 0;

    // Write BMP header directly
    for (int i = 0; i < 54; i++) {
        fread(&byte, sizeof(unsigned char), 1, img);
        fwrite(&byte, sizeof(unsigned char), 1, output_img);
    }

    // Embed message in least significant bit (LSB)
    while (msg_index < msg_len) {
        fread(&byte, sizeof(unsigned char), 1, img);

        // Embed a character from the message into the least significant bit
        byte = (byte & 0xFE) | ((msg[msg_index] >> (msg_index % 8)) & 0x01);

        fwrite(&byte, sizeof(unsigned char), 1, output_img);
        
        msg_index++;
        
        if (msg_index >= msg_len) {
            break;
        }
    }

    // Copy remaining pixel data unchanged
    while (fread(&byte, sizeof(unsigned char), 1, img) == 1) {
        fwrite(&byte, sizeof(unsigned char), 1, output_img);
    }

    fclose(img);
    fclose(output_img);
}

// Function to extract the message from the image
void extract_message(const char* img_filename, char* msg) {
    FILE* img = open_image(img_filename, "rb");
    
    unsigned char byte;
    int msg_index = 0;
    msg[msg_index] = '\0';

    // Skip BMP header
    fseek(img, 54, SEEK_SET);

    // Read each byte and extract LSB for the message
    while (fread(&byte, sizeof(unsigned char), 1, img) == 1) {
        if (msg_index < MAX_MESSAGE_SIZE - 1) {
            // Build the character from the LSBs
            msg[msg_index / 8] |= (byte & 0x01) << (msg_index % 8);
            msg_index++;

            // Stop if we reach end of string (character's null-terminator)
            if (msg_index % 8 == 0 && msg[msg_index / 8 - 1] == '\0') {
                break;
            }
        } else {
            break;
        }
    }

    fclose(img);
}

// Function to get user input safely
void get_user_input(char* buffer, size_t size) {
    printf("Enter message (max %d characters): ", size);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

int main() {
    char img_filename[MAX_FILENAME_SIZE];
    char output_filename[MAX_FILENAME_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char extracted_message[MAX_MESSAGE_SIZE];

    printf("Welcome to the Image Steganography Program!\n");
    printf("Please enter the image filename (BMP format): ");
    scanf("%s", img_filename);

    get_user_input(message, MAX_MESSAGE_SIZE);

    printf("Enter the output image filename: ");
    scanf("%s", output_filename);
    
    // Embed the message into the image
    embed_message(img_filename, message, output_filename);
    printf("Message embedded successfully into the image!\n");

    // Give the user a feedback that extraction is possible
    printf("Now extracting the message from the newly created image...\n");
    
    // Extract the message from the output image
    extract_message(output_filename, extracted_message);
    printf("Extracted message: %s\n", extracted_message);

    return 0;
}