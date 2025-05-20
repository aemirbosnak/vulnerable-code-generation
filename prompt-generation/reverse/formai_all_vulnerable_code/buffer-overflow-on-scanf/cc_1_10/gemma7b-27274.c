//Gemma-7B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024 * 1024

int main()
{
    // Declare variables
    FILE *fp;
    char filename[255];
    int file_size, read_size, write_size;

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file
    fp = fopen(filename, "r+b");

    // Check if the file is open
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Get the file size
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);

    // Print the file size
    printf("File size: %d bytes\n", file_size);

    // Allocate memory for the buffer
    char *buffer = (char *)malloc(file_size);

    // Read the file data
    read_size = fread(buffer, 1, file_size, fp);

    // Print the file data
    printf("File data: \n");
    printf("%s", buffer);

    // Write the file data to a new file
    write_size = fwrite(buffer, 1, read_size, fp);

    // Close the file
    fclose(fp);

    // Free the memory
    free(buffer);

    return 0;
}