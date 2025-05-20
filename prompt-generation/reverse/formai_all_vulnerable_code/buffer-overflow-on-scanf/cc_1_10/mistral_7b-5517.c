//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 100

void generate_key(char key[], int length) {
    int i;
    char current_char;

    if (length == 0) {
        key[0] = '\0';
        return;
    }

    current_char = key[length - 1];
    key[length - 1] = key[length - 2];
    key[length - 2] = current_char ^ 'a';

    generate_key(key, length - 2);
}

void encrypt_string(char input[], char output[], int length) {
    int i;
    char key[MAX_LENGTH];

    if (length == 0) {
        return;
    }

    generate_key(key, length);

    output[0] = input[0] ^ key[0];

    encrypt_string(&input[1], &output[1], length - 1);
}

void decrypt_string(char input[], char output[], int length) {
    int i;
    char key[MAX_LENGTH];

    if (length == 0) {
        return;
    }

    generate_key(key, length);

    output[0] = input[0] ^ key[0];

    decrypt_string(&input[1], &output[1], length - 1);
}

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];
    int length;

    printf("Enter input string: ");
    scanf("%s", input);
    length = strlen(input);

    if (length > MAX_LENGTH) {
        printf("String too long.\n");
        return 1;
    }

    encrypt_string(input, output, length);

    printf("Encrypted string: %s\n", output);

    char decrypted[MAX_LENGTH];
    decrypt_string(output, decrypted, length);

    printf("Decrypted string: %s\n", decrypted);

    return 0;
}