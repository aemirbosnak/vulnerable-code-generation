//FormAI DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <string.h>

int main(void) {
    char message[100], ch;
    int key, i;

    // Prompt user for message input
    printf("Enter a message to encrypt: ");
    gets(message);

    // Prompt user for secret key
    printf("Enter encryption key: ");
    scanf("%d", &key);

    // Loop through message and encrypt each character
    for (i = 0; message[i] != '\0'; i++) {
        ch = message[i];

        // If input character is lowercase alphabet
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            // If output character is not a lowercase alphabet
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        // If input character is uppercase alphabet
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            // If output character is not a uppercase alphabet
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    for (i = 0; message[i] != '\0'; i++) {
        ch = message[i];

        // If input character is lowercase alphabet
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;

            // If output character is not a lowercase alphabet
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        // If input character is uppercase alphabet
        else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;

            // If output character is not a uppercase alphabet
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }

    // Print decrypted message
    printf("Decrypted message: %s", message);

    return 0;
}