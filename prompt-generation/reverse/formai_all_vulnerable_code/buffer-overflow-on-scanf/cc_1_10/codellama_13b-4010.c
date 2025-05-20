//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: romantic
// A romantic file encrypter program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_PASSWORD_LENGTH 32

// Struct to store encrypted file information
typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} EncryptedFile;

// Function to encrypt a file
void encryptFile(char* filePath, char* password) {
    // Open the file to encrypt
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s for encryption\n", filePath);
        return;
    }

    // Create a new file to store the encrypted data
    char encryptedFilePath[MAX_FILE_NAME_LENGTH];
    sprintf(encryptedFilePath, "%s.enc", filePath);
    FILE* encryptedFile = fopen(encryptedFilePath, "w");
    if (encryptedFile == NULL) {
        printf("Error: Could not create encrypted file %s\n", encryptedFilePath);
        fclose(file);
        return;
    }

    // Encrypt the file data using the password
    char buffer[1024];
    size_t bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, 1024, file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= password[i % strlen(password)];
        }
        fwrite(buffer, 1, bytesRead, encryptedFile);
    }

    // Close the files
    fclose(file);
    fclose(encryptedFile);
}

// Function to decrypt a file
void decryptFile(char* filePath, char* password) {
    // Open the encrypted file
    FILE* encryptedFile = fopen(filePath, "r");
    if (encryptedFile == NULL) {
        printf("Error: Could not open encrypted file %s for decryption\n", filePath);
        return;
    }

    // Create a new file to store the decrypted data
    char decryptedFilePath[MAX_FILE_NAME_LENGTH];
    sprintf(decryptedFilePath, "%s.dec", filePath);
    FILE* decryptedFile = fopen(decryptedFilePath, "w");
    if (decryptedFile == NULL) {
        printf("Error: Could not create decrypted file %s\n", decryptedFilePath);
        fclose(encryptedFile);
        return;
    }

    // Decrypt the file data using the password
    char buffer[1024];
    size_t bytesRead = 0;
    while ((bytesRead = fread(buffer, 1, 1024, encryptedFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= password[i % strlen(password)];
        }
        fwrite(buffer, 1, bytesRead, decryptedFile);
    }

    // Close the files
    fclose(encryptedFile);
    fclose(decryptedFile);
}

// Main function
int main() {
    // Get the file path and password from the user
    char filePath[MAX_FILE_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter file path: ");
    scanf("%s", filePath);
    printf("Enter password: ");
    scanf("%s", password);

    // Encrypt the file
    encryptFile(filePath, password);

    // Decrypt the file
    decryptFile(filePath, password);

    return 0;
}