//Gemma-7B DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

int main()
{
    FILE* filePointer = NULL;
    char buffer[BUFFER_SIZE] = "";
    int readSize = 0;
    int writeSize = 0;
    char input[1024] = "";

    // Open a file in read-write mode
    filePointer = fopen("my_file.txt", "r+w");

    // Check if the file is open
    if (filePointer == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read data from the file
    readSize = fread(buffer, 1, BUFFER_SIZE, filePointer);

    // Check if any data was read
    if (readSize > 0)
    {
        // Print the data
        printf("Data read from the file:\n");
        printf("%s", buffer);
    }

    // Write data to the file
    printf("Enter data to write to the file: ");
    scanf("%s", input);

    // Write the data to the file
    writeSize = fwrite(input, 1, strlen(input) + 1, filePointer);

    // Check if any data was written
    if (writeSize > 0)
    {
        // Print a confirmation message
        printf("Data written to the file:\n");
        printf("%s", input);
    }

    // Close the file
    fclose(filePointer);

    return 0;
}