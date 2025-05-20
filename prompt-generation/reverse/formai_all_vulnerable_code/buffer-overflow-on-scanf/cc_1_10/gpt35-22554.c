//FormAI DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>

#define BUFFER_SIZE 100000
#define FILENAME_SIZE 100

int main()
{
    char inputFileName[FILENAME_SIZE];
    char outputFileName[FILENAME_SIZE];
    char message[BUFFER_SIZE];

    printf("Enter the input filename containing the image: ");
    scanf("%s", inputFileName);

    printf("Enter the output filename for the steganographed image: ");
    scanf("%s", outputFileName);

    printf("Enter the message to be hidden: ");
    scanf(" %[^\n]s", message);

    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");

    //Copy header bytes to output file
    unsigned char byte;
    for (int i = 0; i < 54; i++)
    {
        fread(&byte, sizeof(unsigned char), 1, inputFile);
        fwrite(&byte, sizeof(unsigned char), 1, outputFile);
    }

    //Convert message to binary representation
    int messageLength = strlen(message);
    unsigned char binaryMessage[BUFFER_SIZE];
    int binaryMessageIndex = 0;

    for (int i = 0; i < messageLength; i++)
    {
        unsigned char c = message[i];
        for (int j = 0; j < 8; j++)
        {
            binaryMessage[binaryMessageIndex++] = (c >> (7-j)) & 1;
        }
    }

    int binaryMessageLength = binaryMessageIndex;

    //Hide message in LSB of each pixel
    int index = 0;
    while (fread(&byte, sizeof(unsigned char), 1, inputFile))
    {
        if (index < binaryMessageLength)
        {
            byte = (byte & 0xFE) | binaryMessage[index]; //Set LSB to the corresponding bit of the message
            index++;
        }   
        fwrite(&byte, sizeof(unsigned char), 1, outputFile);
    }

    //Add EOF character to signal end of message
    for (int i = 0; i < 8; i++)
    {
        unsigned char eofChar = 0;
        eofChar = (eofChar | 1) << (7-i);
        fwrite(&eofChar, sizeof(unsigned char), 1, outputFile);
    }

    printf("Message successfully hidden in the image.\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}