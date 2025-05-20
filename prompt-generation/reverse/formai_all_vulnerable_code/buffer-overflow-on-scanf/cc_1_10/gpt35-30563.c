//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILENAME 100
#define MAXKEYLENGTH 32
#define MAXBUFFERLENGTH 1024

// Encrypt the file
void encryptFile(char* filename, char* key) {
    // Generate the output file name
    char encryptedFilename[MAXFILENAME + 5];
    snprintf(encryptedFilename, MAXFILENAME + 5, "%s.enc", filename);

    // Open the input and output files
    FILE* inputFile = fopen(filename, "rb");
    FILE* outputFile = fopen(encryptedFilename, "wb");

    // Generate the encryption key
    int keyLength = strlen(key);
    int keyIndex = 0;

    // Read the file one buffer at a time, encrypting each buffer
    char buffer[MAXBUFFERLENGTH];
    size_t bytesRead = 0;
    while((bytesRead = fread(buffer, sizeof(char), MAXBUFFERLENGTH, inputFile))) {
        // Encrypt the buffer
        for(int i = 0; i < bytesRead; i++) {
            buffer[i] = buffer[i] ^ key[keyIndex];
            keyIndex = (keyIndex + 1) % keyLength;
        }

        // Write the encrypted buffer to the output file
        fwrite(buffer, sizeof(char), bytesRead, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Delete the original file
    remove(filename);

    printf("File encrypted successfully.\n");
}

// Decrypt the file
void decryptFile(char* filename, char* key) {
    // Check if the file is a valid encrypted file
    size_t len = strlen(filename);
    if(len < 5 || strcmp(filename + len - 4, ".enc") != 0) {
        printf("Invalid encrypted file.\n");
        return;
    }

    // Generate the output file name
    char decryptedFilename[MAXFILENAME];
    strncpy(decryptedFilename, filename, len - 4);
    decryptedFilename[len - 4] = '\0';

    // Open the input and output files
    FILE* inputFile = fopen(filename, "rb");
    FILE* outputFile = fopen(decryptedFilename, "wb");

    // Generate the decryption key
    int keyLength = strlen(key);
    int keyIndex = 0;

    // Read the file one buffer at a time, decrypting each buffer
    char buffer[MAXBUFFERLENGTH];
    size_t bytesRead = 0;
    while((bytesRead = fread(buffer, sizeof(char), MAXBUFFERLENGTH, inputFile))) {
        // Decrypt the buffer
        for(int i = 0; i < bytesRead; i++) {
            buffer[i] = buffer[i] ^ key[keyIndex];
            keyIndex = (keyIndex + 1) % keyLength;
        }

        // Write the decrypted buffer to the output file
        fwrite(buffer, sizeof(char), bytesRead, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Delete the encrypted file
    remove(filename);

    printf("File decrypted successfully.\n");
}

int main() {
    char userChoice;
    char filename[MAXFILENAME];
    char key[MAXKEYLENGTH];

    // Display the main menu
    printf("File Encryption/Decryption Program\n");
    printf("----------------------------------\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n\n");

    // Get the user's choice
    printf("Choose an option (1-3): ");
    scanf("%c", &userChoice);
    getchar();

    switch(userChoice) {
        case '1':
            // Get the file name and encryption key from the user
            printf("Enter the file name to encrypt: ");
            fgets(filename, MAXFILENAME, stdin);
            filename[strcspn(filename, "\n")] = '\0'; // Remove newline character
            
            printf("Enter the encryption key: ");
            fgets(key, MAXKEYLENGTH, stdin);
            key[strcspn(key, "\n")] = '\0'; // Remove newline character

            // Encrypt the file
            encryptFile(filename, key);
            break;

        case '2':
            // Get the encrypted file name and decryption key from the user
            printf("Enter the file name to decrypt: ");
            fgets(filename, MAXFILENAME, stdin);
            filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

            printf("Enter the decryption key: ");
            fgets(key, MAXKEYLENGTH, stdin);
            key[strcspn(key, "\n")] = '\0'; // Remove newline character

            // Decrypt the file
            decryptFile(filename, key);
            break;

        case '3':
            // Exit the program
            printf("Exiting program...\n");
            exit(0);
            break;

        default:
            // Invalid choice
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}