//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1024
#define MAX_FILE_NAME_SIZE 256

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
    key[key_size] = '\0';
}

void encrypt_file(char *file_name, char *key) {
    FILE *file;
    FILE *out_file;
    char buffer[1024];
    char encrypted_buffer[1024];
    int key_index = 0;

    file = fopen(file_name, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }

    out_file = fopen("encrypted_file.txt", "w");
    if (!out_file) {
        printf("Error: Could not create file encrypted_file.txt\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            encrypted_buffer[i] = buffer[i] ^ key[key_index];
            key_index = (key_index + 1) % strlen(key);
        }
        fputs(encrypted_buffer, out_file);
    }

    fclose(file);
    fclose(out_file);

    printf("Encrypted file saved as encrypted_file.txt\n");
}

void decrypt_file(char *file_name, char *key) {
    FILE *file;
    FILE *out_file;
    char buffer[1024];
    char decrypted_buffer[1024];
    int key_index = 0;

    file = fopen("encrypted_file.txt", "r");
    if (!file) {
        printf("Error: Could not open file encrypted_file.txt\n");
        exit(1);
    }

    out_file = fopen("decrypted_file.txt", "w");
    if (!out_file) {
        printf("Error: Could not create file decrypted_file.txt\n");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            decrypted_buffer[i] = buffer[i] ^ key[key_index];
            key_index = (key_index + 1) % strlen(key);
        }
        fputs(decrypted_buffer, out_file);
    }

    fclose(file);
    fclose(out_file);

    printf("Decrypted file saved as decrypted_file.txt\n");
}

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter the name of the file to be encrypted: ");
    scanf("%s", file_name);

    printf("Enter the encryption key: ");
    fgets(key, sizeof(key), stdin);

    encrypt_file(file_name, key);
    decrypt_file("encrypted_file.txt", key);

    return 0;
}