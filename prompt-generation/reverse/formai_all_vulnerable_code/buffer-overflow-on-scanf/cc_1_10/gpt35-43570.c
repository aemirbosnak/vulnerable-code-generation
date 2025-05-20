//FormAI DATASET v1.0 Category: Image Steganography ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Define variables
#define BYTES_PER_PIXEL 3
#define FILENAME_SIZE 256
#define SECRET_MESSAGE_SIZE 1000

//Function declaration
void hideMessageInImage(char* imageName, char* secretMessage);
void retrieveMessageFromImage(char* imageName);

//Main function
int main()
{
    char imageName[FILENAME_SIZE];
    char secretMessage[SECRET_MESSAGE_SIZE];

    printf("Welcome to Image Steganography Program!\n");
    printf("Enter the name of the image file to hide your secret message: ");
    scanf("%s", imageName);

    printf("Enter the secret message to be hidden in the image (max 1000 characters): ");
    scanf(" %[^\n]s", secretMessage);

    printf("Hiding the secret message in the image...\n");
    hideMessageInImage(imageName, secretMessage);
    printf("Secret message is hidden in the image successfully!\n");

    printf("Retrieving the secret message from the image...\n");
    retrieveMessageFromImage(imageName);
    printf("Secret message is retrieved from the image successfully!\n");

    printf("Thank you for using Image Steganography Program!\n");

    return 0;
}

//Function definition to hide the message in the image
void hideMessageInImage(char* imageName, char* secretMessage)
{
    //Open the image file in binary mode
    FILE* imageFile = fopen(imageName, "rb");

    //Get the size of the image file
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    //Allocate memory to store the entire image contents
    char* imageData = (char*) malloc(sizeof(char) * imageSize);
    fread(imageData, sizeof(char), imageSize, imageFile);
    fclose(imageFile);

    //Loop through the image and write secret message as LSB of each pixel
    int secretMessageIndex = 0;
    int imageDataIndex = 0;
    while (secretMessage[secretMessageIndex] != '\0')
    {
        for (int i = 0; i < BYTES_PER_PIXEL - 1; i++)
        {
            if (secretMessage[secretMessageIndex] & 1 << i)
            {
                imageData[imageDataIndex] |= 1;
            }
            else
            {
                imageData[imageDataIndex] &= ~1;
            }
            imageDataIndex++;
        }
        secretMessageIndex++;
    }

    //Write a null-terminator character as the end marker of the secret message
    for (int i = 0; i < BYTES_PER_PIXEL - 1; i++)
    {
        imageData[imageDataIndex] &= ~1;
        imageDataIndex++;
    }

    //Write the modified image data to the same image file
    imageFile = fopen(imageName, "wb");
    fwrite(imageData, sizeof(char), imageSize, imageFile);
    fclose(imageFile);

    free(imageData);
}

//Function definition to retrieve the message from the image
void retrieveMessageFromImage(char* imageName)
{
    //Open the image file in binary mode
    FILE* imageFile = fopen(imageName, "rb");

    //Get the size of the image file
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    //Allocate memory to store the entire image contents
    char* imageData = (char*) malloc(sizeof(char) * imageSize);
    fread(imageData, sizeof(char), imageSize, imageFile);
    fclose(imageFile);

    //Loop through the image and read LSB of each pixel to retrieve the message
    char secretMessage[SECRET_MESSAGE_SIZE];
    int secretMessageIndex = 0;
    int imageDataIndex = 0;
    char byteValue = 0;
    int bitIndex = 0;
    while (imageDataIndex < imageSize)
    {
        byteValue <<= 1;
        byteValue |= imageData[imageDataIndex] & 1;
        bitIndex++;
        if (bitIndex == BYTES_PER_PIXEL - 1)
        {
            secretMessage[secretMessageIndex] = byteValue;
            secretMessageIndex++;
            byteValue = 0;
            bitIndex = 0;
        }
        imageDataIndex++;
        if (secretMessage[secretMessageIndex - 1] == '\0')
        {
            break;
        }
    }

    //Print the retrieved secret message
    printf("The retrieved secret message is: %s\n", secretMessage);

    free(imageData);
}