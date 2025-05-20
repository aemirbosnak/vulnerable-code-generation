//FormAI DATASET v1.0 Category: File Encyptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BUFFER_LENGTH 1024

void encrypt(char* buffer, int key)
{
    int i;
    for(i=0; i<strlen(buffer); i++)
    {
        buffer[i] = buffer[i] + key;
    }
}

void decrypt(char* buffer, int key)
{
    int i;
    for(i=0; i<strlen(buffer); i++)
    {
        buffer[i] = buffer[i] - key;
    }
}

void encrypt_file(char* file_name, int key)
{
    FILE* fp;
    char buffer[MAX_BUFFER_LENGTH];

    fp = fopen(file_name, "r+");
    if(fp==NULL)
    {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }

    while(fgets(buffer, MAX_BUFFER_LENGTH, fp))
    {
        encrypt(buffer, key);
        fseek(fp, -strlen(buffer), SEEK_CUR);
        fputs(buffer, fp);
    }

    fclose(fp);
}

void decrypt_file(char* file_name, int key)
{
    FILE* fp;
    char buffer[MAX_BUFFER_LENGTH];

    fp = fopen(file_name, "r+");
    if(fp==NULL)
    {
        printf("Error opening file: %s\n", file_name);
        exit(1);
    }

    while(fgets(buffer, MAX_BUFFER_LENGTH, fp))
    {
        decrypt(buffer, key);
        fseek(fp, -strlen(buffer), SEEK_CUR);
        fputs(buffer, fp);
    }

    fclose(fp);
}

int main()
{
    char file_name[MAX_FILE_NAME_LENGTH];
    int key;

    printf("Enter the file name to encrypt: ");
    scanf("%s", file_name);
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt_file(file_name, key);
    printf("File encrypted successfully!\n");

    printf("Enter the file name to decrypt: ");
    scanf("%s", file_name);
    printf("Enter the decryption key: ");
    scanf("%d", &key);

    decrypt_file(file_name, key);
    printf("File decrypted successfully!\n");

    return 0;
}