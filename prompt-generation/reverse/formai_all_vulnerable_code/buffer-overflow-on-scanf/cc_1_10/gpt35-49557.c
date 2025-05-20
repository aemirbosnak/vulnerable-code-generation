//FormAI DATASET v1.0 Category: File Encyptor ; Style: systematic
#include <stdio.h>

#define KEY 3

void encryptFile(char *filename);
void decryptFile(char *filename);

int main()
{
    char filename[100];
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("Choose an option:\n");
    printf("1. Encrypt the file.\n");
    printf("2. Decrypt the file.\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            encryptFile(filename);
            printf("File encrypted successfully!\n");
            break;
        case 2:
            decryptFile(filename);
            printf("File decrypted successfully!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void encryptFile(char *filename)
{
    FILE *fp = fopen(filename, "rb+");
    unsigned char ch;

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    while(fread(&ch, sizeof(unsigned char), 1, fp) > 0)
    {
        ch = ch + KEY;
        fseek(fp, -1L, SEEK_CUR);
        fwrite(&ch, sizeof(unsigned char), 1, fp);
    }

    fclose(fp);
}

void decryptFile(char *filename)
{
    FILE *fp = fopen(filename, "rb+");
    unsigned char ch;

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    while(fread(&ch, sizeof(unsigned char), 1, fp) > 0)
    {
        ch = ch - KEY;
        fseek(fp, -1L, SEEK_CUR);
        fwrite(&ch, sizeof(unsigned char), 1, fp);
    }

    fclose(fp);
}