//Falcon-180B DATASET v1.0 Category: Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1000
#define MAX_INPUT_SIZE 100000

char key[MAX_KEY_SIZE];
int key_size;

void generate_key(int size) {
    int i;
    for (i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[size] = '\0';
}

void encrypt(char *input, int input_size, char *output) {
    int i;
    for (i = 0; i < input_size; i++) {
        if (isalpha(input[i])) {
            output[i] = input[i] + key[i % key_size];
        } else {
            output[i] = input[i];
        }
    }
}

void decrypt(char *input, int input_size, char *output) {
    int i;
    for (i = 0; i < input_size; i++) {
        if (isalpha(input[i])) {
            output[i] = input[i] - key[i % key_size];
        } else {
            output[i] = input[i];
        }
    }
}

int main() {
    printf("Welcome to the funny encryption program!\n");

    printf("Enter the length of the encryption key: ");
    scanf("%d", &key_size);

    generate_key(key_size);
    printf("Encryption key: %s\n", key);

    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];

    printf("Enter the text to encrypt: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    encrypt(input, strlen(input), output);
    printf("Encrypted text: %s\n", output);

    printf("Enter the encrypted text to decrypt: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    decrypt(input, strlen(input), output);
    printf("Decrypted text: %s\n", output);

    return 0;
}