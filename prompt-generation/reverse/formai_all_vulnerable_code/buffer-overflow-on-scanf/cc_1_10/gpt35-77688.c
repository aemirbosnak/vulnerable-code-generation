//FormAI DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

void encrypt(FILE* file);

int main()
{
    char file_name[100];
    FILE* file;

    // get file name from user
    printf("Enter file name: ");
    scanf("%s",file_name);

    // open file in read mode
    file = fopen(file_name,"rb");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // encrypt file
    encrypt(file);

    // close file
    fclose(file);

    return 0;
}

void encrypt(FILE* file)
{
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;
    int key = 9; // example key

    // read file contents into buffer
    bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file);

    // perform encryption
    for (int i = 0; i < bytes_read; i++)
    {
        buffer[i] ^= key;
    }

    // seek to beginning of file
    fseek(file, 0, SEEK_SET);

    // write encrypted contents back to file
    fwrite(buffer, sizeof(char), bytes_read, file);

    printf("File encrypted successfully!\n");
}