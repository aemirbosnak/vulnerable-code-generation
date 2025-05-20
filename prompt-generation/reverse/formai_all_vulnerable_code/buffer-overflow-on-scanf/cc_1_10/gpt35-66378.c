//FormAI DATASET v1.0 Category: Image Steganography ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

// Utility function to convert decimal to binary
int* decimalToBinary(int n) {
    int *binary = (int *) malloc(8 * sizeof(int));
    int i, j, k;
    for (i = 7; i >= 0; i--) {
        k = n >> i;
        if (k & 1) {
            binary[7 - i] = 1;
        } else {
            binary[7 - i] = 0;
        }
    }
    return binary;
}

// Utility function to convert binary to decimal
int binaryToDecimal(int *binary) {
    int decimal = 0;
    int i, j, k;
    for (i = 0; i < 8; i++) {
        k = binary[7 - i] * (1 << i);
        decimal += k;
    }
    return decimal;
}

// Utility function to extract LSB from a decimal number
int extractLSB(int n) {
    return n & 1;
}

// Utility function to set LSB in a decimal number
int setLSB(int n, int bit) {
    if (bit == 0) {
        return (n & ~1);
    } else {
        return (n | 1);
    }
}

int main() {
    FILE *image_file, *secret_file, *stego_file;
    char image_path[100], secret_path[100], stego_path[100];
    printf("Enter image file path (with extension): ");
    scanf("%s", image_path);
    printf("Enter secret file path (with extension): ");
    scanf("%s", secret_path);
    printf("Enter stego file path to be created (with extension): ");
    scanf("%s", stego_path);

    image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Could not read image file\n");
        exit(0);
    }

    secret_file = fopen(secret_path, "rb");
    if (secret_file == NULL) {
        printf("Could not read secret file\n");
        exit(0);
    }

    stego_file = fopen(stego_path, "wb");
    if (stego_file == NULL) {
        printf("Could not create stego file\n");
        exit(0);
    }

    int image_size;
    unsigned char *image_data;
    int secret_size;
    unsigned char *secret_data;
    unsigned char *stego_data;
    int i, j, k;

    // Read image data
    fseek(image_file, 0L, SEEK_END);
    image_size = ftell(image_file);
    fseek(image_file, 0L, SEEK_SET);
    image_data = (unsigned char *) malloc(image_size * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), image_size, image_file);
    fclose(image_file);

    // Read secret data
    fseek(secret_file, 0L, SEEK_END);
    secret_size = ftell(secret_file);
    if (secret_size > (image_size / 8)) {
        printf("Cannot hide secret in image\n");
        exit(0);
    }
    fseek(secret_file, 0L, SEEK_SET);
    secret_data = (unsigned char *) malloc(secret_size * sizeof(unsigned char));
    fread(secret_data, sizeof(unsigned char), secret_size, secret_file);
    fclose(secret_file);

    // Allocate memory for stego data
    stego_data = (unsigned char *) malloc(image_size * sizeof(unsigned char));

    // Copy image header to stego data
    for (i = 0; i < 54; i++) {
        stego_data[i] = image_data[i];
    }

    // Embed secret in image data
    int index = 54; // Start from the 55th byte of the image data
    int *binary;
    for (i = 0; i < secret_size; i++) {
        binary = decimalToBinary(secret_data[i]);
        for (j = 0; j < 8; j++) {
            k = extractLSB(image_data[index]);
            if (k == binary[j]) {
                stego_data[index] = image_data[index];
            } else {
                if (k == 0 && binary[j] == 1) {
                    stego_data[index] = setLSB(image_data[index], 1);
                } else if (k == 1 && binary[j] == 0) {
                    stego_data[index] = setLSB(image_data[index], 0);
                }
            }
            index++;
        }
        free(binary);
    }

    // Copy rest of image data to stego data
    for (i = index; i < image_size; i++) {
        stego_data[i] = image_data[i];
    }

    // Save stego data to file
    fwrite(stego_data, sizeof(unsigned char), image_size, stego_file);
    fclose(stego_file);
    printf("Stego file created\n");

    free(image_data);
    free(secret_data);
    free(stego_data);

    return 0;
}