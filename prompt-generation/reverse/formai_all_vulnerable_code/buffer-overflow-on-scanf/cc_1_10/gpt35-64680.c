//FormAI DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *image, *stegImage, *msgFile; // file pointers for image, steganographed image and message file
    char imageName[20], stegImageName[20], msgFileName[20], ch;
    unsigned char buffer[4];
    int i, msgSize = 0;

    printf("Enter the image name along with extension: ");
    scanf("%s", imageName);

    // open the image file
    image = fopen(imageName, "rb");
    if (image == NULL) {
        printf("Error in opening %s!\n", imageName);
        exit(1); // exit the program with error code 1
    }

    // read the image header
    for (i = 0; i < 54; i++) { // header size is fixed for BMP images
        ch = fgetc(image);
    }

    printf("Enter the name for steganographed image (with extension): ");
    scanf("%s", stegImageName);

    // create a new file for steganographed image
    stegImage = fopen(stegImageName, "wb");
    if (stegImage == NULL) {
        printf("Error in creating %s!\n", stegImageName);
        exit(1); // exit the program with error code 1
    }

    // copy the header of the original image to the new file
    fseek(image, 0, SEEK_SET); // move the file pointer to the beginning of the file
    for (i = 0; i < 54; i++) {
        ch = fgetc(image);
        putc(ch, stegImage);
    }

    printf("Enter the message file name along with extension: ");
    scanf("%s", msgFileName);

    // open the message file
    msgFile = fopen(msgFileName, "r");
    if (msgFile == NULL) {
        printf("Error in opening %s!\n", msgFileName);
        exit(1); // exit the program with error code 1
    }

    // find the size of the message file
    fseek(msgFile, 0, SEEK_END); // move the file pointer to the end of the file
    msgSize = ftell(msgFile); // get the file size
    rewind(msgFile); // move the file pointer to the beginning of the file

    // write the size of the message file to the steganographed image file
    buffer[0] = msgSize >> 24 & 0xFF;
    buffer[1] = msgSize >> 16 & 0xFF;
    buffer[2] = msgSize >> 8 & 0xFF;
    buffer[3] = msgSize & 0xFF;
    fwrite(buffer, 1, 4, stegImage);

    // read the message file and steganograph it to the image
    for (i = 0; i < msgSize; i++) {
        ch = fgetc(msgFile);
        int j;
        for (j = 7; j >= 0; j--) {
            int pixel = fgetc(image);
            int bit = (ch >> j) & 1;
            if (bit == 1) {
                pixel |= 1;
            }
            else {
                pixel &= ~1;
            }
            putc(pixel, stegImage);
        }
    }

    // copy the rest of the pixels from the original image to the steganographed image
    while ((ch = fgetc(image)) != EOF) {
        putc(ch, stegImage);
    }

    // close all the files
    fclose(image);
    fclose(stegImage);
    fclose(msgFile);

    printf("Steganography completed successfully!\n");
    return 0;
}