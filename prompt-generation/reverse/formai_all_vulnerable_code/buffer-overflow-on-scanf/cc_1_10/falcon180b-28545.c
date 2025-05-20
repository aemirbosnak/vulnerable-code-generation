//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

// Function to encrypt a block of data using XOR operation
void encryptBlock(char *block, int size)
{
    char key[strlen(KEY)];
    strcpy(key, KEY);

    for (int i = 0; i < size; i++)
    {
        block[i] ^= key[i % strlen(KEY)];
    }
}

// Function to decrypt a block of data using XOR operation
void decryptBlock(char *block, int size)
{
    char key[strlen(KEY)];
    strcpy(key, KEY);

    for (int i = 0; i < size; i++)
    {
        block[i] ^= key[i % strlen(KEY)];
    }
}

int main()
{
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];
    char block[BLOCK_SIZE];
    int fileSize;

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open input and output files
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL)
    {
        printf("Error opening input file\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL)
    {
        printf("Error opening output file\n");
        fclose(inputFile);
        exit(1);
    }

    // Get file size
    fseek(inputFile, 0, SEEK_END);
    fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    // Encrypt file contents
    char *buffer = (char *)malloc(BLOCK_SIZE);
    int bytesRead;
    while ((bytesRead = fread(buffer, 1, BLOCK_SIZE, inputFile))!= 0)
    {
        encryptBlock(buffer, bytesRead);
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    // Clean up and close files
    free(buffer);
    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully\n");

    return 0;
}