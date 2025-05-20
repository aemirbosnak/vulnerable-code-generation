//Falcon-180B DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "mysecretkey"
#define KEY_LENGTH 16

void encrypt(char *input, char *output) {
    int i, j, k = 0;
    char key[KEY_LENGTH];
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = KEY[i];
    }
    for (i = 0; input[i]!= '\0'; i++) {
        if (isalpha(input[i])) {
            output[k] = input[i] ^ key[k % KEY_LENGTH];
            k++;
        } else {
            output[k] = input[i];
            k++;
        }
    }
    output[k] = '\0';
}

void decrypt(char *input, char *output) {
    int i, j, k = 0;
    char key[KEY_LENGTH];
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = KEY[i];
    }
    for (i = 0; input[i]!= '\0'; i++) {
        if (isalpha(input[i])) {
            output[k] = input[i] ^ key[k % KEY_LENGTH];
            k++;
        } else {
            output[k] = input[i];
            k++;
        }
    }
    output[k] = '\0';
}

int main() {
    char input[100], output[100];
    printf("Enter text to encrypt: ");
    scanf("%s", input);
    encrypt(input, output);
    printf("Encrypted text: %s\n", output);
    decrypt(output, input);
    printf("Decrypted text: %s\n", input);
    return 0;
}