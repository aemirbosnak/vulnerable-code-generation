//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x5A // Example encryption key, can be any value!

void encryptDecryptFile(const char *filePath) {
    FILE *file = fopen(filePath, "rb+");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read the entire file into a buffer
    unsigned char *buffer = (unsigned char *)malloc(fileSize);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    
    fread(buffer, 1, fileSize, file);
    
    // Encrypt/Decrypt the buffer
    for (long i = 0; i < fileSize; i++) {
        buffer[i] ^= KEY; // XOR operation
    }
    
    // Rewind the file pointer and write the modified content back
    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, fileSize, file);
    
    // Cleanup
    fclose(file);
    free(buffer);

    printf("File '%s' has been successfully encrypted/decrypted!\n", filePath);
}

void displayMenu() {
    printf("\n--- File Encryptor / Decryptor ---\n");
    printf("1. Encrypt/Decrypt a file\n");
    printf("2. Exit\n");
    printf("------------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    while (1) {
        displayMenu();
        
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            char filePath[256];
            printf("Enter the file path: ");
            scanf("%s", filePath);
            encryptDecryptFile(filePath);
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}