//FormAI DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("\n\n---------------------------------------------------------------");
    printf("\nA Mystery Image and Secret Message\n");
    printf("---------------------------------------------------------------\n\n");

    // Open image file in read mode
    FILE *imageFilePtr = fopen("mysteryImage.bmp", "rb");

    // If image file failed to open
    if (imageFilePtr == NULL) {
        printf("ERROR: Unable to open image file.\n");
        exit(EXIT_FAILURE);
    }

    // Read image file header
    unsigned char fileHeader[54];
    fread(fileHeader, sizeof(unsigned char), 54, imageFilePtr);

    // If image file type is incorrect
    if (fileHeader[0] != 'B' || fileHeader[1] != 'M') {
        printf("ERROR: Invalid image file type.\n");
        exit(EXIT_FAILURE);
    }

    // Determine image width and height
    int width = *(int*)&fileHeader[18];
    int height = *(int*)&fileHeader[22];

    // Reverse the bytes for cross-platform compatibility
    int i;
    unsigned char currentIndex;
    for(i = 0; i < 54 / 2; ++i)
    {
        currentIndex = fileHeader[i];
        fileHeader[i] = fileHeader[54 - i - 1];
        fileHeader[54 - i - 1] = currentIndex;
    }

    printf("The mystery image dimensions are: %d pixels (width) x %d pixels (height)\n\n", width, height);

    // Open message file in read mode
    FILE *messageFilePtr = fopen("secretMessage.txt", "r");

    // If message file failed to open
    if (messageFilePtr == NULL) {
        printf("ERROR: Unable to open message file.\n");
        exit(EXIT_FAILURE);
    }

    // Determine message length
    fseek(messageFilePtr, 0L, SEEK_END);
    int messageLength = ftell(messageFilePtr);
    fseek(messageFilePtr, 0L, SEEK_SET);

    // Allocate memory for message data
    char* messageData = (char*)malloc(messageLength);

    // If memory allocation failed
    if (messageData == NULL) {
        printf("ERROR: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    // Read message data
    fgets(messageData, messageLength, messageFilePtr);

    printf("The secret message is: \"%s\"\n\n", messageData);

    fclose(messageFilePtr);

    rewind(imageFilePtr);

    // Allocate memory for image data
    unsigned char* imageData = (unsigned char*)malloc(width * height * 3);

    // If memory allocation failed
    if (imageData == NULL) {
        printf("ERROR: Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }

    // Read image data
    fread(imageData, sizeof(unsigned char), width * height * 3, imageFilePtr);

    // Hide message in image data
    int messageIndex = 0;
    for(i = 0; i < width * height * 3; ++i)
    {
        if(i % 3 != 0) // Skip over every 3rd byte (the blue component)
        {
            if(messageIndex < messageLength)
            {
                imageData[i] = messageData[messageIndex];
                ++messageIndex;
            }
        }
    }

    // Open output image file in write mode
    FILE *outputImageFilePtr = fopen("mysteryMessage.bmp", "wb");

    // If output image file failed to open
    if (outputImageFilePtr == NULL) {
        printf("ERROR: Unable to open output image file.\n");
        exit(EXIT_FAILURE);
    }

    // Write output image file header
    fwrite(fileHeader, sizeof(unsigned char), 54, outputImageFilePtr);

    rewind(outputImageFilePtr);

    // Write modified image data to output image file
    fwrite(imageData, sizeof(unsigned char), width * height * 3, outputImageFilePtr);

    printf("Message successfully hidden in mystery image. New image saved as \"mysteryMessage.bmp\"\n\n");

    // Free dynamically allocated memory
    free(imageData);
    free(messageData);

    // Close open files
    fclose(imageFilePtr);
    fclose(outputImageFilePtr);

    return 0;
}