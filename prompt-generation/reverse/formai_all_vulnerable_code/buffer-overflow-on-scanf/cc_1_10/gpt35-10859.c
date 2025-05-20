//FormAI DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

void encrypt(char* file_path, int key) {
    FILE* original_file = fopen(file_path, "rb");
    if (!original_file) {
        printf("Could not open file %s!", file_path);
        return;
    }

    fseek(original_file, 0, SEEK_END);
    long int file_size = ftell(original_file);
    fseek(original_file, 0, SEEK_SET);

    FILE* encrypted_file = fopen(strcat(file_path, ".enc"), "wb");
    if (!encrypted_file) {
        printf("Could not create encrypted file!");
        return;
    }

    char* buffer = (char*)malloc(file_size);
    fread(buffer, file_size, 1, original_file);

    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= key;
    }

    fwrite(buffer, file_size, 1, encrypted_file);

    fclose(original_file);
    fclose(encrypted_file);
    free(buffer);
}

void decrypt(char* file_path, int key) {
    FILE* encrypted_file = fopen(file_path, "rb");
    if (!encrypted_file) {
        printf("Could not open file %s!", file_path);
        return;
    }

    fseek(encrypted_file, 0, SEEK_END);
    long int file_size = ftell(encrypted_file);
    fseek(encrypted_file, 0, SEEK_SET);

    char* buffer = (char*)malloc(file_size);
    fread(buffer, file_size, 1, encrypted_file);

    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= key;
    }

    FILE* decrypted_file = fopen(strtok(file_path, ".enc"), "wb");
    if (!decrypted_file) {
        printf("Could not create decrypted file!");
        return;
    }

    fwrite(buffer, file_size, 1, decrypted_file);

    fclose(decrypted_file);
    fclose(encrypted_file);
    free(buffer);
}

int main() {
    printf("Welcome to my file encryptor program!\n");
    printf("Would you like to encrypt or decrypt a file? (e/d)\n");

    char choice;
    scanf("%c", &choice);

    printf("Please enter the file path:\n");
    char file_path[100];
    scanf("%s", &file_path);

    printf("Please enter the encryption key (an integer between 0 and 255):\n");
    int key;
    scanf("%d", &key);

    switch (choice) {
        case 'e':
            encrypt(file_path, key);
            printf("The file has been encrypted and saved as %s.enc.\n", file_path);
            break;
        case 'd':
            decrypt(file_path, key);
            printf("The file has been decrypted and saved as %s.\n", strtok(file_path, ".enc"));
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}