//FormAI DATASET v1.0 Category: File Backup System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_BUFFER_SIZE 1024

/* Function prototypes */
void copy_file(FILE *source, FILE *dest);
void backup_file(char *filename);

int main()
{
    char input[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", input);
    backup_file(input);

    return 0;
}

void copy_file(FILE *source, FILE *dest)
{
    char buffer[MAX_BUFFER_SIZE];
    size_t numRead;

    while ((numRead = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, source)) > 0)
    {
        fwrite(buffer, sizeof(char), numRead, dest);
    }

    if (ferror(source))
    {
        printf("Error reading from source file");
    }

    if (ferror(dest))
    {
        printf("Error writing to destination file");
    }
}

void backup_file(char *filename)
{
    FILE *source = fopen(filename, "rb");
    if (source == NULL)
    {
        printf("Error opening source file");
        return;
    }

    char destination[MAX_FILE_NAME_LENGTH + 4];
    strcpy(destination, filename);
    strcat(destination, ".bak");

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL)
    {
        printf("Error opening destination file");
        return;
    }

    copy_file(source, dest);

    fclose(source);
    fclose(dest);

    printf("%s successfully backed up as %s\n", filename, destination);
}