//FormAI DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to get decimal value of given binary string
int binaryToDecimal(char *binary)
{
    int decimal = 0, power = 1, length = strlen(binary);
    for(int i = length-1; i >= 0; i--)
    {
        int digit = binary[i]-'0';
        decimal += digit * power;
        power *= 2;
    }
    return decimal;
}

// Function to convert decimal to binary and store in given array of size 8
void decimalToBinary(int decimal, char *binary)
{
    for(int i = 7; i >= 0; i--)
    {
        binary[i] = decimal % 2 + '0';
        decimal /= 2;
    }
    binary[8] = '\0';
}

// Function to get LSB (Least Significant Bit) of a given decimal number
int getLSB(int decimal)
{
    return decimal % 2;
}

// Function to set LSB of a given decimal number to given bit value
void setLSB(int *decimal, int bit)
{
    *decimal = (*decimal & ~1) | (bit & 1);
}

// Function to hide given message in given image using LSB steganography
void hideMessage(char *message, char *image, char *outputImage)
{
    FILE *fpImg = fopen(image, "rb");
    FILE *fpOut = fopen(outputImage, "wb");
    if(fpImg == NULL || fpOut == NULL)
    {
        printf("Error opening files!\n");
        exit(1);
    }
    int pixel[3], bit = 0, count = 0;
    char byte = 0, binary[9];
    while(fread(pixel, 3, 1, fpImg))
    {
        for(int i = 0; i < 3; i++)
        {
            decimalToBinary(pixel[i], binary);
            setLSB(&pixel[i], getLSB(message[count]));
            count++;
            if(count > strlen(message))
            {
                bit = 1;
                break;
            }
        }
        byte = binaryToDecimal(binary);
        fwrite(pixel, 3, 1, fpOut);
        if(bit)
            break;
    }
    while(fread(pixel, 3, 1, fpImg))
    {
        fwrite(pixel, 3, 1, fpOut);
    }
    printf("Message hidden successfully!\n");
    fclose(fpImg);
    fclose(fpOut);
}

// Function to reveal hidden message in given image using LSB steganography
void showMessage(char *image)
{
    FILE *fp = fopen(image, "rb");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    char binary[9], message[1000], byte = 0;
    int pixel[3], count = 0;
    while(fread(pixel, 3, 1, fp))
    {
        for(int i = 0; i < 3; i++)
        {
            decimalToBinary(pixel[i], binary);
            byte = (byte << 1) | getLSB(pixel[i]);
            if(count % 8 == 7)
            {
                message[count/8] = byte;
                byte = 0;
            }
            count++;
        }
    }
    message[count/8] = '\0';
    printf("Hidden message: %s\n", message);
    fclose(fp);
}

// Main function to test steganography program
int main()
{
    char message[1000], image[100], outputImage[100];
    printf("Enter message to hide: ");
    scanf("%[^\n]s", message);
    getchar();
    printf("Enter name of image file: ");
    scanf("%[^\n]s", image);
    getchar();
    printf("Enter name of output image file: ");
    scanf("%[^\n]s", outputImage);

    hideMessage(message, image, outputImage);

    printf("Do you want to reveal hidden message? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if(choice == 'y')
    {
        showMessage(outputImage);
    }

    return 0;
}