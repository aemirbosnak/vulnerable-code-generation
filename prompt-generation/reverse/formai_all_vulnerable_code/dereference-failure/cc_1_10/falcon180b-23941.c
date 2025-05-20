//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 8
#define BLOCK_SIZE 64

typedef struct {
    char key[KEY_SIZE];
    int index;
} vigenere_cipher;

void init_vigenere_cipher(vigenere_cipher* cipher, char* key) {
    int i = 0;
    for(; i < KEY_SIZE; i++) {
        if(isalpha(key[i])) {
            cipher->key[i] = toupper(key[i]);
        } else {
            cipher->key[i] = 'A';
        }
    }
    cipher->index = 0;
}

char encrypt_char(char plaintext, char key) {
    char result = 0;
    if(isalpha(plaintext)) {
        if(isupper(plaintext)) {
            result = (key + plaintext - 65) % 26 + 65;
        } else {
            result = (key + plaintext - 97) % 26 + 97;
        }
    } else {
        result = plaintext;
    }
    return result;
}

void encrypt_block(char* plaintext, int length, vigenere_cipher* cipher) {
    int i = 0;
    for(; i < length; i++) {
        plaintext[i] = encrypt_char(plaintext[i], cipher->key[cipher->index % KEY_SIZE]);
        cipher->index++;
    }
}

void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    vigenere_cipher cipher;
    init_vigenere_cipher(&cipher, key);
    char buffer[BLOCK_SIZE];
    int bytes_read = 0;
    while((bytes_read = fread(buffer, sizeof(char), BLOCK_SIZE, input_file))!= 0) {
        encrypt_block(buffer, bytes_read, &cipher);
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }
}

int main(int argc, char* argv[]) {
    if(argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }
    FILE* input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE* output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }
    char* key = argv[3];
    encrypt_file(input_file, output_file, key);
    fclose(input_file);
    fclose(output_file);
    return 0;
}