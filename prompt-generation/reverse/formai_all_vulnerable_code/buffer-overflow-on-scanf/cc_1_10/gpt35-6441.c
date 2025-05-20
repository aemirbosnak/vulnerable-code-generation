//FormAI DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

void encryptFile(char* filename, char key)
{
    FILE* inputFile = fopen(filename, "rb");
    if (inputFile == NULL)
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    char outputFilename[MAX_FILENAME_LENGTH];
    sprintf(outputFilename, "%s_encrypted", filename);
    FILE* outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL)
    {
        printf("Error creating output file %s\n", outputFilename);
        return;
    }

    char byte;
    while (fread(&byte, sizeof(char), 1, inputFile))
    {
        byte ^= key; // Encrypt the byte
        fwrite(&byte, sizeof(char), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File %s encrypted and saved as %s\n", filename, outputFilename);
}

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name to encrypt: ");
    scanf("%s", filename);

    char key;
    printf("Enter encryption key: ");
    scanf("%c", &key); // Consume the newline character from previous input
    scanf("%c", &key); // Read the encryption key

    encryptFile(filename, key);
    return 0;
}