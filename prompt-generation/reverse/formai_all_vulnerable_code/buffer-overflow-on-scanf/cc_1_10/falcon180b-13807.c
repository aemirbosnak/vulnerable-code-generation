//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define KEY_LEN 12

// Function to encrypt the file
void encryptFile(FILE *file, char *key) {
    unsigned char buffer[1024];
    unsigned char keyBuffer[KEY_LEN];
    int bytesRead;
    int i;

    // Read the file contents into memory
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        // Convert the key to bytes
        for (i = 0; i < strlen(key); i++) {
            keyBuffer[i] = key[i];
        }

        // Encrypt the buffer
        for (i = 0; i < bytesRead; i++) {
            buffer[i] ^= keyBuffer[i % KEY_LEN];
        }

        // Write the encrypted buffer back to the file
        fwrite(buffer, 1, bytesRead, file);
    }
}

// Function to decrypt the file
void decryptFile(FILE *file, char *key) {
    unsigned char buffer[1024];
    unsigned char keyBuffer[KEY_LEN];
    int bytesRead;
    int i;

    // Read the file contents into memory
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        // Convert the key to bytes
        for (i = 0; i < strlen(key); i++) {
            keyBuffer[i] = key[i];
        }

        // Decrypt the buffer
        for (i = 0; i < bytesRead; i++) {
            buffer[i] ^= keyBuffer[i % KEY_LEN];
        }

        // Write the decrypted buffer back to the file
        fwrite(buffer, 1, bytesRead, file);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char mode;

    // Open the input file
    inputFile = fopen("input.txt", "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open the output file
    outputFile = fopen("output.txt", "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Ask the user for the mode (encrypt or decrypt)
    printf("Enter mode (e for encrypt, d for decrypt): ");
    scanf("%c", &mode);

    // Encrypt or decrypt the file
    if (mode == 'e') {
        encryptFile(inputFile, KEY);
        printf("File encrypted successfully.\n");
    } else if (mode == 'd') {
        decryptFile(inputFile, KEY);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid mode.\n");
        exit(1);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}