//FormAI DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *file_name, char *key) {
    FILE *file_ptr = fopen(file_name, "rb");
    FILE *output_file_ptr;
    char output_file_name[100];
    sprintf(output_file_name, "%s.enc", file_name);
    output_file_ptr = fopen(output_file_name, "wb");
    int file_size;
    char buffer[1000];
    int i, j = 0, keylength = strlen(key);
    fseek(file_ptr, 0L, SEEK_END);
    file_size = ftell(file_ptr);
    fseek(file_ptr, 0L, SEEK_SET);
    for (i = 0; i < file_size; i++) {
        if (j == keylength) {
            j = 0;
        }
        fseek(file_ptr, i, SEEK_SET);
        fread(&buffer, 1, 1, file_ptr);
        int encrypted_byte = buffer[0] ^ key[j];
        fwrite(&encrypted_byte, 1, 1, output_file_ptr);
        j++;
    }
    fclose(file_ptr);
    fclose(output_file_ptr);
    printf("File Encrypted Successfully!\n");
}

void decrypt(char *file_name, char *key) {
    FILE *file_ptr = fopen(file_name, "rb");
    FILE *output_file_ptr;
    char output_file_name[100];
    sprintf(output_file_name, "%s.dec", file_name);
    output_file_ptr = fopen(output_file_name, "wb");
    int file_size;
    char buffer[1000];
    int i, j = 0, keylength = strlen(key);
    fseek(file_ptr, 0L, SEEK_END);
    file_size = ftell(file_ptr);
    fseek(file_ptr, 0L, SEEK_SET);
    for (i = 0; i < file_size; i++) {
        if (j == keylength) {
            j = 0;
        }
        fseek(file_ptr, i, SEEK_SET);
        fread(&buffer, 1, 1, file_ptr);
        int decrypted_byte = buffer[0] ^ key[j];
        fwrite(&decrypted_byte, 1, 1, output_file_ptr);
        j++;
    }
    fclose(file_ptr);
    fclose(output_file_ptr);
    printf("File Decrypted Successfully!\n");
}

int main() {
    char file_name[100];
    char key[100];
    int choice = 0;
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter encryption/decryption key: ");
    scanf("%s", key);
    printf("Enter 1 to encrypt or 2 to decrypt file: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            encrypt(file_name, key);
            break;
        case 2:
            decrypt(file_name, key);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}