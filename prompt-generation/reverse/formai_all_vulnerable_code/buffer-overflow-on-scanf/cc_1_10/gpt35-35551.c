//FormAI DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_NAME 1000
#define MAX_KEY_LENGTH 100

// Function to encrypt the file
void encryptFile(char* filename, char* key) {
    FILE* file = fopen(filename, "rb");

    // Check if the file can be opened
    if (file == NULL) {
        printf("Failed to open file. Please check the file name and try again.\n");
        return;
    }

    // Get length of the file
    fseek(file, 0, SEEK_END);
    long int fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the contents of the file
    char* fileContents = (char*)malloc(fileLength * sizeof(char));

    // Read file contents into buffer
    fread(fileContents, sizeof(char), fileLength, file);

    // Encrypt file contents
    for (int i = 0, j = 0; i < fileLength; ++i, ++j) {
        if (j == MAX_KEY_LENGTH) {
            j = 0;
        }

        fileContents[i] = toupper(fileContents[i]) ^ toupper(key[j]);
    }

    // Get new file name to write the encryted contents
    char* encryptedFileName = (char*)malloc(MAX_FILE_NAME * sizeof(char));
    strcpy(encryptedFileName, "ENCRYPTED-");
    strcat(encryptedFileName, filename);

    // Open new file to write the encrypted contents
    FILE* encryptedFile = fopen(encryptedFileName, "wb");

    // Check if the file can be opened
    if (encryptedFile == NULL) {
        printf("Failed to create encrypted file. Please check if you have the permission to create a file in this directory.\n");
        fclose(file);
        free(fileContents);
        free(encryptedFileName);
        return;
    }

    // Write encrypted contents to file
    fwrite(fileContents, sizeof(char), fileLength, encryptedFile);

    // Clean up
    fclose(file);
    fclose(encryptedFile);
    free(fileContents);
    free(encryptedFileName);

    printf("File successfully encrypted!\n");
}

// Driver program
int main() {
    // Get file name and key from user
    char* filename = (char*)malloc(MAX_FILE_NAME * sizeof(char));
    char* key = (char*)malloc(MAX_KEY_LENGTH * sizeof(char));

    printf("Enter the file name that you want to encrypt: ");
    scanf("%s", filename);
    printf("Enter the key for encryption: ");
    scanf("%s", key);

    // Encrypt file
    encryptFile(filename, key);

    // Clean up
    free(filename);
    free(key);

    return 0;
}