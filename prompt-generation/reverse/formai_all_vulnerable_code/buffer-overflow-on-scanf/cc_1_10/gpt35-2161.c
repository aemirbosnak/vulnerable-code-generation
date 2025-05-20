//FormAI DATASET v1.0 Category: Image Steganography ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_TEXT_SIZE 1000

// Function to convert decimal to binary
void decimal_to_binary(uint8_t dec, char* bin) {
    int index = 0;
    while (dec > 0) {
        bin[index++] = (dec % 2) + '0';
        dec = dec / 2;
    }
    while (index < 8) {
        bin[index++] = '0';
    }
    bin[index] = '\0';
}

// Function to convert binary to decimal
uint8_t binary_to_decimal(char* bin) {
    int len = strlen(bin);
    int decimal = 0;
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        if (bin[i] == '1') {
            decimal += (1 << j);
        }
    }
    return (uint8_t) decimal;
}

int main() {

    // Read text to hide
    char text[MAX_TEXT_SIZE];
    printf("Enter the text to hide: ");
    fgets(text, MAX_TEXT_SIZE, stdin);

    // Read image file
    char image_file_path[100];
    printf("Enter the image file path: ");
    scanf("%s", image_file_path);

    // Open image file
    FILE* fp = fopen(image_file_path, "rb+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);
    }

    // Skip past header info
    fseek(fp, 54, SEEK_SET);

    // Loop through each char in text
    int text_len = strlen(text);
    for (int i = 0; i < text_len; i++) {

        // Read current pixel
        uint8_t pixel[3];
        fread(pixel, sizeof(uint8_t), 3, fp);

        // Convert current char to binary
        char binary_text[9];
        decimal_to_binary(text[i], binary_text);

        // Modify pixel values to hide binary data
        for (int j = 0; j < 3; j++) {
            char binary_pixel[9];
            decimal_to_binary(pixel[j], binary_pixel);

            // Replace least significant bit of pixel with bit from binary text
            binary_pixel[7] = binary_text[j];

            // Convert binary back to decimal
            pixel[j] = binary_to_decimal(binary_pixel);
        }

        // Write modified pixel back to file
        fseek(fp, -3, SEEK_CUR);
        fwrite(pixel, sizeof(uint8_t), 3, fp);
    }

    // Close file
    fclose(fp);

    printf("Text hidden successfully in image!\n");

    return 0;
}