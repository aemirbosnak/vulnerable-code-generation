//FormAI DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 256
#define IMAGE_SIZE 1000000
#define SECRET_SIZE 10000

void hide_secret(char* image_path, char* secret_path, char* output_path) {
    unsigned char image[IMAGE_SIZE], secret[SECRET_SIZE], output[IMAGE_SIZE];
    int image_size, secret_size, output_size, i, j, k;
    FILE *image_file, *secret_file, *output_file;

    // Open the image file
    image_file = fopen(image_path, "rb");
    if (!image_file) {
        fprintf(stderr, "Error opening image file: %s\n", image_path);
        exit(1);
    }

    // Read the image into a buffer
    image_size = fread(image, 1, IMAGE_SIZE, image_file);
    fclose(image_file);

    // Open the secret file
    secret_file = fopen(secret_path, "rb");
    if (!secret_file) {
        fprintf(stderr, "Error opening secret file: %s\n", secret_path);
        exit(1);
    }

    // Read the secret into a buffer
    secret_size = fread(secret, 1, SECRET_SIZE, secret_file);
    fclose(secret_file);

    // Check if the secret can be embedded in the image
    if (secret_size * 8 > image_size) {
        fprintf(stderr, "Error: secret too big to be embedded in image\n");
        exit(1);
    }

    // Embed the secret in the image using LSB steganography
    output_size = image_size;
    memcpy(output, image, image_size);
    for (i = 0, k = 0; i < secret_size; i++) {
        for (j = 7; j >= 0; j--, k++) {
            // Set bit k of the output to bit j of the secret
            output[k] = (image[k] & 0xFE) | ((secret[i] >> j) & 1);
        }
    }

    // Open the output file
    output_file = fopen(output_path, "wb");
    if (!output_file) {
        fprintf(stderr, "Error opening output file: %s\n", output_path);
        exit(1);
    }

    // Write the output to the file
    fwrite(output, 1, output_size, output_file);
    fclose(output_file);

    printf("Secret embedded in image successfully\n");
}

void extract_secret(char* image_path, char* output_path) {
    unsigned char image[IMAGE_SIZE], output[SECRET_SIZE];
    int image_size, output_size, i, j, k;
    FILE *image_file, *output_file;

    // Open the image file
    image_file = fopen(image_path, "rb");
    if (!image_file) {
        fprintf(stderr, "Error opening image file: %s\n", image_path);
        exit(1);
    }

    // Read the image into a buffer
    image_size = fread(image, 1, IMAGE_SIZE, image_file);
    fclose(image_file);

    // Extract the secret from the image using LSB steganography
    output_size = image_size / 8;
    for (i = 0, k = 0; i < output_size; i++) {
        output[i] = 0;
        for (j = 7; j >= 0; j--, k++) {
            // Set bit j of the output to bit k of the image
            output[i] |= ((image[k] & 1) << j);
        }
    }

    // Open the output file
    output_file = fopen(output_path, "wb");
    if (!output_file) {
        fprintf(stderr, "Error opening output file: %s\n", output_path);
        exit(1);
    }

    // Write the output to the file
    fwrite(output, 1, output_size, output_file);
    fclose(output_file);

    printf("Secret extracted from image successfully\n");
}

int main() {
    char image_path[FILE_NAME_SIZE], secret_path[FILE_NAME_SIZE], output_path[FILE_NAME_SIZE];
    int option;

    while (1) {
        printf("1. Hide secret in image\n");
        printf("2. Extract secret from image\n");
        printf("3. Quit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter path to image: ");
                scanf("%s", image_path);
                printf("Enter path to secret file: ");
                scanf("%s", secret_path);
                printf("Enter output path: ");
                scanf("%s", output_path);
                hide_secret(image_path, secret_path, output_path);
                break;
            case 2:
                printf("Enter path to image: ");
                scanf("%s", image_path);
                printf("Enter output path: ");
                scanf("%s", output_path);
                extract_secret(image_path, output_path);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, try again\n");
        }
    }

    return 0;
}