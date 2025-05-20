//FormAI DATASET v1.0 Category: File Encyptor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024

int main()
{
    char file_name[MAX_FILE_NAME_LENGTH], file_contents[MAX_FILE_SIZE];
    FILE *file_pointer;

    printf("Enter the file name you want to encrypt: ");
    scanf("%s", file_name);

    file_pointer = fopen(file_name, "rb");
    if(file_pointer == NULL)
    {
        printf("File not found.\n");
        return 0;
    }

    int file_size = fread(file_contents, 1, MAX_FILE_SIZE, file_pointer);
    fclose(file_pointer);

    if(file_size == 0)
    {
        printf("Failed to read file.\n");
        return 0;
    }

    char key[8];
    printf("Enter the encryption key (8 characters): ");
    scanf("%s", key);

    if(strlen(key) != 8)
    {
        printf("Invalid key length.\n");
        return 0;
    }

    for(int i=0; i<file_size; i++)
    {
        file_contents[i] ^= key[i%8];
    }

    // Append the encrypted data to a copy of the original file
    strcat(file_name, ".enc");
    file_pointer = fopen(file_name, "wb");
    fwrite(file_contents, 1, file_size, file_pointer);
    fclose(file_pointer);

    printf("Encryption successful!\n");
    return 0;
}