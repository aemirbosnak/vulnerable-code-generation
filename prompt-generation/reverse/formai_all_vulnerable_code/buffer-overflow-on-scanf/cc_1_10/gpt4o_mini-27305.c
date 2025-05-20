//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_KEY_SIZE 256

void encrypt_decrypt_file(const char *filename, const char *key, int encrypt) {
    FILE *file;
    unsigned char ch;
    size_t key_length = strlen(key);
    size_t key_index = 0;

    file = fopen(filename, "rb+");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    while (fread(&ch, sizeof(unsigned char), 1, file) == 1) {
        ch ^= key[key_index]; // XOR encryption/decryption
        fseek(file, -1, SEEK_CUR); // Move back to the last byte
        fwrite(&ch, sizeof(unsigned char), 1, file);
        
        key_index = (key_index + 1) % key_length; // Loop through the key
    }
    fclose(file);
    printf("%s operation completed successfully.\n", encrypt ? "Encryption" : "Decryption");
}

int main() {
    char filename[MAX_FILENAME_SIZE];
    char key[MAX_KEY_SIZE];
    int choice;

    printf("File Encryptor/Decryptor\n");
    printf("===========================\n");
    printf("Enter the filename (with extension): ");
    scanf("%s", filename);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt_decrypt_file(filename, key, 1);
            break;
        case 2:
            encrypt_decrypt_file(filename, key, 0);
            break;
        default:
            fprintf(stderr, "Invalid choice\n");
            exit(EXIT_FAILURE);
    }

    return 0;
}