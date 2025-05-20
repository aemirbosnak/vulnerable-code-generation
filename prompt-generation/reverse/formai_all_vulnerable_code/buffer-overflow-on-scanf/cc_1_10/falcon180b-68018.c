//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

int main()
{
    FILE *fp;
    char filename[50], ch;
    int i, j, k, size, choice, row, col, pixel, count = 0, flag = 0, num;
    unsigned char stegofile[MAX_SIZE];
    unsigned char message[MAX_SIZE];

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);

    printf("Enter the size of message to be hidden (in bytes): ");
    scanf("%d", &num);

    printf("Enter the message to be hidden:\n");

    for(i = 0; i < num; i++)
    {
        scanf("%c", &message[i]);
    }

    for(i = 0; i < size; i++)
    {
        fread(&stegofile[i], sizeof(unsigned char), 1, fp);
    }

    fclose(fp);

    for(i = 0; i < num; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(message[i] & (1 << j))
            {
                for(k = 0; k < 3; k++)
                {
                    row = i / 3;
                    col = i % 3;
                    pixel = (stegofile[(row * 3) + col] & ~(0x07 << (2 - k))) | ((message[i] >> (2 - k)) & 0x07);
                    stegofile[(row * 3) + col] = pixel;
                }
            }
        }
    }

    fp = fopen(filename, "wb");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    for(i = 0; i < size; i++)
    {
        fwrite(&stegofile[i], sizeof(unsigned char), 1, fp);
    }

    fclose(fp);

    printf("Message successfully hidden in the image.\n");

    return 0;
}