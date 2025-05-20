//FormAI DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert decimal to binary
void decimalToBinary(int num, int binary[])
{
    int i = 0;
    while (num > 0)
    {
        binary[i] = num % 2;
        num = num/2;
        i++;
    }
}

// function to convert binary to decimal
int binaryToDecimal(int binary[])
{
    int decimal = 0;
    int base = 1;
    for (int i = 0; i < 8; i++)
    {
        decimal += binary[i] * base;
        base *= 2;
    }
    return decimal;
}

int main()
{
    FILE *inFile, *outFile;
    char inFileName[100], outFileName[100], secretMessage[1000];
    int binaryMessage[8000], pixel, binaryPixel[8];
    int width, height, maxVal, i, j;

    printf("Enter the name of the input image file: ");
    scanf("%s", inFileName);

    inFile = fopen(inFileName, "rb");

    // get dimensions of image
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, inFile);
    getline(&line, &len, inFile);
    sscanf(line, "%d %d", &width, &height);
    getline(&line, &len, inFile);
    sscanf(line, "%d", &maxVal);

    // create output file
    strcpy(outFileName, "output.ppm");
    outFile = fopen(outFileName, "w+");
    fprintf(outFile, "P3\n%d %d\n%d\n", width, height, maxVal);

    // get secret message from user
    printf("Enter secret message: ");
    fgets(secretMessage, sizeof(secretMessage), stdin);

    int messageLength = strlen(secretMessage);
    if (secretMessage[messageLength-1] == '\n')
        secretMessage[messageLength-1] = '\0';

    // convert the message to binary
    for (i=0; i<messageLength; i++)
    {
        decimalToBinary((int)secretMessage[i], &binaryMessage[i*8]);
    }
    int totalBits = i*8;

    // check if message fits in image
    int maxBits = width*height*3;
    if (totalBits > maxBits)
    {
        printf("Message is too large for this image\n");
        return 0;
    }

    // read and modify image pixels
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // red pixel
            fread(&pixel, sizeof(pixel), 1, inFile);
            decimalToBinary(pixel, binaryPixel);
            if (totalBits > 0)
            {
                binaryPixel[7] = binaryMessage[totalBits-1];
                totalBits--;
            }
            pixel = binaryToDecimal(binaryPixel);
            fprintf(outFile, "%d ", pixel);

            // green pixel
            fread(&pixel, sizeof(pixel), 1, inFile);
            decimalToBinary(pixel, binaryPixel);
            if (totalBits > 0)
            {
                binaryPixel[7] = binaryMessage[totalBits-1];
                totalBits--;
            }
            pixel = binaryToDecimal(binaryPixel);
            fprintf(outFile, "%d ", pixel);

            // blue pixel
            fread(&pixel, sizeof(pixel), 1, inFile);
            decimalToBinary(pixel, binaryPixel);
            if (totalBits > 0)
            {
                binaryPixel[7] = binaryMessage[totalBits-1];
                totalBits--;
            }
            pixel = binaryToDecimal(binaryPixel);
            fprintf(outFile, "%d ", pixel);
        }
        fprintf(outFile, "\n");
    }

    printf("Message hidden in image successfully\n");

    fclose(inFile);
    fclose(outFile);
    return 0;
}