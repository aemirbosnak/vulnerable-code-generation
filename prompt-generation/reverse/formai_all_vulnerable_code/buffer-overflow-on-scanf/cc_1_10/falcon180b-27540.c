//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_SIZE 1000000

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char buffer[MAX_FILE_SIZE];
    int buffer_length;
    int i, j;

    while ((buffer_length = fread(buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        for (i = 0; i < buffer_length; i++) {
            buffer[i] ^= key[i % strlen(key)];
        }
        fwrite(buffer, 1, buffer_length, output_file);
    }
}

void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char buffer[MAX_FILE_SIZE];
    int buffer_length;
    int i;

    while ((buffer_length = fread(buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        for (i = 0; i < buffer_length; i++) {
            buffer[i] ^= key[i % strlen(key)];
        }
        fwrite(buffer, 1, buffer_length, output_file);
    }
}

int main() {
    FILE *input_file, *output_file;
    char key[MAX_KEY_LENGTH];
    int key_length;

    printf("Enter the file name to encrypt:\n");
    scanf("%s", "input.txt");
    printf("Enter the file name to decrypt:\n");
    scanf("%s", "output.txt");

    input_file = fopen("input.txt", "rb");
    output_file = fopen("output.txt", "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    printf("Enter the encryption key:\n");
    scanf("%s", key);
    key_length = strlen(key);

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    printf("Encryption completed.\n");

    input_file = fopen("output.txt", "rb");
    output_file = fopen("input.txt", "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    decrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    printf("Decryption completed.\n");

    return 0;
}