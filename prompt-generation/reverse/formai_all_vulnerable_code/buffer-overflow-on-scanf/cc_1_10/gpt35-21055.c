//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
* Program to demonstrate the concept of digital watermarking 
* in text using LSB Steganography
* Author: Your Name
*/

// Function to convert character to binary
char* chartobin(char c)
{
    char* bin = (char*)malloc(9 * sizeof(char));
    int num = c;
    for(int i=0; i<8; i++)
    {
        bin[i] = (num % 2 == 0) ? '0' : '1';
        num = num/2;
    }
    bin[8] = '\0';
    return bin;
}

// Function to convert binary to character
char bintochar(char* bin)
{
    int num = 0;
    for(int i=7; i>=0; i--)
    {
        if(bin[i] == '1')
            num += 1<<7-i;
    }
    return (char)num;
}

int main()
{
    printf("Enter the text to be watermarked: ");
    char* message = (char*)malloc(100 * sizeof(char));
    scanf("%[^\n]s", message);
    getchar();

    printf("\nEnter the watermark: ");
    char* watermark = (char*)malloc(20 * sizeof(char));
    scanf("%[^\n]s", watermark);

    // Length of the watermark
    int watermark_len = strlen(watermark);

    // Loop through message and embed watermark
    int i = 0, j = 0;
    while(message[i] != '\0')
    {
        char* bin = chartobin(message[i]);
        if(j < watermark_len)
        {
            char* watermark_bin = chartobin(watermark[j]);
            bin[7] = watermark_bin[0];
            bin[6] = watermark_bin[1];
            bin[5] = watermark_bin[2];
            bin[4] = watermark_bin[3];
            bin[3] = watermark_bin[4];
            bin[2] = watermark_bin[5];
            bin[1] = watermark_bin[6];
            bin[0] = watermark_bin[7];
            j++;
        }
        printf("%s ", bin);
        i++;
    }
    printf("\n");

    // Loop through message and extract watermark
    i = 0, j = 0;
    char* extracted = (char*)malloc(watermark_len * sizeof(char));
    memset(extracted, 0, watermark_len);
    while(message[i] != '\0' && j < watermark_len)
    {
        char* bin = chartobin(message[i]);
        char* watermark_bin = (char*)malloc(9 * sizeof(char));
        watermark_bin[0] = bin[7];
        watermark_bin[1] = bin[6];
        watermark_bin[2] = bin[5];
        watermark_bin[3] = bin[4];
        watermark_bin[4] = bin[3];
        watermark_bin[5] = bin[2];
        watermark_bin[6] = bin[1];
        watermark_bin[7] = bin[0];
        watermark_bin[8] = '\0';
        extracted[j] = bintochar(watermark_bin);
        j++;
        i++;
    }
    printf("\nExtracted watermark: %s\n", extracted);

    return 0;
}