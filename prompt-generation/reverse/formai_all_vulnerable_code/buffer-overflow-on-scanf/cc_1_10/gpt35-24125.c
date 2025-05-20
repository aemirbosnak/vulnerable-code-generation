//FormAI DATASET v1.0 Category: File Encyptor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* filename);
void decrypt(char* filename);

void main()
{
    char filename[100];
    int choice;
    printf("Welcome to File Encryptor!\n\n");

    printf("Enter the filename (with extension) to process: ");
    scanf("%s", filename);

    printf("\nSelect an option:\n");
    printf("1. Encrypt the file\n");
    printf("2. Decrypt the file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            encrypt(filename);
            printf("File has been encrypted successfully\n");
            break;
        case 2:
            decrypt(filename);
            printf("File has been decrypted successfully\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

void encrypt(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if(fp == NULL)
    {
        printf("The file could not be opened\n");
        exit(1);
    }

    char key[100];
    printf("Enter the key for encryption: ");
    scanf("%s", key);

    int keyLen = strlen(key), i, j;
    char temp, k;

    fseek(fp, 0, SEEK_END);
    long int fileSize = ftell(fp);
    rewind(fp);

    for(i = 0; i < fileSize; i++)
    {
        if(i % keyLen == 0)
            j = 0;

        fseek(fp, i, SEEK_SET);
        fread(&temp, 1, 1, fp);

        k = key[j];
        temp = temp ^ k;

        fseek(fp, i, SEEK_SET);
        fwrite(&temp, 1, 1, fp);

        j++;
    }

    fclose(fp);
}

void decrypt(char* filename)
{
    FILE* fp = fopen(filename, "rb+");
    if(fp == NULL)
    {
        printf("The file could not be opened\n");
        exit(1);
    }

    char key[100];
    printf("Enter the key for decryption: ");
    scanf("%s", key);

    int keyLen = strlen(key), i, j;
    char temp, k;

    fseek(fp, 0, SEEK_END);
    long int fileSize = ftell(fp);
    rewind(fp);

    for(i = 0; i < fileSize; i++)
    {
        if(i % keyLen == 0)
            j = 0;

        fseek(fp, i, SEEK_SET);
        fread(&temp, 1, 1, fp);

        k = key[j];
        temp = temp ^ k;

        fseek(fp, i, SEEK_SET);
        fwrite(&temp, 1, 1, fp);

        j++;
    }

    fclose(fp);
}