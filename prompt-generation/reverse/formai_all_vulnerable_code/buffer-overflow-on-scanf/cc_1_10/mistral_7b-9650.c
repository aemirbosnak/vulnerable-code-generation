//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY 3

void encrypt(char *message) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = ((message[i] - 65 + KEY) % 26) + 65;
            } else {
                message[i] = ((message[i] - 97 + KEY) % 26) + 97;
            }
        }
    }
}

void decrypt(char *message) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = ((message[i] - 65 - KEY + 26) % 26) + 65;
            } else {
                message[i] = ((message[i] - 97 - KEY + 26) % 26) + 97;
            }
        }
    }
}

int main() {
    char message[100];
    char operation;

    printf("Welcome to SecretMessage!\n");
    printf("Please enter your message: ");
    scanf("%s", message);

    printf("Please enter the operation (E for Encrypt, D for Decrypt): ");
    scanf(" %c", &operation);

    if (operation == 'E' || operation == 'e') {
        encrypt(message);
        printf("Encrypted message: %s\n", message);
    } else if (operation == 'D' || operation == 'd') {
        char decrypted_message[100];
        decrypt(message);
        strcpy(decrypted_message, message);
        printf("Decrypted message: %s\n", decrypted_message);
    } else {
        printf("Invalid operation! Please use E for Encrypt or D for Decrypt.\n");
        return 1;
    }

    return 0;
}