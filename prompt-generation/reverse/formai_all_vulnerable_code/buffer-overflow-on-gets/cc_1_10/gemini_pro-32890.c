//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void hide_message(char *image, char *message) {
    int i = 0, j = 0;
    while (message[i] != '\0') {
        image[j] = (image[j] & 0xFE) | ((message[i] >> 7) & 0x01);
        image[j + 1] = (image[j + 1] & 0xFE) | ((message[i] >> 6) & 0x01);
        image[j + 2] = (image[j + 2] & 0xFE) | ((message[i] >> 5) & 0x01);
        image[j + 3] = (image[j + 3] & 0xFE) | ((message[i] >> 4) & 0x01);
        image[j + 4] = (image[j + 4] & 0xFE) | ((message[i] >> 3) & 0x01);
        image[j + 5] = (image[j + 5] & 0xFE) | ((message[i] >> 2) & 0x01);
        image[j + 6] = (image[j + 6] & 0xFE) | ((message[i] >> 1) & 0x01);
        image[j + 7] = (image[j + 7] & 0xFE) | (message[i] & 0x01);
        i++;
        j += 8;
    }
}

void reveal_message(char *image) {
    int i = 0, j = 0;
    while (1) {
        char c = (image[j] & 0x01) << 7 | (image[j + 1] & 0x01) << 6 |
                (image[j + 2] & 0x01) << 5 | (image[j + 3] & 0x01) << 4 |
                (image[j + 4] & 0x01) << 3 | (image[j + 5] & 0x01) << 2 |
                (image[j + 6] & 0x01) << 1 | (image[j + 7] & 0x01);
        if (c == '\0') {
            break;
        }
        putchar(c);
        j += 8;
    }
}

int main() {
    char image[10000], message[1000];
    printf("Enter the message to hide: ");
    gets(message);
    printf("Enter the image file name: ");
    gets(image);
    FILE *fp = fopen(image, "rb+");
    if (fp == NULL) {
        printf("Error opening the image file!");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(image, 1, size, fp);
    hide_message(image, message);
    fseek(fp, 0, SEEK_SET);
    fwrite(image, 1, size, fp);
    fclose(fp);
    printf("Message successfully hidden in the image file!\n");
    printf("Extracting the message from the image...\n");
    fp = fopen(image, "rb");
    if (fp == NULL) {
        printf("Error opening the image file!");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(image, 1, size, fp);
    fclose(fp);
    reveal_message(image);
    printf("\nMessage successfully extracted from the image file!\n");
    return 0;
}