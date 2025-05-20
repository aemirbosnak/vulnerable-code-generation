//FormAI DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char *path, char *key) {
    FILE *file, *temp;
    char tempPath[100];
    char ch;
    int i = 0, j, keyLen = strlen(key);

    // Open the file to read
    file = fopen(path, "r");

    // Get the file name without extension for temporary file
    while (path[i] != '.') {
        tempPath[i] = path[i];
        i++;
    }
    tempPath[i] = '\0';

    // Add extension to the temporary file
    strcat(tempPath, "_temp.txt");

    // Open the temporary file to write the encrypted content
    temp = fopen(tempPath, "w");

    // Read each character from the file and encrypt it
    while ((ch = fgetc(file)) != EOF) {
        for (j = 0; j < keyLen; j++) {
            // XOR each character with corresponding character from key
            ch = ch ^ key[j];
        }
        // Write the encrypted character to the temporary file
        fputc(ch, temp);
    }

    // Close the files
    fclose(file);
    fclose(temp);

    // Rename the temporary file to original file name
    remove(path);
    rename(tempPath, path);

    printf("File encrypted successfully!\n");
}

// Main function
int main() {
    char path[100], key[20];

    printf("Enter file path to encrypt: ");
    scanf("%s", path);

    printf("Enter encryption key (max 20 characters): ");
    scanf("%s", key);

    // Call the encryptFile function
    encryptFile(path, key);

    return 0;
}