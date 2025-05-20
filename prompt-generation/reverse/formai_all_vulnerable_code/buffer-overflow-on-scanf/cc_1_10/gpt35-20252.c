//FormAI DATASET v1.0 Category: File Encyptor ; Style: post-apocalyptic
// Post-Apocalyptic Style C File Encryptor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 13 // Caesar Cipher Key

int main()
{
    FILE *file, *encryptedFile;
    char fileName[100], encryptedFileName[100];
    char ch;
    int choice;

    printf("Enter the name of file to encrypt: ");
    scanf("%s", fileName);

    file = fopen(fileName, "r");

    if (file == NULL)
    {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }

    printf("Enter the name of the encrypted file: ");
    scanf("%s", encryptedFileName);

    encryptedFile = fopen(encryptedFileName, "w");

    if (encryptedFile == NULL)
    {
        printf("Error creating encrypted file %s\n", encryptedFileName);
        exit(1);
    }

    printf("Do you want to encrypt or decrypt the file? (1 for encrypt, 2 for decrypt): ");
    scanf("%d", &choice);

    if (choice == 1) // Encrypt File
    {
        while ((ch = fgetc(file)) != EOF)
        {
            ch = ch + KEY;

            fputc(ch, encryptedFile);
        }

        printf("File %s has been encrypted and saved as %s.\n", fileName, encryptedFileName);
    }
    else if (choice == 2) // Decrypt File
    {
        while ((ch = fgetc(file)) != EOF)
        {
            ch = ch - KEY;

            fputc(ch, encryptedFile);
        }

        printf("File %s has been decrypted and saved as %s.\n", fileName, encryptedFileName);
    }
    else // Invalid Choice
    {
        printf("Invalid Choice!\n");
        exit(1);
    }

    fclose(file);
    fclose(encryptedFile);

    return 0;
}