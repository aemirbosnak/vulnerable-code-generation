//FormAI DATASET v1.0 Category: File Encyptor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_BUFFER_SIZE 512

void encryptFile(char fileName[]);
void decryptFile(char fileName[]);

int main()
{
    char fileName[MAX_FILENAME_SIZE];
    int choice;

    printf("File Encryption/Decryption\n");
    printf("--------------------------\n");
    printf("Enter filename: ");
    fgets(fileName, MAX_FILENAME_SIZE, stdin);
    fileName[strcspn(fileName, "\n")] = '\0';

    printf("Choose an option:\n");
    printf("1. Encrypt file\n");
    printf("2. Decrypt file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            encryptFile(fileName);
            printf("File has been encrypted successfully.\n");
            break;

        case 2:
            decryptFile(fileName);
            printf("File has been decrypted successfully.\n");
            break;

        default:
            printf("Invalid choice. Program will now exit.\n");
            exit(0);
    }

    return 0;
}

void encryptFile(char fileName[])
{
    FILE *fpIn, *fpOut;
    char buffer[MAX_BUFFER_SIZE], outFileName[MAX_FILENAME_SIZE];
    int i, numRead;

    strcpy(outFileName, fileName);
    strcat(outFileName, ".enc");

    fpIn = fopen(fileName, "rb");
    fpOut = fopen(outFileName, "wb");

    if(fpIn == NULL || fpOut == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    while((numRead = fread(buffer, 1, MAX_BUFFER_SIZE, fpIn)) > 0)
    {
        for(i = 0; i < numRead; i++)
        {
            buffer[i] = ~buffer[i]; // bitwise not operation
        }

        fwrite(buffer, 1, numRead, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);
}

void decryptFile(char fileName[])
{
    FILE *fpIn, *fpOut;
    char buffer[MAX_BUFFER_SIZE], outFileName[MAX_FILENAME_SIZE];
    int i, numRead;

    strncpy(outFileName, fileName, strlen(fileName) - 4);
    outFileName[strlen(fileName) - 4] = '\0';

    fpIn = fopen(fileName, "rb");
    fpOut = fopen(outFileName, "wb");

    if(fpIn == NULL || fpOut == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    while((numRead = fread(buffer, 1, MAX_BUFFER_SIZE, fpIn)) > 0)
    {
        for(i = 0; i < numRead; i++)
        {
            buffer[i] = ~buffer[i];
        }

        fwrite(buffer, 1, numRead, fpOut);
    }

    fclose(fpIn);
    fclose(fpOut);
}