//Falcon-180B DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

void encrypt(char *message, int key) {
    int i, j;
    char cipher[MAX_LEN];

    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                cipher[j++] = ((message[i] + key - 65) % 26) + 65;
            } else {
                cipher[j++] = ((message[i] + key - 97) % 26) + 97;
            }
        } else {
            cipher[j++] = message[i];
        }
    }

    cipher[j] = '\0';

    printf("Encrypted message: %s\n", cipher);
}

void decrypt(char *cipher, int key) {
    int i, j;
    char message[MAX_LEN];

    for (i = 0, j = 0; cipher[i]!= '\0'; i++) {
        if (isalpha(cipher[i])) {
            if (isupper(cipher[i])) {
                message[j++] = ((cipher[i] - 65 - key) % 26) + 65;
            } else {
                message[j++] = ((cipher[i] - 97 - key) % 26) + 97;
            }
        } else {
            message[j++] = cipher[i];
        }
    }

    message[j] = '\0';

    printf("Decrypted message: %s\n", message);
}

int main() {
    char message[MAX_LEN];
    int key;

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}