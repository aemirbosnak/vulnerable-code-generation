//FormAI DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

#define MAX_IMAGE_SIZE 1000000
#define MAX_MESSAGE_SIZE 1000

int encode(char *imagePath, char *messagePath, char *newImagePath);
char *loadData(FILE *input);
void writeData(char *data, FILE *output);
void hideMessage(char *image, char *message, int imageSize, int messageSize);
int getMessageSize(FILE *message);

struct Image {
    unsigned char data[MAX_IMAGE_SIZE];
    int size;
};

int main() {
    char imagePath[100], messagePath[100], newImagePath[100];
    printf("Enter image path : ");
    scanf("%s", imagePath);
    printf("Enter message path : ");
    scanf("%s", messagePath);
    printf("Enter new image path : ");
    scanf("%s", newImagePath);
    int success = encode(imagePath, messagePath, newImagePath);
    if(success == 1) {
        printf("Message successfully encoded!\n");
    } else {
        printf("Failed to encode message!\n");
    }
    return 0;
}

int encode(char *imagePath, char *messagePath, char *newImagePath) {
    FILE *imageFile, *messageFile, *newImageFile;
    imageFile = fopen(imagePath, "rb");
    messageFile = fopen(messagePath, "rb");
    newImageFile = fopen(newImagePath, "wb");
    if(imageFile == NULL || messageFile == NULL || newImageFile == NULL) {
        printf("Error opening files!\n");
        return 0;
    }
    char *imageData = loadData(imageFile);
    char *messageData = loadData(messageFile);
    int imageSize = fread(imageData, 1, MAX_IMAGE_SIZE, imageFile);
    int messageSize = getMessageSize(messageFile);
    if(messageSize > MAX_MESSAGE_SIZE) {
        printf("Message is too large to encode in image!\n");
        return 0;
    }
    hideMessage(imageData, messageData, imageSize, messageSize);
    writeData(imageData, newImageFile);
    fclose(imageFile);
    fclose(messageFile);
    fclose(newImageFile);
    return 1;
}

char *loadData(FILE *input) {
    fseek(input, 0, SEEK_END);
    int size = ftell(input);
    fseek(input, 0, SEEK_SET);
    char *data = malloc(size * sizeof(char));
    if(!data) {
        printf("Error allocating memory!\n");
        exit(1);
    }
    fread(data, 1, size, input);
    return data;
}

void writeData(char *data, FILE *output) {
    int size = fwrite(data, 1, MAX_IMAGE_SIZE, output);
    if(size != MAX_IMAGE_SIZE) {
        printf("Error writing data to file!\n");
    }
}

int getMessageSize(FILE *message) {
    fseek(message, 0, SEEK_END);
    int size = ftell(message);
    fseek(message, 0, SEEK_SET);
    return size;
}

void hideMessage(char *image, char *message, int imageSize, int messageSize) {
    int imageIndex = 0;
    for(int i = 0; i < messageSize; i++) {
        char messageByte = message[i];
        for(int j = 0; j < 8; j++) {
            char bit = (messageByte >> j) & 1;
            if(imageIndex >= imageSize) {
                printf("Image is too small to encode full message!\n");
                exit(1);
            }
            image[imageIndex] = (image[imageIndex] & 0xFE) | bit;
            imageIndex++;
        }
    }
    if(imageIndex >= imageSize) {
        printf("Image is too small to encode full message!\n");
        exit(1);
    }
    image[imageIndex] = (image[imageIndex] & 0xFE) | 1;
}