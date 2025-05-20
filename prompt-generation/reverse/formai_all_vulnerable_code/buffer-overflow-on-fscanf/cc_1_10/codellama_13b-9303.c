//Code Llama-13B DATASET v1.0 Category: File handling ; Style: enthusiastic
/*
 * This program demonstrates how to read and write files in C.
 * It is a unique file handling example program written in an enthusiastic style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100

int main()
{
    // Declare variables
    FILE *file_ptr;
    char file_name[MAX_FILE_NAME];
    char file_content[MAX_FILE_NAME];

    // Get file name from user
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the file in write mode
    file_ptr = fopen(file_name, "w");

    // Check if file opened successfully
    if (file_ptr == NULL)
    {
        printf("Error! Unable to open file.\n");
        return 1;
    }

    // Write data to file
    fprintf(file_ptr, "Welcome to the file handling example program!\n");
    fprintf(file_ptr, "This program demonstrates how to read and write files in C.\n");
    fprintf(file_ptr, "It is a unique file handling example program written in an enthusiastic style.\n");
    fprintf(file_ptr, "Enjoy the program!\n");

    // Close the file
    fclose(file_ptr);

    // Open the file in read mode
    file_ptr = fopen(file_name, "r");

    // Check if file opened successfully
    if (file_ptr == NULL)
    {
        printf("Error! Unable to open file.\n");
        return 1;
    }

    // Read data from file
    fscanf(file_ptr, "%s", file_content);

    // Print the file content
    printf("%s", file_content);

    // Close the file
    fclose(file_ptr);

    // Success message
    printf("File handling example program completed successfully!\n");

    return 0;
}