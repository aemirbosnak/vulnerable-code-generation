//Falcon-180B DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 2

// Function to encrypt/decrypt the message
void encrypt_decrypt(char *message, int mode, int key) {
    int i, j, k;
    char ch;

    for (i = 0; message[i]!= '\0'; i++) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 26;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 26;
            }
        }

        if (mode == ENCRYPT) {
            message[i] = ch;
        } else {
            message[i] = ch - key;
        }
    }
}

int main() {
    char message[100], key;
    int mode;

    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    printf("Enter the mode (1 for encryption, 2 for decryption): ");
    scanf("%d", &mode);

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt_decrypt(message, mode, key);

    printf("Encrypted/Decrypted message: %s\n", message);

    return 0;
}