//Gemma-7B DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define a structure to store file information
    typedef struct File
    {
        char name[256];
        int size;
        FILE *fp;
    } File;

    // Create a file structure
    File file;

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", file.name);

    // Open the file
    file.fp = fopen(file.name, "r");

    // Check if the file is open
    if (file.fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get the file size
    file.size = fileSize(file.fp);

    // Print the file size
    printf("The file size is: %d bytes.\n", file.size);

    // Close the file
    fclose(file.fp);

    return 0;
}

int fileSize(FILE *fp)
{
    int size = 0;
    char buffer[1024];

    // Read the file until there is no more data
    while (fgets(buffer, 1024, fp) != NULL)
    {
        // Add the number of bytes read to the file size
        size += strlen(buffer) + 1;
    }

    // Return the file size
    return size;
}