//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 256
#define HEIGHT 256
#define IMAGE_SIZE (WIDTH * HEIGHT)

// Function to read the input image file
void read_image(char *filename, unsigned char *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fread(image, sizeof(unsigned char), IMAGE_SIZE, fp);
    fclose(fp);
}

// Function to write the output image file
void write_image(char *filename, unsigned char *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fwrite(image, sizeof(unsigned char), IMAGE_SIZE, fp);
    fclose(fp);
}

// Function to hide the message in the image
void hide_message(unsigned char *image, char *message) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < 3; j++) {
            k = i * 3 + j;
            if (k < IMAGE_SIZE) {
                image[k] = (unsigned char) (image[k] + message[i] - 'A');
            }
        }
    }
}

// Function to extract the message from the image
void extract_message(unsigned char *image, char *message) {
    int i, j, k;
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < 3; j++) {
            k = i * 3 + j;
            if (k < IMAGE_SIZE) {
                message[i] = (char) (image[k] - (unsigned char) ('A') + 'A');
            }
        }
    }
    message[strlen(message)] = '\0';
}

// Function to generate a random key
void generate_key(char *key) {
    int i;
    srand(time(NULL));
    for (i = 0; i < strlen(key); i++) {
        key[i] = (char) rand() % 26 + 'A';
    }
    key[strlen(key)] = '\0';
}

int main() {
    char input_filename[256], output_filename[256], message[256], key[256];
    unsigned char image[IMAGE_SIZE];

    // Read the input image file
    printf("Enter the name of the input image file: ");
    scanf("%s", input_filename);
    read_image(input_filename, image);

    // Read the message to be hidden
    printf("Enter the message to be hidden: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Hide the message in the image
    hide_message(image, message);

    // Save the output image file
    strcpy(output_filename, input_filename);
    strcat(output_filename, "_stego");
    write_image(output_filename, image);

    // Extract the message from the output image file
    strcpy(message, "");
    extract_message(image, message);
    printf("The hidden message is: %s\n", message);

    return 0;
}