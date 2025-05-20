//FormAI DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    char message[MAX_SIZE];
    char image_name[MAX_SIZE];
    char output_name[MAX_SIZE];
    char next_char;
    char image_data[MAX_SIZE];
    FILE *image;
    FILE *output;
    int i, j, k;
    int bits_to_hide[MAX_SIZE][8];

    printf("Enter the message to be hidden:\n");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter the name of the image file to be used:\n");
    fgets(image_name, MAX_SIZE, stdin);

    printf("Enter the name of the output file:\n");
    fgets(output_name, MAX_SIZE, stdin);

    // Open the image file
    image = fopen(image_name, "rb");

    // Check if file was opened successfully
    if (image == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the image data into image_data array
    i = 0;
    while ((next_char = fgetc(image)) != EOF) {
        image_data[i] = next_char;
        i++;
    }

    // Calculate the number of pixels in the image
    int num_pixels = i / 3;

    // Calculate the number of bits that can be hidden in the image
    int num_bits_to_hide = num_pixels * 3;

    // Check if message can be hidden in the image
    if (strlen(message) > num_bits_to_hide / 8) {
        printf("Error: Message is too long to be hidden in this image\n");
        exit(1);
    }

    // Convert the message characters to binary
    int message_length = strlen(message);
    for (i = 0; i < message_length; i++) {
        for (j = 0; j < 8; j++) {
            bits_to_hide[i][j] = ((message[i] >> j) & 1);
        }
    }

    // Hide the bits in the image
    k = 0;
    for (i = 0; i < num_pixels; i++) {
        if (k >= message_length) break;
        for (j = 0; j < 3; j++) {
            if ((image_data[i*3+j] % 2) == 0 && bits_to_hide[k][j] == 1) {
                image_data[i*3+j]++;
            }
            else if ((image_data[i*3+j] % 2) == 1 && bits_to_hide[k][j] == 0) {
                image_data[i*3+j]--;
            }
        }
        k++;
    }

    // Create the output file
    output = fopen(output_name, "wb");

    // Check if file was created successfully
    if (output == NULL) {
        printf("Error creating file\n");
        exit(1);
    }

    // Write the image data to the output file
    fwrite(image_data, sizeof(char), num_pixels * 3, output);

    // Close the files
    fclose(image);
    fclose(output);

    printf("Message hidden successfully!\n");
    return 0;
}