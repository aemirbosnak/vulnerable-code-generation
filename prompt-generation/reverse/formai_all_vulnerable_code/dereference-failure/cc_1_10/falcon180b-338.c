//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BLOCK_SIZE 64
#define KEY_SIZE 16

typedef struct {
    char key[KEY_SIZE];
} encryption_key;

void generate_key(encryption_key* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key->key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char* file_path, encryption_key* key) {
    FILE* file = fopen(file_path, "rb");
    if (!file) {
        printf("Error: File not found.\n");
        exit(1);
    }

    FILE* encrypted_file = fopen("encrypted.txt", "wb");
    if (!encrypted_file) {
        printf("Error: Failed to create encrypted file.\n");
        exit(1);
    }

    char buffer[BLOCK_SIZE];
    while (fread(buffer, 1, BLOCK_SIZE, file) > 0) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] = buffer[i] ^ key->key[i % KEY_SIZE];
        }
        fwrite(buffer, 1, BLOCK_SIZE, encrypted_file);
    }

    fclose(file);
    fclose(encrypted_file);
}

void decrypt(char* file_path, encryption_key* key) {
    FILE* file = fopen(file_path, "rb");
    if (!file) {
        printf("Error: File not found.\n");
        exit(1);
    }

    FILE* decrypted_file = fopen("decrypted.txt", "wb");
    if (!decrypted_file) {
        printf("Error: Failed to create decrypted file.\n");
        exit(1);
    }

    char buffer[BLOCK_SIZE];
    while (fread(buffer, 1, BLOCK_SIZE, file) > 0) {
        for (int i = 0; i < BLOCK_SIZE; i++) {
            buffer[i] = buffer[i] ^ key->key[i % KEY_SIZE];
        }
        fwrite(buffer, 1, BLOCK_SIZE, decrypted_file);
    }

    fclose(file);
    fclose(decrypted_file);
}

int main() {
    encryption_key key;
    generate_key(&key);

    char* file_path = "example.txt";
    encrypt(file_path, &key);
    decrypt("encrypted.txt", &key);

    return 0;
}