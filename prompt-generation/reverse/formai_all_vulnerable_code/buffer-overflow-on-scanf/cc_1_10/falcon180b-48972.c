//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        if (j == KEY_LENGTH) {
            generate_key(key);
            memset(ciphertext, 0, strlen(ciphertext));
            j = 0;
        }
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[j] = (plaintext[i] - 'A' + rand() % 26) % 26 + 'A';
            } else {
                ciphertext[j] = (plaintext[i] - 'a' + rand() % 26) % 26 + 'a';
            }
        } else {
            ciphertext[j] = plaintext[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ciphertext); i++, j++) {
        if (j == KEY_LENGTH) {
            generate_key(key);
            memset(plaintext, 0, strlen(plaintext));
            j = 0;
        }
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                plaintext[j] = (ciphertext[i] - 'A' - rand() % 26 + 26) % 26 + 'A';
            } else {
                plaintext[j] = (ciphertext[i] - 'a' - rand() % 26 + 26) % 26 + 'a';
            }
        } else {
            plaintext[j] = ciphertext[i];
        }
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[1000];
    char ciphertext[1000];
    char key[KEY_LENGTH + 1];
    FILE* input_file;
    FILE* output_file;

    printf("Enter the name of the input file: ");
    scanf("%s", plaintext);
    input_file = fopen(plaintext, "r");

    if (input_file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    printf("Enter the name of the output file: ");
    scanf("%s", ciphertext);
    output_file = fopen(ciphertext, "w");

    if (output_file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    generate_key(key);

    char buffer[BLOCK_SIZE + 1];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, BLOCK_SIZE, input_file)) > 0) {
        encrypt(buffer, key, buffer);
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}