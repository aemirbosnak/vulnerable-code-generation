//Gemma-7B DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

int main()
{
    FILE *fp;
    char filename[255];
    int file_size;
    char *file_data;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file is open
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get the file size
    file_size = fileSize(fp);

    // Allocate memory for the file data
    file_data = malloc(file_size);

    // Read the file data
    fread(file_data, file_size, 1, fp);

    // Close the file
    fclose(fp);

    // Print the file data
    printf("File data: \n");
    printf("%s", file_data);

    // Free the memory
    free(file_data);

    return 0;
}

int fileSize(FILE *fp)
{
    int file_size = 0;
    int bytes_read = 0;
    char buffer[MAX_FILE_SIZE];

    // While there are still bytes to read, read the file in chunks of MAX_FILE_SIZE bytes
    while (!feof(fp) && bytes_read < file_size)
    {
        bytes_read += fread(buffer, MAX_FILE_SIZE, 1, fp);
        file_size += MAX_FILE_SIZE;
    }

    // Return the file size
    return file_size;
}