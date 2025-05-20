//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "secret_key"
#define BLOCK_SIZE 16

void encrypt(char* plaintext, char* ciphertext) {
    int i, j, k;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = tolower(plaintext[i]);
            ciphertext[j] = plaintext[i] ^ key[i % strlen(key)];
            j++;
        } else {
            ciphertext[j] = plaintext[i];
            j++;
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* plaintext) {
    int i, j, k;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = tolower(ciphertext[i]);
            plaintext[j] = ciphertext[i] ^ key[i % strlen(key)];
            j++;
        } else {
            plaintext[j] = ciphertext[i];
            j++;
        }
    }
    plaintext[j] = '\0';
}

void write_to_file(char* filename, char* data) {
    FILE* file;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    fwrite(data, strlen(data), 1, file);
    fclose(file);
}

void read_from_file(char* filename, char* data) {
    FILE* file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    fread(data, strlen(data), 1, file);
    fclose(file);
}

int main() {
    char filename[50], plaintext[1000], ciphertext[1000];
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    encrypt(plaintext, ciphertext);
    write_to_file(filename, ciphertext);
    printf("Encryption complete.\n");
    printf("Enter the filename: ");
    scanf("%s", filename);
    read_from_file(filename, ciphertext);
    decrypt(ciphertext, plaintext);
    printf("Decryption complete.\n");
    printf("Plaintext: %s\n", plaintext);
    return 0;
}