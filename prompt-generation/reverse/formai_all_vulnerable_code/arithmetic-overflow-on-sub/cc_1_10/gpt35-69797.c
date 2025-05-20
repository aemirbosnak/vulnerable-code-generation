//FormAI DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to get bit value from int
int getBitValue(int num, int bit) {
    return ((num & (1 << bit)) != 0);
}

//Function to set bit value in int
int setBitValue(int num, int bit, int value) {
    if(value == 1) {
        return (num | (1 << bit));
    } else {
        return (num & ~(1 << bit));
    }
}

//Function to hide message in image
void hideMessageInImage(char* imageFile, char* messageFile, char* outputFile) {
    //Open image file
    FILE *imageFp = fopen(imageFile, "rb");
    if(imageFp == NULL) {
        printf("Error: Unable to open image file %s\n", imageFile);
        exit(1);
    }

    //Read image file header and data
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFp);
    int imageSize = *(int*)&header[2];
    unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char)*imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, imageFp);
    fclose(imageFp);

    //Open message file
    FILE *messageFp = fopen(messageFile, "r");
    if(messageFp == NULL) {
        printf("Error: Unable to open message file %s\n", messageFile);
        exit(1);
    }

    //Read message file data
    char message[100];
    fgets(message, 100, messageFp);
    fclose(messageFp);

    int messageLength = strlen(message);
    int imageIndex = 0;
    int bitIndex = 0;
    int byteIndex = 0;
    int maxMessageLength = (imageSize - 54)/8;

    //Check if message can be hidden in image
    if(messageLength > maxMessageLength) {
        printf("Error: Unable to hide message in image. Message size is too large.\n");
        exit(1);
    }

    //Loop through all pixels in image data
    for(int i=0; i<imageSize; i+=3) {
        if(bitIndex == 8) {
            bitIndex = 0;
            byteIndex++;
        }

        if(byteIndex >= messageLength+1) {
            break;
        }

        //Get RGB values of pixel
        int red = imageData[i];
        int green = imageData[i+1];
        int blue = imageData[i+2];

        if(byteIndex == 0) {
            //Set first pixel to message length
            int messageLengthBits[8];
            for(int j=0; j<8; j++) {
                messageLengthBits[j] = getBitValue(messageLength, j);
            }
            red = setBitValue(red, 0, messageLengthBits[0]);
            red = setBitValue(red, 1, messageLengthBits[1]);
            red = setBitValue(red, 2, messageLengthBits[2]);
            red = setBitValue(red, 3, messageLengthBits[3]);
            green = setBitValue(green, 0, messageLengthBits[4]);
            green = setBitValue(green, 1, messageLengthBits[5]);
            green = setBitValue(green, 2, messageLengthBits[6]);
            green = setBitValue(green, 3, messageLengthBits[7]);
        } else {
            //Set message bits in R and G values
            int messageByte = (int)message[byteIndex-1];
            int messageByteBits[8];
            for(int j=0; j<8; j++) {
                messageByteBits[j] = getBitValue(messageByte, j);
            }
            red = setBitValue(red, bitIndex, messageByteBits[0]);
            green = setBitValue(green, bitIndex, messageByteBits[1]);

            bitIndex++;

            //Check if end of message byte is reached
            if(bitIndex == 8) {
                bitIndex = 0;
                byteIndex++;
            }
        }

        //Set new RGB values in image data
        imageData[i] = red;
        imageData[i+1] = green;
        imageData[i+2] = blue;

        imageIndex++;
    }

    //Write the new image data to output file
    FILE *outputFp = fopen(outputFile, "wb");
    fwrite(header, sizeof(unsigned char), 54, outputFp);
    fwrite(imageData, sizeof(unsigned char), imageSize, outputFp);
    fclose(outputFp);

    printf("Message hidden in image successfully.\n");
}

//Function to retrieve message from image
void retrieveMessageFromImage(char* imageFile, char* outputFile) {
    //Open image file
    FILE *imageFp = fopen(imageFile, "rb");
    if(imageFp == NULL) {
        printf("Error: Unable to open image file %s\n", imageFile);
        exit(1);
    }

    //Read image file header and data
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFp);
    int imageSize = *(int*)&header[2];
    unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char)*imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, imageFp);
    fclose(imageFp);

    //Get message length from first pixel
    int messageLength = 0;
    messageLength = setBitValue(messageLength, 0, getBitValue(imageData[0], 0));
    messageLength = setBitValue(messageLength, 1, getBitValue(imageData[0], 1));
    messageLength = setBitValue(messageLength, 2, getBitValue(imageData[0], 2));
    messageLength = setBitValue(messageLength, 3, getBitValue(imageData[0], 3));
    messageLength = setBitValue(messageLength, 4, getBitValue(imageData[1], 0));
    messageLength = setBitValue(messageLength, 5, getBitValue(imageData[1], 1));
    messageLength = setBitValue(messageLength, 6, getBitValue(imageData[1], 2));
    messageLength = setBitValue(messageLength, 7, getBitValue(imageData[1], 3));

    int messageLengthBytes = messageLength;
    int messageIndex = 0;
    int bitIndex = 0;
    char message[100];

    //Loop through all pixels in image data
    for(int i=0; i<imageSize; i+=3) {
        if(bitIndex == 8) {
            bitIndex = 0;
        }

        if(messageIndex >= messageLengthBytes) {
            break;
        }

        //Get RGB values of pixel
        int red = imageData[i];
        int green = imageData[i+1];

        if(messageIndex == 0) {
            //Skip first pixel which contains message length
        } else {
            //Retrieve message bits from R and G values
            int messageByte = 0;
            messageByte = setBitValue(messageByte, 0, getBitValue(red, bitIndex));
            messageByte = setBitValue(messageByte, 1, getBitValue(green, bitIndex));

            message[messageIndex-1] = (char)messageByte;

            bitIndex++;

            //Check if end of message byte is reached
            if(bitIndex == 8) {
                bitIndex = 0;
                messageIndex++;
            }
        }
    }

    //Write message to output file
    FILE *outputFp = fopen(outputFile, "w");
    fprintf(outputFp, "%s", message);
    fclose(outputFp);

    printf("Message retrieved from image successfully.\n");
}

//Main function
int main() {
    char* imageFile = "image.bmp";
    char* messageFile = "secret.txt";
    char* outputFile = "output.bmp";

    hideMessageInImage(imageFile, messageFile, outputFile);

    retrieveMessageFromImage(outputFile, "retrieved.txt");

    return 0;
}