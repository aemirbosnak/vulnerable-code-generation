//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int key_len;
    int mode;
} cipher_t;

void generate_key(cipher_t *cipher, int key_len) {
    char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    cipher->key = (char *) malloc(key_len + 1);
    for (int i = 0; i < key_len; i++) {
        cipher->key[i] = chars[rand() % strlen(chars)];
    }
    cipher->key[key_len] = '\0';
    cipher->key_len = key_len;
}

void encrypt_file(FILE *input, FILE *output, cipher_t *cipher) {
    char buffer[1024];
    int len;
    while ((len = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (int i = 0; i < len; i++) {
            buffer[i] ^= cipher->key[i % cipher->key_len];
        }
        fwrite(buffer, 1, len, output);
    }
}

void decrypt_file(FILE *input, FILE *output, cipher_t *cipher) {
    char buffer[1024];
    int len;
    while ((len = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (int i = 0; i < len; i++) {
            buffer[i] ^= cipher->key[i % cipher->key_len];
        }
        fwrite(buffer, 1, len, output);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 6) {
        printf("Usage: %s [encrypt/decrypt] [input_file] [output_file] [key_length]\n", argv[0]);
        return 1;
    }

    cipher_t cipher;
    cipher.key = NULL;
    cipher.key_len = 0;
    cipher.mode = 0;

    if (strcmp(argv[1], "encrypt") == 0) {
        cipher.mode = 1;
    } else if (strcmp(argv[1], "decrypt") == 0) {
        cipher.mode = 2;
    } else {
        printf("Invalid mode.\n");
        return 1;
    }

    int key_len = atoi(argv[4]);
    generate_key(&cipher, key_len);

    FILE *input = fopen(argv[2], "rb");
    if (input == NULL) {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[3], "wb");
    if (output == NULL) {
        printf("Could not open output file.\n");
        return 1;
    }

    if (cipher.mode == 1) {
        encrypt_file(input, output, &cipher);
    } else if (cipher.mode == 2) {
        decrypt_file(input, output, &cipher);
    }

    fclose(input);
    fclose(output);

    free(cipher.key);
    return 0;
}