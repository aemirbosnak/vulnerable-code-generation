//Gemma-7B DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    // Define file pointer
    FILE *fp;

    // Open file in read-write mode
    fp = fopen("my_file.txt", "r+w");

    // Check if file is open
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Allocate memory for buffer
    char *buffer = (char *)malloc(MAX_BUFFER_SIZE);

    // Read data from file
    int read_bytes = fread(buffer, MAX_BUFFER_SIZE, 1, fp);

    // Check if data was read
    if (read_bytes > 0)
    {
        // Print data
        printf("Data read from file:\n");
        printf("%s", buffer);
    }

    // Write data to file
    printf("Enter data to write to file: ");
    scanf("%s", buffer);

    // Write data to file
    int write_bytes = fwrite(buffer, MAX_BUFFER_SIZE, 1, fp);

    // Check if data was written
    if (write_bytes > 0)
    {
        // Print confirmation message
        printf("Data written to file successfully.\n");
    }

    // Close file
    fclose(fp);

    // Free memory
    free(buffer);

    return 0;
}