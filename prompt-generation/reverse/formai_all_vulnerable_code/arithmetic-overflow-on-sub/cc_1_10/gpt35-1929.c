//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_SECRET_MSG 10000
#define OFFSET 54

void hideMessageInImage(char *fileName, char *secretMessage){
    FILE *imageFile, *newImageFile;
    char newFileName[MAX_FILE_NAME];
    unsigned char *bmpHeader, *imageData, *secretData;
    int fileSize, imageSize, secretSize, i, j, bitCount = 0, bitIndex = 0;

    // Open the input file
    imageFile = fopen(fileName, "rb");
    if(imageFile == NULL){
        printf("Error opening the image file!\n");
        exit(1);
    }

    // Determine the file size and allocate memory for the BMP header and image data
    fseek(imageFile, 0, SEEK_END);
    fileSize = ftell(imageFile);
    rewind(imageFile);
    bmpHeader = (unsigned char *) malloc(OFFSET);
    imageData = (unsigned char *) malloc(fileSize - OFFSET);

    // Read the BMP header
    if(fread(bmpHeader, sizeof(unsigned char), OFFSET, imageFile) != OFFSET){
        printf("Error reading the BMP header!\n");
        exit(1);
    }

    // Read the image data
    if(fread(imageData, sizeof(unsigned char), fileSize - OFFSET, imageFile) != fileSize - OFFSET){
        printf("Error reading the image data!\n");
        exit(1);
    }

    // Close the input file
    fclose(imageFile);

    // Get the image size
    imageSize = fileSize - OFFSET;

    // Get the length of the secret message
    secretSize = strlen(secretMessage);

    // Allocate memory for the secret data
    secretData = (unsigned char *) malloc(secretSize * 8);

    // Convert the secret message to binary and store it in the secret data array
    for(i = 0; i < secretSize; i++){
        for(j = 7; j >= 0; j--){
            secretData[bitCount++] = (secretMessage[i] >> j) & 1;
        }
    }

    // Calculate the maximum number of bits that can be hidden in the image
    int maxBits = imageSize * 8;

    // Check if the secret message can fit in the image
    if(bitCount > maxBits){
        printf("Error! The secret message is too large to be hidden in the image!\n");
        exit(1);
    }

    // Copy the image data to a new array
    unsigned char *newImageData = (unsigned char *) malloc(imageSize);
    memcpy(newImageData, imageData, imageSize);

    // Hide the secret data in the new image data array
    for(i = 0; i < bitCount; i++){
        // Get the bit at the current index
        int bit = secretData[i];

        // Get the byte index and bit index in the byte for the current pixel
        int byteIndex = (i / 8) + OFFSET;
        int pixelBitIndex = i % 8;

        // Set the LSB of the byte to the current bit
        newImageData[byteIndex] = (newImageData[byteIndex] & ~(1 << pixelBitIndex)) | (bit << pixelBitIndex);
    }

    // Get the new file name
    strcpy(newFileName, "new_");
    strcat(newFileName, fileName);

    // Open the new output file
    newImageFile = fopen(newFileName, "wb");
    if(newImageFile == NULL){
        printf("Error creating the new image file!\n");
        exit(1);
    }

    // Write the BMP header to the new file
    if(fwrite(bmpHeader, sizeof(unsigned char), OFFSET, newImageFile) != OFFSET){
        printf("Error writing the BMP header to the new file!\n");
        exit(1);
    }

    // Write the new image data to the new file
    if(fwrite(newImageData, sizeof(unsigned char), imageSize, newImageFile) != imageSize){
        printf("Error writing the new image data to the new file!\n");
        exit(1);
    }

    // Close the new output file
    fclose(newImageFile);

    printf("The secret message has been hidden in the image successfully!\n");

    // Free the memory
    free(bmpHeader);
    free(imageData);
    free(secretData);
    free(newImageData);
}

void extractMessageFromImage(char *fileName){
    FILE *imageFile;
    unsigned char *bmpHeader, *imageData;
    int fileSize, imageSize, i, j, bitCount = 0, byteCount = 0;
    char secretMsg[MAX_SECRET_MSG];

    // Open the input file
    imageFile = fopen(fileName, "rb");
    if(imageFile == NULL){
        printf("Error opening the image file!\n");
        exit(1);
    }

    // Determine the file size and allocate memory for the BMP header and image data
    fseek(imageFile, 0, SEEK_END);
    fileSize = ftell(imageFile);
    rewind(imageFile);
    bmpHeader = (unsigned char *) malloc(OFFSET);
    imageData = (unsigned char *) malloc(fileSize - OFFSET);

    // Read the BMP header
    if(fread(bmpHeader, sizeof(unsigned char), OFFSET, imageFile) != OFFSET){
        printf("Error reading the BMP header!\n");
        exit(1);
    }

    // Read the image data
    if(fread(imageData, sizeof(unsigned char), fileSize - OFFSET, imageFile) != fileSize - OFFSET){
        printf("Error reading the image data!\n");
        exit(1);
    }

    // Close the input file
    fclose(imageFile);

    // Get the image size
    imageSize = fileSize - OFFSET;

    // Extract the secret data from the image
    for(i = 0; i < imageSize; i++){
        // Get the byte index and bit index in the byte for the current pixel
        int byteIndex = (i / 8) + OFFSET;
        int pixelBitIndex = i % 8;

        // Get the LSB of the byte
        int bit = (imageData[byteIndex] >> pixelBitIndex) & 1;

        // Store the bit in the secret message array
        secretMsg[bitCount] = (secretMsg[bitCount] << 1) | bit;
        
        // Increment the byte count and bit count
        if(++byteCount == 8){
            byteCount = 0;
            bitCount++;
        }
    }

    // Null-terminate the secret message
    secretMsg[bitCount / 8] = '\0';

    // Output the secret message
    printf("The secret message hidden in the image is:\n%s\n", secretMsg);

    // Free the memory
    free(bmpHeader);
    free(imageData);
}

int main(){
    char fileName[MAX_FILE_NAME], secretMessage[MAX_SECRET_MSG];
    int choice;

    printf("1. Hide message in image\n");
    printf("2. Extract message from image\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the name of the image file to hide the message in: ");
            scanf("%s", fileName);
            printf("Enter the secret message to hide in the image: ");
            getchar();
            fgets(secretMessage, MAX_SECRET_MSG, stdin);
            hideMessageInImage(fileName, secretMessage);
            break;
        case 2:
            printf("Enter the name of the image file to extract the message from: ");
            scanf("%s", fileName);
            extractMessageFromImage(fileName);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}