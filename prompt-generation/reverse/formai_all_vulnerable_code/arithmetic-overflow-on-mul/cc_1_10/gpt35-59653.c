//FormAI DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include<stdio.h>

// function to convert decimal to binary
void decToBinary(int num, int binary[])
{
    for(int i = 7; i >= 0; i--)
    {
        binary[i] = num % 2;
        num = num / 2;
    }
}

// function to convert binary to decimal
int binaryToDec(int binary[])
{
    int dec = 0;
    for(int i = 0; i < 8; i++)
    {
        dec = dec * 2 + binary[i];
    }
    return dec;
}

int main()
{
    // input image file and output image file
    FILE *inImg = fopen("input.bmp", "rb");
    FILE *outImg = fopen("output.bmp", "wb");

    // read header of input image file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inImg);

    // write header to output image file
    fwrite(header, sizeof(unsigned char), 54, outImg);

    // extract width and height from header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // calculate size of image data and allocate memory
    int imageDataSize = width * height * 3;
    unsigned char* imageData = (unsigned char*)malloc(sizeof(unsigned char) * imageDataSize);

    // read image data from input image file
    fread(imageData, sizeof(unsigned char), imageDataSize, inImg);

    // message to hide in image
    char* message = "Hello World!";

    // convert message to binary string
    int binaryMsg[8 * strlen(message)];
    int index = 0;
    for(int i = 0; i < strlen(message); i++)
    {
        decToBinary((int)message[i], &binaryMsg[index]);
        index += 8;
    }

    // hide binary message in image data
    index = 0;
    for(int i = 0; i < imageDataSize; i++)
    {
        if(index >= 8 * strlen(message))
            break;

        int binaryPixel[8];
        decToBinary(imageData[i], binaryPixel);

        for(int j = 0; j < 8; j++)
        {
            if(index >= 8 * strlen(message))
                break;

            binaryPixel[j] = binaryMsg[index];

            index++;
        }

        imageData[i] = binaryToDec(binaryPixel);
    }

    // write modified image data to output image file
    fwrite(imageData, sizeof(unsigned char), imageDataSize, outImg);

    // free allocated memory
    free(imageData);

    // close files
    fclose(inImg);
    fclose(outImg);

    return 0;
}