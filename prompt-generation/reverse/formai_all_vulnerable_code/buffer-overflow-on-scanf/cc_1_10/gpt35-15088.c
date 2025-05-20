//FormAI DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50
#define MAX_BUFFER_SIZE 10000

void encrypt(char* filename, char* key);
void decrypt(char* filename, char* key);

int main()
{
    char filename[MAX_FILENAME_LEN], key[MAX_FILENAME_LEN], choice;

    printf("Enter file name (with extension): ");
    scanf("%s", filename);

    printf("Enter encryption/decryption key: ");
    scanf("%s", key);

    printf("Do you want to encrypt or decrypt (e/d)? ");
    scanf(" %c", &choice);

    switch (choice)
    {
        case 'e': encrypt(filename, key);
                  break;

        case 'd': decrypt(filename, key);
                  break;

        default: printf("Invalid choice!\n");
                 exit(0);
    }

    return 0;
}

void encrypt(char* filename, char* key)
{
    char buffer[MAX_BUFFER_SIZE];
    int file_size, key_size, i, j;

    FILE* fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Unable to open file %s!\n", filename);
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    FILE* fp_encrypted = fopen(strcat(filename, ".enc"), "wb");
    if (fp_encrypted == NULL)
    {
        printf("Unable to create encrypted file!\n");
        exit(0);
    }

    key_size = strlen(key);

    for (i = 0, j = 0; i < file_size; ++i, ++j)
    {
        if (j == key_size)
            j = 0;

        fread(&buffer[i], 1, 1, fp);
        buffer[i] = buffer[i] + key[j];
        fwrite(&buffer[i], 1, 1, fp_encrypted);
    }

    fclose(fp);
    fclose(fp_encrypted);

    printf("File %s encrypted successfully.\n", filename);
}

void decrypt(char* filename, char* key)
{
    char buffer[MAX_BUFFER_SIZE];
    int file_size, key_size, i, j;

    if (strstr(filename, ".enc") == NULL)
    {
        printf("Invalid file format (%s).\n", filename);
        exit(0);
    }

    FILE* fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Unable to open file %s!\n", filename);
        exit(0);
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    filename[strlen(filename) - 4] = '\0';

    FILE* fp_decrypted = fopen(filename, "wb");
    if (fp_decrypted == NULL)
    {
        printf("Unable to create decrypted file!\n");
        exit(0);
    }

    key_size = strlen(key);

    for (i = 0, j = 0; i < file_size; ++i, ++j)
    {
        if (j == key_size)
            j = 0;

        fread(&buffer[i], 1, 1, fp);
        buffer[i] = buffer[i] - key[j];
        fwrite(&buffer[i], 1, 1, fp_decrypted);
    }

    fclose(fp);
    fclose(fp_decrypted);

    printf("File %s decrypted successfully.\n", filename);
}