//FormAI DATASET v1.0 Category: Image Steganography ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* The steganography algorithm requires 3 bits per pixel */
#define BITS_PER_PIXEL 3 

#define MAX_SECRET_BYTES ((MAX_IMAGE_BYTES * BITS_PER_PIXEL) / 8)
#define MAX_FILENAME_LENGTH 256

/* The maximum number of bytes that can be hidden in an image */
#define MAX_IMAGE_BYTES 2000 

/* Function to read image data from a binary file */
bool read_image_data(char* filename, unsigned char* image_data, int* image_size) {
    FILE* fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'!", filename);
        return false;
    }

    /* Get the size of the file */
    fseek(fp, 0, SEEK_END);
    *image_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /* Read the data from the file and close the file stream */
    fread(image_data, 1, *image_size, fp);
    fclose(fp);
    return true;
}

/* Function to write image data to a binary file */
bool write_image_data(char* filename, unsigned char* image_data, int image_size) {
    FILE* fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'!", filename);
        return false;
    }

    fwrite(image_data, 1, image_size, fp);
    fclose(fp);
    return true;
}

/* Function to hide secret data in an image */
bool hide_secret_data_in_image(unsigned char* image_data, int image_size, unsigned char* secret_data, int secret_size) {

    /* Check if the secret data can fit in the image */
    if (secret_size > MAX_SECRET_BYTES) {
        printf("Error: Secret data size exceeds maximum capacity of image!");
        return false;
    }

    /* Hide the secret data within the image */
    int data_offset = 0;
    for (int i = 0; i < image_size; i++) {
        if (data_offset < secret_size) {
            /* Store the bits of each byte of the secret data within the least significant bits of the image data */
            for (int bit = 0; bit < BITS_PER_PIXEL; bit++) {
                image_data[i] &= ~(1 << bit);
                image_data[i] |= ((secret_data[data_offset] >> bit) & 1) << bit;
                data_offset++;
            }
        }
        else {
            /* All secret data bits have been stored */
            break;
        }
    }

    return true;
}

/* Function to extract secret data from an image */
bool extract_secret_data_from_image(unsigned char* image_data, int image_size, unsigned char* secret_data, int* secret_size) {

    /* Extract the secret data from the image */
    *secret_size = 0;
    unsigned char current_byte = 0;
    int data_offset = 0;
    for (int i = 0; i < image_size; i++) {
        /* Extract the least significant bits of each image byte to reconstruct the secret data */
        for (int bit = 0; bit < BITS_PER_PIXEL; bit++) {
            current_byte |= ((image_data[i] >> bit) & 1) << bit;
            data_offset++;
            if (data_offset % 8 == 0) {
                /* A full byte of secret data has been extracted */
                secret_data[*secret_size] = current_byte;
                *secret_size += 1;
                current_byte = 0;
                if (*secret_size >= MAX_SECRET_BYTES) {
                    /* Maximum capacity of secret data has been reached */
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    char image_filename[MAX_FILENAME_LENGTH];
    char secret_filename[MAX_FILENAME_LENGTH];

    /* Get the filenames of the image and secret data from the user */
    printf("Enter name of image file to hide data in: ");
    scanf("%s", image_filename);
    printf("Enter name of secret file to hide in image: ");
    scanf("%s", secret_filename);

    /* Read the image data from the file */
    unsigned char* image_data = (unsigned char*) malloc(MAX_IMAGE_BYTES);
    int image_size = 0;
    if (!read_image_data(image_filename, image_data, &image_size)) {
        return 1;
    }

    /* Read the secret data from the file */
    unsigned char* secret_data = (unsigned char*) malloc(MAX_SECRET_BYTES);
    int secret_size = 0;
    FILE* fp;
    fp = fopen(secret_filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'!", secret_filename);
        return 1;
    }
    secret_size = fread(secret_data, 1, MAX_SECRET_BYTES, fp);
    fclose(fp);

    /* Hide the secret data in the image */
    if (!hide_secret_data_in_image(image_data, image_size, secret_data, secret_size)) {
        printf("Error: could not hide secret data in image!");
        return 1;
    }

    /* Write the modified image data to a file */
    if (!write_image_data("hidden_image.bin", image_data, image_size)) {
        printf("Error: could not write modified image data to file!");
        return 1;
    }

    /* Extract the secret data from the modified image data */
    unsigned char* extracted_secret_data = (unsigned char*) malloc(MAX_SECRET_BYTES);
    int extracted_secret_size = 0;
    if (!extract_secret_data_from_image(image_data, image_size, extracted_secret_data, &extracted_secret_size)) {
        printf("Error: could not extract secret data from image!");
        return 1;
    }

    /* Write the extracted secret data to a file */
    fp = fopen("extracted_secret.bin", "wb");
    if (fp == NULL) {
        printf("Error: could not write extracted secret data to file!");
        return 1;
    }
    fwrite(extracted_secret_data, 1, extracted_secret_size, fp);
    fclose(fp);

    printf("Operation successful!\n");
    return 0;
}