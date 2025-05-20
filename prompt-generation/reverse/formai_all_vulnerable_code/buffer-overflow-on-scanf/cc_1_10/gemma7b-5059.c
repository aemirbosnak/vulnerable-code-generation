//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Generate a random key
    int key = rand() % 256;

    // Get the file name from the user
    char filename[256];
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file
    FILE *file = fopen(filename, "r");

    // Check if the file is open
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file contents
    char buffer[4096];
    int bytesRead = fread(buffer, 1, 4096, file);

    // Encrypt the file contents
    for (int i = 0; i < bytesRead; i++)
    {
        buffer[i] ^= key;
    }

    // Write the encrypted file contents to a new file
    FILE *newFile = fopen("encrypted.txt", "w");
    fwrite(buffer, 1, bytesRead, newFile);

    // Close the file
    fclose(file);

    // Close the new file
    fclose(newFile);

    // Print a message
    printf("File encrypted successfully.\n");

    return 0;
}