//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size = MAX_BUFFER_SIZE;

    // Get the file name from the user
    char file_name[256];
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Open the file
    FILE *file = fopen(file_name, "r");

    // If the file is not open, exit
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read the file into the buffer
    int read_size = fread(buffer, 1, buffer_size, file);

    // Close the file
    fclose(file);

    // Encrypt the buffer
    int key = 12;
    for (int i = 0; i < read_size; i++)
    {
        buffer[i] ^= key;
    }

    // Write the encrypted buffer to a new file
    char new_file_name[256];
    printf("Enter the name of the new file: ");
    scanf("%s", new_file_name);

    // Open the new file
    file = fopen(new_file_name, "w");

    // If the file is not open, exit
    if (file == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write the encrypted buffer to the file
    fwrite(buffer, 1, read_size, file);

    // Close the file
    fclose(file);

    // Print a success message
    printf("File encrypted successfully.\n");

    return 0;
}