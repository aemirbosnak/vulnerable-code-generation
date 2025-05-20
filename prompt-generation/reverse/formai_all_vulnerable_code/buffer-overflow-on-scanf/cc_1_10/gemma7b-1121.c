//Gemma-7B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

void handleFile(char *filename)
{
    FILE *fp;
    int fileSize, readSize, data[MAX_FILE_SIZE];
    char *buffer;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);

    // Allocate memory for the buffer
    buffer = malloc(fileSize);

    // Read the file data
    readSize = fread(data, sizeof(int), fileSize, fp);

    // Copy the file data to the buffer
    memcpy(buffer, data, readSize);

    // Print the file data
    printf("File data: \n");
    printf("%s", buffer);

    // Free the memory allocated for the buffer
    free(buffer);

    // Close the file
    fclose(fp);
}

int main()
{
    char filename[256];

    printf("Enter the filename: ");
    scanf("%s", filename);

    handleFile(filename);

    return 0;
}