//FormAI DATASET v1.0 Category: Image Steganography ; Style: relaxed
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 1000000

//Function to convert decimal to binary
void decimalToBinary(int n, int binaryArray[])
{
    int indexForBinaryArray = 0;
    while(n>0)
    {
        binaryArray[indexForBinaryArray++] = n%2;
        n = n/2;
    }
    while(indexForBinaryArray<8)
    {
        binaryArray[indexForBinaryArray++] = 0;
    }
    return;
}

//Function to convert binary to decimal
int binaryToDecimal(int binaryArray[])
{
    int sum=0;
    for(int i=0;i<8;i++)
    {
        sum+=binaryArray[i]*(1<<(7-i));
    }
    return sum;
}

int main()
{
    FILE *fpImage, *fpText, *fpEncoded;

    char imagePath[100], textPath[100], encodedPath[100];
    printf("Enter the path of the image: ");
    scanf("%s", imagePath);
    
    printf("Enter the path of the text to be encoded: ");
    scanf("%s", textPath);

    printf("Enter the path of the encoded file to be saved: ");
    scanf("%s", encodedPath);

    fpImage = fopen(imagePath, "rb");
    if(fpImage == NULL)
    {
        printf("Error: Cannot open image\n");
        exit(1);
    }

    fpText = fopen(textPath, "r");
    if(fpText == NULL)
    {
        printf("Error: Cannot open text file\n");
        exit(1);
    }

    fpEncoded = fopen(encodedPath, "w");
    if(fpEncoded == NULL)
    {
        printf("Error: Cannot create encoded file\n");
        exit(1);
    }

    fseek(fpImage, 0, SEEK_END);
    long imageSize = ftell(fpImage);
    fseek(fpImage, 0, SEEK_SET);

    unsigned char* imageData = (unsigned char*)malloc(imageSize);
    fread(imageData, imageSize, 1, fpImage);

    char* textData = (char*)malloc(BUFFER_SIZE);
    fgets(textData, BUFFER_SIZE, fpText);

    if(strlen(textData)*8 >= imageSize)
    {
        printf("Error: Text too long to encode into the image\n");
        exit(1);
    }

    int textDataIndex = 0;
    for(int i=0;i<imageSize;i+=3)
    {
        int binaryArrayForPixel1[8], binaryArrayForPixel2[8], binaryArrayForPixel3[8];
        decimalToBinary(imageData[i], binaryArrayForPixel1);
        decimalToBinary(imageData[i+1], binaryArrayForPixel2);
        decimalToBinary(imageData[i+2], binaryArrayForPixel3);

        for(int j=0;j<8;j++)
        {
            if(textDataIndex >= strlen(textData))
            {
                break;
            }
            binaryArrayForPixel1[j] = textData[textDataIndex++];
        }
        for(int j=0;j<8;j++)
        {
            if(textDataIndex >= strlen(textData))
            {
                break;
            }
            binaryArrayForPixel2[j] = textData[textDataIndex++];
        }
        for(int j=0;j<8;j++)
        {
            if(textDataIndex >= strlen(textData))
            {
                break;
            }
            binaryArrayForPixel3[j] = textData[textDataIndex++];
        }

        imageData[i] = binaryToDecimal(binaryArrayForPixel1);
        imageData[i+1] = binaryToDecimal(binaryArrayForPixel2);
        imageData[i+2] = binaryToDecimal(binaryArrayForPixel3);
    }

    fwrite(imageData, imageSize, 1, fpEncoded);
    printf("Encoding Successful\n");

    free(imageData);
    free(textData);
    fclose(fpImage);
    fclose(fpText);
    fclose(fpEncoded);
    return 0;
}