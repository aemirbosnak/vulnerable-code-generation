//Gemma-7B DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *filename = NULL;
    int file_size = 0;
    FILE *fp = NULL;

    // Allocate memory dynamically for the file name
    filename = malloc(10);

    // Get the file name from the user
    printf("Enter the file name: ");
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

    // Print the file size
    printf("The file size is: %d bytes.\n", file_size);

    // Close the file
    fclose(fp);

    // Free the memory allocated for the file name
    free(filename);

    return 0;
}

int fileSize(FILE *fp)
{
    int file_size = 0;

    // Seek to the end of the file
    fseek(fp, 0L, SEEK_END);

    // Get the file size
    file_size = ftell(fp);

    // Return the file size
    return file_size;
}