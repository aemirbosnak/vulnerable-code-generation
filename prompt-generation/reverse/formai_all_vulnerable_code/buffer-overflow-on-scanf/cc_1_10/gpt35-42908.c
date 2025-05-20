//FormAI DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file recursively
void encryptFile(char *fileName, int key) {
    // Create a buffer to hold the data from the file
    char buffer[1024];

    // Open the file for reading
    FILE *file = fopen(fileName, "r");

    // Check if the file exists
    if (file != NULL) {
        // Create a new file name by appending ".enc" to the original file name
        char *newFileName = malloc(strlen(fileName) + 5);
        strcpy(newFileName, fileName);
        strcat(newFileName, ".enc");

        // Open the new file for writing
        FILE *newFile = fopen(newFileName, "w");

        // Read data from the file and encrypt it
        size_t bytesRead;
        while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
            for (int i = 0; i < bytesRead; i++) {
                // Encrypt the data using the key
                buffer[i] ^= key;
            }
            // Write the encrypted data to the new file
            fwrite(buffer, 1, bytesRead, newFile);
        }

        // Close the files
        fclose(file);
        fclose(newFile);

        // Delete the original file
        remove(fileName);

        // Recursively encrypt the new file
        encryptFile(newFileName, key);

        // Free the dynamically allocated memory
        free(newFileName);
    }
}

int main() {
    // Get the file name and encryption key from the user
    char fileName[256];
    int key;

    printf("Enter the file name: ");
    scanf("%s", fileName);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the file recursively
    encryptFile(fileName, key);

    printf("File successfully encrypted!\n");

    return 0;
}