//FormAI DATASET v1.0 Category: Image Steganography ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void embed_message(char *image_path, char *msg); // function declaration
void extract_message(char *image_path); // function declaration

int main(int argc, char *argv[]) {
    char image_path[MAX_SIZE];
    char message[MAX_SIZE];

    printf("Enter image path: ");
    scanf("%s", image_path);

    printf("Enter message to embed: ");
    scanf(" %[^\n]s", message);

    embed_message(image_path, message); // call embed function

    printf("Message has been embedded into the image\n");

    extract_message(image_path); // call extract function
}

void embed_message(char *image_path, char *msg) {
    FILE *fp = fopen(image_path, "rb");
    if (!fp) {
        printf("Error opening image file\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char image_data[file_size];
    fread(image_data, file_size, 1, fp);
    fclose(fp);

    int i, j, k = 0;
    int len = strlen(msg);

    for (i = 0; i < len; i++) {
        for (j = 7; j >= 0; j--, k++) {
            unsigned char bit = (msg[i] >> j) & 1;
            if (bit) {
                image_data[k] |= 1;
            } else {
                image_data[k] &= ~1;
            }
        }
    }

    fp = fopen(image_path, "wb");
    if (!fp) {
        printf("Error opening image file\n");
        exit(1);
    }

    fwrite(image_data, file_size, 1, fp);
    fclose(fp);
}

void extract_message(char *image_path) {
    FILE *fp = fopen(image_path, "rb");
    if (!fp) {
        printf("Error opening image file\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    char image_data[file_size];
    fread(image_data, file_size, 1, fp);
    fclose(fp);

    int i, j, k, l = 0;
    char extracted_message[MAX_SIZE] = {0};

    for (k = 0; k < file_size; k++) {
        for (j = 7; j >= 0; j--) {
            unsigned char bit = (image_data[k] >> j) & 1;
            if (bit) {
                extracted_message[l] |= 1;
            }
            l++;
        }
    }

    printf("Extracted Message: %s\n", extracted_message);
}