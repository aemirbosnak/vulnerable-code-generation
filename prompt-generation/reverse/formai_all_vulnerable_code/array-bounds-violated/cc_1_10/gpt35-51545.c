//FormAI DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BIT_MASK 1

/* Function to convert decimal to binary */
void toBinary(int n, int bin[])
{
    int i;
    int k = 0;
    for (i = 7; i >= 0; i--)
    {
        if (n >> i & BIT_MASK)
            bin[k++] = 1;
        else
            bin[k++] = 0;
    }
}

/* Function to convert binary to decimal */
int toDecimal(int bin[])
{
    int i;
    int res = 0;
    for (i = 7; i >= 0; i--)
    {
        int k = 7 - i;
        res += (bin[i] * (1 << k));
    }
    return res;
}

/* Function to hide data in an image */
void hideData(char *message, int len, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    int i, j, k = 0;
    int binary[8];
    char c;
    while (fread(&c, sizeof(char), 1, fp))
    {
        toBinary(c, binary);
        for (i = 0; i < 8; i++)
        {
            if (k == len)
            {
                fseek(fp, -1, SEEK_CUR);
                fclose(fp);
                return;
            }
            binary[i] = binary[i] & ~BIT_MASK | ((message[k] >> i) & BIT_MASK);
            k++;
        }
        c = (char)toDecimal(binary);
        fseek(fp, -1, SEEK_CUR);
        fwrite(&c, sizeof(char), 1, fp);
    }
    fseek(fp, 0, SEEK_END);
    for (i = 0; i < 8; i++)
    {
        if (k == len)
        {
            fclose(fp);
            return;
        }
        if (k == 0)
            fseek(fp, -1, SEEK_CUR);
         binary[i] = binary[i] & ~BIT_MASK | ((message[k] >> i) & BIT_MASK);
         k++;
    }
    c = (char)toDecimal(binary);
    fwrite(&c, sizeof(char), 1, fp);
    fclose(fp);
    printf("Data successfully hidden in the image!\n");
}

/* Function to retrieve hidden data from an image */
void retrieveData(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    int i, binary[8];
    char c, msg[256];
    memset(msg, 0, sizeof(msg));
    int k = 0;
    while (fread(&c, sizeof(char), 1, fp))
    {
        toBinary(c, binary);
        for (i = 0; i < 8; i++)
        {
            if (k == 256)
            {
                fclose(fp);
                printf("Hidden message: %s\n", msg);
                return;
            }
            msg[k] |= (binary[i] & BIT_MASK) << i;
        }
        k++;
    }
    fclose(fp);
}

void main()
{
    char message[256], filename[100];
    printf("Enter a message to hide in the image: ");
    fgets(message, 256, stdin);
    message[strlen(message) - 1] = '\0';
    printf("Enter the filename of the image to hide the message in: ");
    fgets(filename, 100, stdin);
    filename[strlen(filename) - 1] = '\0';
    hideData(message, strlen(message), filename);
    retrieveData(filename);
}