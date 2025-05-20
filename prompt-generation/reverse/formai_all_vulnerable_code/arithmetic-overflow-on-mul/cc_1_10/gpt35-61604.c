//FormAI DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to convert character into binary string of given length
void char_to_binary(char c, char *binary, int length) {
    for(int i = 0; i < length; i++) {
        binary[length - 1 - i] = (c & (1 << i)) ? '1' : '0';
    }
    binary[length] = '\0';
}

// Function to convert binary string into character
char binary_to_char(char *binary, int length) {
    char c = 0;
    for(int i = 0; i < length; i++) {
        c += (binary[length - 1 - i] == '1') ? pow(2, i) : 0;
    }
    return c;
}

// Function to embed data into the least significant bit of pixel value
void embed_data(unsigned char *pixel, char *binary) {
    for(int i = 0; i < strlen(binary); i++) {
        if(binary[i] == '1') {
            if(pixel[i] % 2 == 0) {
                pixel[i]++;
            }
        } else {
            if(pixel[i] % 2 == 1) {
                pixel[i]--;
            }
        }
    }
}

// Function to extract data from the least significant bit of pixel value
void extract_data(unsigned char pixel, char *binary) {
    for(int i = 0; i < 8; i++) {
        binary[7 - i] = (pixel & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: steganography <input_image> <output_image> <secret_message>\n");
        exit(1);
    }

    char *input_image = argv[1];
    char *output_image = argv[2];
    char *secret_message = argv[3];

    // Open input BMP file
    FILE *input_fp = fopen(input_image, "rb");
    if(input_fp == NULL) {
        printf("Error: Unable to open input image file\n");
        exit(1);
    }

    // Read BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_fp);

    // Get width, height and image data offset information from BMP header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int data_offset = *(int*)&header[10];

    // Calculate padding size
    int padding_size = (4 - (width * 3) % 4) % 4;

    // Calculate total image size
    int image_size = (width * 3 + padding_size) * height;

    // Allocate memory for input image data
    unsigned char *input_data = (unsigned char*)malloc(sizeof(unsigned char) * image_size);

    // Read input image data
    fseek(input_fp, data_offset, SEEK_SET);
    fread(input_data, sizeof(unsigned char), image_size, input_fp);

    // Close input BMP file
    fclose(input_fp);

    // Open output BMP file in write binary mode
    FILE *output_fp = fopen(output_image, "wb");
    if(output_fp == NULL) {
        printf("Error: Unable to open output image file\n");
        exit(1);
    }

    // Write input BMP header to output BMP file
    fwrite(header, sizeof(unsigned char), 54, output_fp);

    // Embed secret message into input image data
    int message_length = strlen(secret_message);
    int message_bit_length = message_length * 8;
    char message_bits[message_bit_length + 1];
    for(int i = 0; i < message_length; i++) {
        char_to_binary(secret_message[i], message_bits + i * 8, 8);
    }

    int pixel_index = 0;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            unsigned char *pixel = input_data + (y * (width * 3 + padding_size)) + (x * 3);
            if(pixel_index < message_bit_length) {
                embed_data(pixel, message_bits + pixel_index);
                pixel_index += 8;
            }
        }
    }

    // Write embedded image data to output BMP file
    fwrite(input_data, sizeof(unsigned char), image_size, output_fp);

    // Free input image data memory
    free(input_data);

    // Close output BMP file
    fclose(output_fp);

    // Open embedded BMP file
    FILE *embedded_fp = fopen(output_image, "rb");
    if(embedded_fp == NULL) {
        printf("Error: Unable to open embedded image file\n");
        exit(1);
    }

    // Read embedded BMP header
    unsigned char embedded_header[54];
    fread(embedded_header, sizeof(unsigned char), 54, embedded_fp);

    // Get embedded image data offset information from BMP header
    int embedded_data_offset = *(int*)&embedded_header[10];

    // Calculate embedded image data size
    int embedded_image_size = (width * 3 + padding_size) * height;

    // Allocate memory for embedded image data
    unsigned char *embedded_data = (unsigned char*)malloc(sizeof(unsigned char) * embedded_image_size);

    // Read embedded image data
    fseek(embedded_fp, embedded_data_offset, SEEK_SET);
    fread(embedded_data, sizeof(unsigned char), embedded_image_size, embedded_fp);

    // Close embedded BMP file
    fclose(embedded_fp);

    // Extract secret message from embedded image data
    char extracted_message[message_length + 1];
    for(int i = 0; i < message_length; i++) {
        char message_bits[9];
        extract_data(*(embedded_data + i * 8), message_bits);
        extracted_message[i] = binary_to_char(message_bits, 8);
    }
    extracted_message[message_length] = '\0';

    // Print extracted secret message
    printf("Extracted message: %s\n", extracted_message);

    // Free input image data memory
    free(embedded_data);

    return 0;
}