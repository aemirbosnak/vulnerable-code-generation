//FormAI DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1024

// This function will hide the message into image
void encodeMessage(FILE *image, FILE * secretFile, FILE * encodedImage) {
    unsigned char buffer[BUFFER_SIZE];
    int msgByte, fileByte, i, msgBit;
    int imgByte;

    while((msgByte = fgetc(secretFile)) != EOF) { 
        for(i=0; i<8; i++) {
            msgBit = (msgByte >> i) & 1;
            fileByte = fgetc(image);

            if(fileByte == EOF) {
                printf("\nError: Image file ended unexpectedly\n");
                exit(1);
            }

            imgByte = (((fileByte >> 1) << 1) | msgBit);

            fputc(imgByte, encodedImage);
        }
    }

    while((imgByte = fgetc(image)) != EOF) {
        fputc(imgByte, encodedImage);
    }
}

//This function will extract the message from the image
void decodeMessage(FILE *encodedImage, int *secretFileSize) {
    unsigned char buffer[BUFFER_SIZE];
    int fileByte, i, msgByte = 0, bitCount = 0;
    int imgByte;

    while((imgByte = fgetc(encodedImage)) != EOF) {
        msgByte |= ((imgByte & 1) << bitCount++);
        if(bitCount == 8) {
            fputc(msgByte, stdout);
            bitCount = 0;
            msgByte = 0;
            (*secretFileSize)--;
            if(*secretFileSize == 0)
                break;
        }
    }
}

int main() {
    FILE *image, *secretFile, *encodedImage;
    char imagePath[100], secretFilePath[100], encodedImagePath[100];
    char selection;
    int secretFileSize = 0;

    printf("Welcome to Image Steganography Program\n");
    printf("\nEnter image path (.bmp file): ");
    scanf("%s", imagePath);

    //Validating the image
    image = fopen(imagePath, "rb");
    if(!image) {
        printf("\nFile not found.\n");
        exit(1);
    }

    //Getting the secret file path
    printf("\nEnter secret file path (.txt file): ");
    scanf("%s", secretFilePath);

    //Validating the secret file
    secretFile = fopen(secretFilePath, "rb");
    if(!secretFile) {
        printf("\nFile not found.\n");
        exit(1);
    }

    //Getting the selection
    printf("\nEncode(E) or Decode(D): ");
    scanf(" %c", &selection);
    if(selection != 'E' && selection != 'D') {
        printf("\nInvalid Selection.\n");
        exit(1);
    }

    //Getting the encoded image path
    printf("\nEnter encoded image path (.bmp file): ");
    scanf("%s", encodedImagePath);

    //Encoding the message into image
    if(selection == 'E') {
        encodedImage = fopen(encodedImagePath, "wb");
        if(!encodedImage) {
            printf("\nError while creating file.\n");
            exit(1);
        }

        //Calculating the size of secret file
        fseek(secretFile, 0L, SEEK_END);
        secretFileSize = ftell(secretFile);
        rewind(secretFile);

        //Skip the bitmap header
        fseek(image, 54, SEEK_SET);

        //Call the encode function
        encodeMessage(image, secretFile, encodedImage);

        //Calculate the size of encoded image
        fseek(encodedImage, 0L, SEEK_END);
        printf("\nEncoded image file size: %ld bytes", ftell(encodedImage));
    }
    //Decoding message from image
    else {
        encodedImage = fopen(encodedImagePath, "rb");
        if(!encodedImage) {
            printf("\nError: File not found.\n");
            exit(1);
        }

        //Skip the bitmap header
        fseek(encodedImage, 54, SEEK_SET);

        //Call the decode function
        decodeMessage(encodedImage, &secretFileSize);
    }

    //Close all the files
    fclose(secretFile);
    fclose(image);
    fclose(encodedImage);

    return 0;
}