//FormAI DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 50

void encrypt_file(char* file_name, char* password) {
    FILE* file_ptr = fopen(file_name, "rb+");
    if (file_ptr == NULL) {
        printf("Error opening file %s\n", file_name);
        return;
    }

    // Check file size
    fseek(file_ptr, 0, SEEK_END);
    long file_size = ftell(file_ptr);
    rewind(file_ptr);

    // Generate key from password
    int password_length = strlen(password);
    unsigned char key[password_length];
    for (int i = 0; i < password_length; i++) {
        key[i] = password[i] ^ i;
    }

    // Encrypt file with key
    unsigned char buffer[1024];
    int key_index = 0;
    for (int i = 0; i < file_size; i++) {
        fread(buffer, 1, 1, file_ptr);
        buffer[0] ^= key[key_index];
        fseek(file_ptr, -1, SEEK_CUR);
        fwrite(buffer, 1, 1, file_ptr);
        key_index = (key_index + 1) % password_length;
    }

    fclose(file_ptr);
}

void decrypt_file(char* file_name, char* password) {
    FILE* file_ptr = fopen(file_name, "rb+");
    if (file_ptr == NULL) {
        printf("Error opening file %s\n", file_name);
        return;
    }

    // Check file size
    fseek(file_ptr, 0, SEEK_END);
    long file_size = ftell(file_ptr);
    rewind(file_ptr);

    // Generate key from password
    int password_length = strlen(password);
    unsigned char key[password_length];
    for (int i = 0; i < password_length; i++) {
        key[i] = password[i] ^ i;
    }

    // Decrypt file with key
    unsigned char buffer[1024];
    int key_index = 0;
    for (int i = 0; i < file_size; i++) {
        fread(buffer, 1, 1, file_ptr);
        buffer[0] ^= key[key_index];
        fseek(file_ptr, -1, SEEK_CUR);
        fwrite(buffer, 1, 1, file_ptr);
        key_index = (key_index + 1) % password_length;
    }

    fclose(file_ptr);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter file name: ");
    scanf("%s", file_name);

    printf("Enter password: ");
    scanf("%s", password);

    char choice;
    printf("Enter 'E' to encrypt, 'D' to decrypt: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'E':
            encrypt_file(file_name, password);
            printf("File encrypted successfully.\n");
            break;

        case 'D':
            decrypt_file(file_name, password);
            printf("File decrypted successfully.\n");
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}