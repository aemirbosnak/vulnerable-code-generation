//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LEN 10

void encrypt(char *input_file, char *output_file, char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if (!input ||!output) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char key_table[256];
    memset(key_table, 0, sizeof(key_table));
    int key_index = 0;
    for (int i = 0; i < KEY_LEN; i++) {
        char c = toupper(key[i]);
        if (isalpha(c)) {
            key_table[c] = key_index++;
        }
    }

    int plaintext;
    while ((plaintext = fgetc(input))!= EOF) {
        if (isalpha(plaintext)) {
            plaintext = toupper(plaintext) - 'A';
            if (plaintext >= 0 && plaintext <= 25) {
                plaintext = key_table[plaintext];
            }
        }
        fputc(plaintext, output);
    }

    fclose(input);
    fclose(output);
    printf("File encrypted successfully!\n");
}

void decrypt(char *input_file, char *output_file, char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if (!input ||!output) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char key_table[256];
    memset(key_table, 0, sizeof(key_table));
    int key_index = 0;
    for (int i = 0; i < KEY_LEN; i++) {
        char c = toupper(key[i]);
        if (isalpha(c)) {
            key_table[c] = key_index++;
        }
    }

    int ciphertext;
    while ((ciphertext = fgetc(input))!= EOF) {
        if (isalpha(ciphertext)) {
            ciphertext = toupper(ciphertext) - 'A';
            if (ciphertext >= 0 && ciphertext <= 25) {
                ciphertext = key_table[ciphertext];
            }
        }
        fputc(ciphertext, output);
    }

    fclose(input);
    fclose(output);
    printf("File decrypted successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage:./encryptor <input file> <output file> <encrypt/decrypt> <key>\n");
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *mode = argv[3];
    char *key = argv[4];

    if (strcmp(mode, "encrypt") == 0) {
        encrypt(input_file, output_file, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(input_file, output_file, key);
    } else {
        printf("Invalid mode. Please enter 'encrypt' or 'decrypt'.\n");
        exit(1);
    }

    return 0;
}