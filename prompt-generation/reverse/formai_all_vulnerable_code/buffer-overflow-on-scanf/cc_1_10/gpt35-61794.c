//FormAI DATASET v1.0 Category: Image Steganography ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 50
#define FILE_EXTENSION_SIZE 10
#define MESSAGE_SIZE 50
#define BYTE_SIZE 8

// Function to convert decimal to binary
void decToBinary(int num, int binaryArr[])
{
    for (int i = BYTE_SIZE - 1; i >= 0; i--) {
        binaryArr[i] = num % 2;
        num = num / 2;
    }
}

// Function to convert binary to decimal
int binaryToDec(int binaryArr[])
{
    int num = 0;

    for (int i = BYTE_SIZE - 1; i >= 0; i--) {
        num = num + (binaryArr[i] * (1 << (BYTE_SIZE - i - 1)));
    }

    return num;
}

// Function to hide the message in the image
void hideMessageInImage(char* imageFileName, char* message)
{
    // Open the image file in binary mode
    FILE* fp = fopen(imageFileName, "rb+");

    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return;
    }

    // Move the file pointer to the end of the file
    fseek(fp, 0, SEEK_END);

    // Calculate the total number of bytes in the image file
    int fileSize = ftell(fp);

    // Move the file pointer to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    // Read the image file header
    unsigned char header[54] = { 0 };
    fread(header, sizeof(unsigned char), 54, fp);

    // Calculate the size of the image data
    int imageDataSize = fileSize - 54;

    // Calculate the size of the message
    int messageSize = strlen(message);

    if (messageSize > imageDataSize) {
        printf("Error: The message is too big to fit in the image.\n");
        fclose(fp);
        return;
    }

    // Convert the message to binary
    int binaryMessage[BYTE_SIZE * MESSAGE_SIZE] = { 0 };

    for (int i = 0; i < messageSize; i++) {
        decToBinary(message[i], &binaryMessage[i * BYTE_SIZE]);
    }

    // Loop through the image data
    unsigned char pixel[3] = { 0 };
    int binaryPixel[BYTE_SIZE * 3] = { 0 };
    int binaryMessageIndex = 0;

    for (int i = 0; i < imageDataSize; i += 3) {
        // Read a pixel from the image data
        fread(pixel, sizeof(unsigned char), 3, fp);

        // Convert the pixel to binary
        decToBinary(pixel[0], &binaryPixel[0]);
        decToBinary(pixel[1], &binaryPixel[BYTE_SIZE]);
        decToBinary(pixel[2], &binaryPixel[2 * BYTE_SIZE]);

        // Hide the message in the pixel
        for (int j = 0; j < BYTE_SIZE; j++) {
            if (binaryMessageIndex < messageSize * BYTE_SIZE) {
                binaryPixel[j] = (binaryPixel[j] & 0xFE) | binaryMessage[binaryMessageIndex];
                binaryMessageIndex++;
            } else {
                break;
            }
        }

        // Convert the binary pixel back to decimal
        pixel[0] = (unsigned char)binaryToDec(&binaryPixel[0]);
        pixel[1] = (unsigned char)binaryToDec(&binaryPixel[BYTE_SIZE]);
        pixel[2] = (unsigned char)binaryToDec(&binaryPixel[2 * BYTE_SIZE]);

        // Write the pixel back to the image data
        fseek(fp, i, SEEK_SET);
        fwrite(pixel, sizeof(unsigned char), 3, fp);
    }

    // Close the file
    fclose(fp);

    printf("Message hidden successfully.\n");
}

// Function to extract the message from the image
void extractMessageFromImage(char* imageFileName)
{
    // Open the image file in binary mode
    FILE* fp = fopen(imageFileName, "rb");

    if (fp == NULL) {
        printf("Error: Unable to open the file.\n");
        return;
    }

    // Move the file pointer to the end of the file
    fseek(fp, 0, SEEK_END);

    // Calculate the total number of bytes in the image file
    int fileSize = ftell(fp);

    // Move the file pointer to the beginning of the file
    fseek(fp, 0, SEEK_SET);

    // Read the image file header
    unsigned char header[54] = { 0 };
    fread(header, sizeof(unsigned char), 54, fp);

    // Calculate the size of the image data
    int imageDataSize = fileSize - 54;

    // Loop through the image data
    unsigned char pixel[3] = { 0 };
    int binaryPixel[BYTE_SIZE * 3] = { 0 };
    int binaryMessage[BYTE_SIZE * MESSAGE_SIZE] = { 0 };
    int binaryMessageIndex = 0;
    int messageSize = 0;

    for (int i = 0; i < imageDataSize; i += 3) {
        // Read a pixel from the image data
        fread(pixel, sizeof(unsigned char), 3, fp);

        // Convert the pixel to binary
        decToBinary(pixel[0], &binaryPixel[0]);
        decToBinary(pixel[1], &binaryPixel[BYTE_SIZE]);
        decToBinary(pixel[2], &binaryPixel[2 * BYTE_SIZE]);

        // Extract the message from the pixel
        for (int j = 0; j < BYTE_SIZE; j++) {
            if (binaryMessageIndex < MESSAGE_SIZE * BYTE_SIZE) {
                binaryMessage[binaryMessageIndex] = binaryPixel[j] & 0x01;
                binaryMessageIndex++;
            }
        }

        // Check if the message size has been extracted
        if (binaryMessageIndex == BYTE_SIZE * MESSAGE_SIZE) {
            for (int k = 0; k < BYTE_SIZE; k++) {
                messageSize = messageSize << 1;
                messageSize = messageSize | binaryMessage[k];
            }

            break;
        }
    }

    // Check if the message size is valid
    if (messageSize <= 0 || messageSize > MESSAGE_SIZE) {
        printf("Error: The message size is invalid.\n");
        fclose(fp);
        return;
    }

    // Extract the message from the image
    int messageIndex = 0;

    for (int i = 0; i < messageSize * BYTE_SIZE; i += BYTE_SIZE) {
        char c = (char)binaryToDec(&binaryMessage[i]);

        if (c == '\0') {
            break;
        }

        printf("%c", c);

        messageIndex++;
    }

    printf("\nMessage extracted successfully.\n");

    // Close the file
    fclose(fp);
}

int main()
{
    int choice;
    char imageFileName[FILE_NAME_SIZE];
    char fileExtension[FILE_EXTENSION_SIZE];
    char message[MESSAGE_SIZE];

    while (1) {
        printf("1. Hide message in image.\n");
        printf("2. Extract message from image.\n");
        printf("3. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the name of the image file (without extension): ");
            scanf("%s", imageFileName);
            printf("Enter the extension of the image file: ");
            scanf("%s", fileExtension);
            strcat(imageFileName, ".");
            strcat(imageFileName, fileExtension);
            printf("Enter the message to hide: ");
            scanf(" %[^\n]s", message);
            hideMessageInImage(imageFileName, message);
            break;
        case 2:
            printf("Enter the name of the image file (without extension): ");
            scanf("%s", imageFileName);
            printf("Enter the extension of the image file: ");
            scanf("%s", fileExtension);
            strcat(imageFileName, ".");
            strcat(imageFileName, fileExtension);
            extractMessageFromImage(imageFileName);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}