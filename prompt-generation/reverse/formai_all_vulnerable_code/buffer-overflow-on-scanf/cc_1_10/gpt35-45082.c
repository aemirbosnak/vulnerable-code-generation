//FormAI DATASET v1.0 Category: Encryption ; Style: Linus Torvalds
/**
 * encrypt.c - An example C program to encrypt a string using
 *             a Caesar Cipher.
 *
 * Author: Linus Torvalds <linus@example.com>
 * Date: January 1, 2022
 */

#include <stdio.h>

/**
 * Encrypts a string using a Caesar Cipher.
 *
 * @param message The string to encrypt
 * @param key The encryption key (a number between 1 and 25)
 * @return The encrypted string
 */
char *encrypt(char *message, int key) {
    int i;
    char ch;
    char *encrypted_message = message;

    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            encrypted_message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            encrypted_message[i] = ch;
        }
        else {
            encrypted_message[i] = ch;
        }
    }

    return encrypted_message;
}

int main() {
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter encryption key (1-25): ");
    scanf("%d", &key);

    char *encrypted_message = encrypt(message, key);

    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}