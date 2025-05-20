//Gemma-7B DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

int main()
{
    // Declare variables
    char filename[256];
    FILE *fp;
    int file_size = 0;
    char *file_data;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }

    // Get the file size
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for the file data
    file_data = malloc(file_size);
    if (file_data == NULL)
    {
        printf("Error allocating memory.\n");
        fclose(fp);
        return -1;
    }

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