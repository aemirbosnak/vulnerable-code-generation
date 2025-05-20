//FormAI DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() {
    char message[100], ch;
    int key, i;

    printf("Enter a message: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    // encryption
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }

    printf("Encrypted message: %s", message);

    // decryption
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        key = key % 26;

        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;

            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }

            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;

            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            message[i] = ch;
        }
    }

    printf("Decrypted message: %s", message);

    return 0;
}