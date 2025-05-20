//Falcon-180B DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"

void encrypt(char *input, char *output) {
    int i, j;
    char key[strlen(KEY)];
    int len = strlen(input);

    strcpy(key, KEY);
    for (i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[i] = (key[i % strlen(key)] + input[i]) % 26 + 'A';
            } else {
                output[i] = (key[i % strlen(key)] + input[i]) % 26 + 'a';
            }
        } else {
            output[i] = input[i];
        }
    }
}

void decrypt(char *input, char *output) {
    int i, j;
    char key[strlen(KEY)];
    int len = strlen(input);

    strcpy(key, KEY);
    for (i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            if (isupper(input[i])) {
                output[i] = ((input[i] - key[i % strlen(key)]) % 26 + 26) % 26 + 'A';
            } else {
                output[i] = ((input[i] - key[i % strlen(key)]) % 26 + 26) % 26 + 'a';
            }
        } else {
            output[i] = input[i];
        }
    }
}

int main() {
    char input[100], output[100];
    int choice;

    printf("Enter your message: ");
    scanf("%[^\n]", input);

    printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(input, output);
            printf("Encrypted message: %s\n", output);
            break;
        case 2:
            decrypt(input, output);
            printf("Decrypted message: %s\n", output);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}