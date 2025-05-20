//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX_CHARACTERS 1000

void embedMessage(char *fileName, char *message)
{
    FILE *filePtr;
    int i, j, k, len, carry;

    filePtr = fopen(fileName, "r+");

    if(filePtr == NULL)
    {
        printf("ERROR: Unable to open file.\n");
        exit(0);
    }

    char buffer[MAX_CHARACTERS];
    fgets(buffer, MAX_CHARACTERS, filePtr);

    // Embed watermark message
    len = strlen(message);
    k = 0;
    for(i = 0; i < len; i++)
    {
        for(j = 0; j < 8; j++)
        {
            carry = (message[i] >> j) & 1;
            if(feof(filePtr))
            {
                printf("ERROR: File size too small to embed message.\n");
                exit(0);
            }

            buffer[k] &= 0xFE; // Clear last bit
            buffer[k] |= carry; // Embed message bit
            k++;
        }
    }

    fseek(filePtr, 0, 0);
    fwrite(buffer, sizeof(char), strlen(buffer), filePtr);
    fclose(filePtr);

    printf("Message embedded successfully.\n");
}

void extractMessage(char *fileName)
{
    FILE *filePtr;
    int i, j, k, bitCount, len;
    char buffer[MAX_CHARACTERS], message[MAX_CHARACTERS];

    filePtr = fopen(fileName, "r");

    if(filePtr == NULL)
    {
        printf("ERROR: Unable to open file.\n");
        exit(0);
    }

    fgets(buffer, MAX_CHARACTERS, filePtr);

    // Extract watermark message
    bitCount = 0;
    len = strlen(buffer);
    memset(message, 0, MAX_CHARACTERS);
    for(i = 0; i < len; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(bitCount >= 8 && k < MAX_CHARACTERS)
            {
                bitCount = 0;
                k++;
            }

            message[k] <<= 1;
            message[k] |= buffer[i] & 1;
            buffer[i] >>= 1;

            bitCount++;
        }
    }

    fclose(filePtr);

    printf("Extracted message: %s\n", message);
}

// Driver code
int main()
{
    char inputFilename[100], message[100];

    // Input file name
    printf("Enter input file name: ");
    scanf("%s", inputFilename);

    // Input message to embed
    printf("\nEnter message to embed: ");
    scanf("%s", message);

    embedMessage(inputFilename, message);

    extractMessage(inputFilename);

    return 0;
}