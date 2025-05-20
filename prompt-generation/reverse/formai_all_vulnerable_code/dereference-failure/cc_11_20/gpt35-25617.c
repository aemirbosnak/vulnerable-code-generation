//FormAI DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// define constants
#define MAX_MESSAGE_SIZE 100
#define MAX_PIXEL_VALUE 255
#define FILE_HEADER_SIZE 54
#define MAX_ENCRYPTION_KEY 255

int main(int argc, char const *argv[]) {

    char *image_path;              // path to input image
    char *message;                 // secret message
    char *encrypted_message = "";  // encrypted secret message
    char *decrypted_message = "";  // decrypted secret message
    int key;                       // encryption key
    int message_size;              // size of secret message
    FILE *input_file;              // input image file pointer
    FILE *output_file;             // output image file pointer

    // check input arguments
    if (argc != 4) {
        printf("Invalid input arguments. Please provide input image path, secret message and encryption key.\n");
        return 1;
    }

    // initialize variables
    image_path = argv[1];
    message = argv[2];
    key = atoi(argv[3]);
    message_size = strlen(message);

    // open input image file
    input_file = fopen(image_path, "rb");
    if (input_file == NULL) {
        printf("Failed to open input image file.\n");
        return 1;
    }

    // read input image file header
    char file_header[FILE_HEADER_SIZE];
    fread(file_header, 1, FILE_HEADER_SIZE, input_file);

    // calculate input image dimensions
    int width = *(int*)&file_header[18];
    int height = *(int*)&file_header[22];

    // calculate input image pixel size
    int pixel_size = *(int*)&file_header[28] / 8;

    // calculate input image data size
    int data_size = width * height * pixel_size;

    // allocate memory to store input image data
    char *image_data = (char*) malloc(data_size);
    if (image_data == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // read input image data
    fread(image_data, 1, data_size, input_file);

    // close input image file
    fclose(input_file);

    // embed secret message in input image
    int i, j, k;
    for (i = 0; i < message_size; i++) {
        char letter = *(message + i);
        char binary_letter[8] = "";
        for (j = 0; j < 8; j++) {
            char bit = (letter >> (7 - j)) & 0x01;
            int pixel_index = (i * 8 + j) * pixel_size;
            for (k = 0; k < pixel_size; k++) {
                if (bit == 1) {
                    *(image_data + pixel_index + k) = *(image_data + pixel_index + k) | 0x01;
                } else {
                    *(image_data + pixel_index + k) = *(image_data + pixel_index + k) & 0xFE;
                }
            }
        }
    }

    // encrypt secret message using XOR cipher
    for (i = 0; i < message_size; i++) {
        char letter = *(message + i) ^ key;
        *(encrypted_message + i) = letter;
    }

    // decrypt secret message using XOR cipher
    for (i = 0; i < message_size; i++) {
        char letter = *(encrypted_message + i) ^ key;
        *(decrypted_message + i) = letter;
    }

    // write output image file
    output_file = fopen("output.bmp", "wb");
    if (output_file == NULL) {
        printf("Failed to open output image file.\n");
        return 1;
    }

    // write output image file header
    fwrite(file_header, 1, FILE_HEADER_SIZE, output_file);

    // write output image data
    fwrite(image_data, 1, data_size, output_file);

    // close output image file
    fclose(output_file);

    // free memory used by input image data
    free(image_data);

    // print results
    printf("Secret message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}