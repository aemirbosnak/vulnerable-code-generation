//FormAI DATASET v1.0 Category: Image Steganography ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1000000
#define HEADER_SIZE 54

int main() {

    char image_file_path[100];
    char message_file_path[100];
    char stego_file_path[100];

    printf("Enter the name of the image file (with extension): ");
    scanf("%s", image_file_path);

    printf("Enter the name of the message file (with extension): ");
    scanf("%s", message_file_path);

    printf("Enter the name of the stego file (with extension): ");
    scanf("%s", stego_file_path);

    FILE *image_file = fopen(image_file_path, "rb");
    FILE *message_file = fopen(message_file_path, "r");
    FILE *stego_file = fopen(stego_file_path, "wb");

    if (!image_file) {
        printf("Unable to open image file!");
        return 1;
    }

    if (!message_file) {
        printf("Unable to open message file!");
        return 1;
    }

    if (!stego_file) {
        printf("Unable to create stego file!");
        return 1;
    }

    char header[HEADER_SIZE];
    fread(header, sizeof(char), HEADER_SIZE, image_file);
    fwrite(header, sizeof(char), HEADER_SIZE, stego_file);

    int file_size;
    fread(&file_size, sizeof(int), 1, image_file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Message file too large to be hidden in the image!");
        return 1;
    }

    char *message = (char*) malloc(file_size);
    fread(message, sizeof(char), file_size, message_file);

    int i, j, k;
    char byte, mask;

    for (i = 0, j = 0, k = 0; k < file_size; i += 3, j++, k++) {
        byte = message[k];
        mask = 0x80;

        while (mask) {
            if (byte & mask) {
                header[i+2] |= 0x01;
            } else {
                header[i+2] &= 0xFE;
            }

            mask >>= 1;

            if (k < file_size) {
                byte = message[k];
            } else {
                byte = 0;
            }
        }
    }

    fwrite(header, sizeof(char), HEADER_SIZE, stego_file);

    int byte_count;
    char buffer[1024];

    while ((byte_count = fread(buffer, sizeof(char), 1024, image_file)) > 0){
        fwrite(buffer, sizeof(char), byte_count, stego_file);
    }

    free(message);

    fclose(image_file);
    fclose(message_file);
    fclose(stego_file);

    printf("Stego file created successfully!");

    return 0;
}