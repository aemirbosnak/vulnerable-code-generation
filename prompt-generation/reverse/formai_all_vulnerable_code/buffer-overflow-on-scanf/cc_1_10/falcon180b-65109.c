//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_KEY_SIZE 32

// Function to generate a random string of given length
char* generateRandomString(int length) {
    char* result = (char*)malloc(length + 1);
    if (!result) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        result[i] = 'A' + rand() % 26;
    }

    result[length] = '\0';
    return result;
}

// Function to encrypt the given file using the given key
void encryptFile(FILE* file, char* key) {
    char buffer[1024];
    char encryptedBuffer[1024];

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            encryptedBuffer[i] = buffer[i] ^ key[i % strlen(key)];
        }

        fputs(encryptedBuffer, stdout);
    }
}

int main() {
    srand(time(NULL));

    // Get the name of the file to encrypt
    char fileName[MAX_FILE_NAME_SIZE];
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", fileName);

    // Open the file for reading
    FILE* inputFile = fopen(fileName, "r");
    if (!inputFile) {
        printf("Error: Could not open file %s\n", fileName);
        exit(1);
    }

    // Generate a random encryption key
    char* key = generateRandomString(MAX_KEY_SIZE);
    printf("Encryption key: %s\n", key);

    // Encrypt the file
    encryptFile(inputFile, key);

    // Close the input file
    fclose(inputFile);

    return 0;
}