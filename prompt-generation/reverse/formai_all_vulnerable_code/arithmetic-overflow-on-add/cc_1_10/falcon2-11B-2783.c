//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 8
#define STRING_SIZE 0x100

typedef unsigned char BYTE;

void encode(char* message, char* cover) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            BYTE temp = cover[j];
            char ch = message[i];
            cover[j] = ch ^ temp;
        }
    }
}

void decode(char* cover, char* message) {
    int i, j;
    for (i = 0; i < STRING_SIZE; i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            BYTE temp = cover[j];
            char ch = message[i];
            cover[j] = ch ^ temp;
        }
    }
}

int main() {
    char cover[BLOCK_SIZE];
    char message[BLOCK_SIZE];

    printf("Enter the cover image file name: ");
    scanf("%s", cover);

    FILE *fp = fopen(cover, "rb");
    if (fp == NULL) {
        printf("Error opening cover image file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size + 1);
    fread(data, 1, size, fp);
    fclose(fp);

    for (int i = 0; i < size; i++) {
        if (data[i]!= 0) {
            message[i % BLOCK_SIZE] = data[i];
        }
    }

    printf("Enter the secret message: ");
    scanf("%s", message);

    encode(message, cover);

    fp = fopen(cover, "wb");
    fwrite(cover, 1, STRING_SIZE, fp);
    fclose(fp);

    printf("Steganography complete.\n");

    fp = fopen(cover, "rb");
    if (fp == NULL) {
        printf("Error opening cover image file.\n");
        return 1;
    }

    decode(cover, message);

    printf("Secret message recovered: %s\n", message);

    return 0;
}