//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME 1000
#define MAX_SECRET_MSG 1000
#define MAX_SIZE 100000

// function to convert decimal to binary
char* decimalToBinary(int decimal) {
    char* binary = (char*)malloc(9);
    int i;
    for (i = 7; i >= 0; i--) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[8] = '\0';
    return binary;
}

// function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0, i;
    for (i = 0; i < 8; i++) {
        decimal = 2 * decimal + binary[i] - '0';
    }
    return decimal;
}

// function to hide a secret message in an image
void hideSecretMessage(char* imageFileName, char* secretMessage) {
    char* newImageFileName = (char*)malloc(MAX_FILE_NAME);
    strcpy(newImageFileName, "hidden_");
    strcat(newImageFileName, imageFileName);
    FILE* imageFile = fopen(imageFileName, "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open file '%s' for reading\n", imageFileName);
        exit(1);
    }
    FILE* newImageFile = fopen(newImageFileName, "wb");
    if (newImageFile == NULL) {
        printf("Error: Could not open file '%s' for writing\n", newImageFileName);
        exit(1);
    }
    char* secretMessageBinary = (char*)malloc(MAX_SECRET_MSG * 8);
    int i, j, secretMsgLength = strlen(secretMessage);
    for (i = 0, j = 0; i < secretMsgLength; i++) {
        if (!isalnum(secretMessage[i])) continue;
        char* binary = decimalToBinary(secretMessage[i]);
        strcat(secretMessageBinary, binary);
    }
    int secretMsgBinaryLen = strlen(secretMessageBinary);
    char* imageBytes = (char*)malloc(MAX_SIZE);
    int bytesRead = fread(imageBytes, 1, MAX_SIZE, imageFile);
    if (bytesRead <= 0) {
        printf("Error: Could not read image\n");
        exit(1);
    }
    int imageIndex = 0, secretMsgIndex = 0;
    while (imageIndex < bytesRead && secretMsgIndex < secretMsgBinaryLen) {
        if (imageIndex + 3 < bytesRead) {
            for (i = 0; i < 3; i++) {
                char c = imageBytes[imageIndex];
                char* binary = decimalToBinary(c);
                binary[7] = secretMessageBinary[secretMsgIndex++];
                c = binaryToDecimal(binary);
                fprintf(newImageFile, "%c", c);
                imageIndex++;
            }
        } else {
            char c = imageBytes[imageIndex++];
            char* binary = decimalToBinary(c);
            binary[7] = secretMessageBinary[secretMsgIndex++];
            c = binaryToDecimal(binary);
            fprintf(newImageFile, "%c", c);
        }
    }
    while (imageIndex < bytesRead) {
        fprintf(newImageFile, "%c", imageBytes[imageIndex++]);
    }
    printf("Secret message hidden successfully in '%s'\n", newImageFileName);
    fclose(imageFile);
    fclose(newImageFile);
}

// function to extract a secret message from an image
void extractSecretMessage(char* imageFileName) {
    FILE* imageFile = fopen(imageFileName, "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open file '%s' for reading\n", imageFileName);
        exit(1);
    }
    char* secretMessageBinary = (char*)malloc(MAX_SECRET_MSG * 8);
    char* imageBytes = (char*)malloc(MAX_SIZE);
    int bytesRead = fread(imageBytes, 1, MAX_SIZE, imageFile);
    int i;
    for (i = 0; i < bytesRead; i += 3) {
        if (i + 3 <= bytesRead) {
            char c1 = imageBytes[i];
            char c2 = imageBytes[i + 1];
            char c3 = imageBytes[i + 2];
            char* binary1 = decimalToBinary(c1);
            char* binary2 = decimalToBinary(c2);
            char* binary3 = decimalToBinary(c3);
            secretMessageBinary[strlen(secretMessageBinary)] = binary1[7];
            secretMessageBinary[strlen(secretMessageBinary)] = binary2[7];
            secretMessageBinary[strlen(secretMessageBinary)] = binary3[7];
        } else {
            char c = imageBytes[i];
            char* binary = decimalToBinary(c);
            secretMessageBinary[strlen(secretMessageBinary)] = binary[7];
        }
    }
    printf("Extracted secret message: ");
    for (i = 0; i < strlen(secretMessageBinary); i += 8) {
        char* binary = (char*)malloc(9);
        strncpy(binary, &secretMessageBinary[i], 8);
        binary[8] = '\0';
        int decimal = binaryToDecimal(binary);
        char c = (char)decimal;
        printf("%c", c);
    }
    printf("\n");
    fclose(imageFile);
}

int main() {
    int choice;
    char* imageFileName = (char*)malloc(MAX_FILE_NAME);
    char* secretMessage = (char*)malloc(MAX_SECRET_MSG);
    while (1) {
        printf("\n1. Hide secret message in an image\n");
        printf("2. Extract secret message from an image\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter name of image file: ");
                scanf("%s", imageFileName);
                printf("Enter secret message: ");
                scanf(" %[^\n]", secretMessage);
                hideSecretMessage(imageFileName, secretMessage);
                break;
            case 2:
                printf("\nEnter name of image file: ");
                scanf("%s", imageFileName);
                extractSecretMessage(imageFileName);
                break;
            case 3:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    }
    return 0;
}