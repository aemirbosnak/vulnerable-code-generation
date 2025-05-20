//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54
#define MESSAGE_SIZE 256
#define MAX_PLAYERS 10

typedef struct {
    unsigned char header[BMP_HEADER_SIZE];
    int width;
    int height;
} BMPImage;

void readBMPHeader(FILE *fp, BMPImage *img) {
    fread(img->header, sizeof(unsigned char), BMP_HEADER_SIZE, fp);
    img->width = *(int*)&img->header[18];
    img->height = *(int*)&img->header[22];
}

void writeBMPHeader(FILE *fp, BMPImage *img) {
    fwrite(img->header, sizeof(unsigned char), BMP_HEADER_SIZE, fp);
}

void embedMessage(const char *inputFile, const char *outputFile, const char *message) {
    BMPImage img;
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    if (!input || !output) {
        perror("File opening failed");
        return;
    }

    readBMPHeader(input, &img);
    writeBMPHeader(output, &img);
    
    int messageLen = strlen(message);
    if (messageLen > MESSAGE_SIZE) {
        printf("Message is too long!\n");
        fclose(input);
        fclose(output);
        return;
    }

    fseek(input, BMP_HEADER_SIZE, SEEK_SET);
    fseek(output, BMP_HEADER_SIZE, SEEK_SET);

    unsigned char pixel[3];
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fread(pixel, sizeof(unsigned char), 3, input);
            if (i * img.width + j < messageLen) {
                pixel[0] = (pixel[0] & 0xFE) | ((message[i * img.width + j] >> 7) & 0x01);
                pixel[1] = (pixel[1] & 0xFE) | ((message[i * img.width + j] >> 6) & 0x01);
                pixel[2] = (pixel[2] & 0xFE) | ((message[i * img.width + j] >> 5) & 0x01);
            }
            fwrite(pixel, sizeof(unsigned char), 3, output);
        }
    }
    
    fclose(input);
    fclose(output);
    printf("Message embedded successfully!\n");
}

void extractMessage(const char *imageFile) {
    BMPImage img;
    FILE *input = fopen(imageFile, "rb");
    if (!input) {
        perror("File opening failed");
        return;
    }

    readBMPHeader(input, &img);
    
    fseek(input, BMP_HEADER_SIZE, SEEK_SET);
    unsigned char pixel[3];
    char message[MESSAGE_SIZE] = {0};
    
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fread(pixel, sizeof(unsigned char), 3, input);
            if (i * img.width + j < MESSAGE_SIZE) {
                message[i * img.width + j] = ((pixel[0] & 0x01) << 7) |
                                              ((pixel[1] & 0x01) << 6) |
                                              ((pixel[2] & 0x01) << 5);
            }
        }
    }
    
    fclose(input);
    printf("Extracted message: %s\n", message);
}

int main() {
    int playerCount;
    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart and try again.\n");
        return 1;
    }

    for (int i = 0; i < playerCount; i++) {
        printf("\nPlayer %d - Choose an option:\n1. Embed a message\n2. Extract a message\n", i + 1);
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char inputFile[100], outputFile[100], message[MESSAGE_SIZE];
            printf("Enter input BMP file name: ");
            scanf("%s", inputFile);
            printf("Enter output BMP file name: ");
            scanf("%s", outputFile);
            printf("Enter your message (max %d characters): ", MESSAGE_SIZE);
            scanf(" %[^\n]", message);
            embedMessage(inputFile, outputFile, message);
        } else if (choice == 2) {
            char imageFile[100];
            printf("Enter BMP file name to extract message from: ");
            scanf("%s", imageFile);
            extractMessage(imageFile);
        } else {
            printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}