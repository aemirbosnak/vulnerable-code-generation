//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size = 0;
    char filename[256];
    FILE *file_ptr;
    unsigned int checksum = 0;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file
    file_ptr = fopen(filename, "r");

    // Check if the file is open
    if (file_ptr == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file data
    while (!feof(file_ptr))
    {
        // Read the data from the file
        int read_size = fread(buffer, 1, MAX_BUFFER_SIZE, file_ptr);

        // Update the buffer size
        buffer_size += read_size;

        // Calculate the checksum
        for (int i = 0; i < read_size; i++)
        {
            checksum += (int)buffer[i];
        }
    }

    // Close the file
    fclose(file_ptr);

    // Print the checksum
    printf("The checksum is: %x\n", checksum);

    return 0;
}