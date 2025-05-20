//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SHIFT 3 // number of positions to shift the letters

int main() {
    char message[1000], ch;
    int i, choice;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter choice 1 to encrypt, 2 to decrypt: ");
    scanf("%d", &choice);

    // convert message to uppercase
    for (i = 0; message[i] != '\0'; i++) {
        message[i] = toupper(message[i]);
    }

    if (choice == 1) { // encryption process
        for (i = 0; message[i] != '\0'; i++) {
            ch = message[i];

            // ignore non-alphabetic characters
            if (ch < 'A' || ch > 'Z') {
                continue;
            }

            // apply shifting to the letters
            ch = ((ch - 'A') + SHIFT) % 26 + 'A';

            message[i] = ch;
        }

        printf("Encrypted message: %s\n", message);
    }
    else if (choice == 2) { // decryption process
        for (i = 0; message[i] != '\0'; i++) {
            ch = message[i];

            // ignore non-alphabetic characters
            if (ch < 'A' || ch > 'Z') {
                continue;
            }

            // apply reverse shifting to the letters
            ch = ((ch - 'A') - SHIFT + 26) % 26 + 'A';

            message[i] = ch;
        }

        printf("Decrypted message: %s\n", message);
    }
    else { // invalid choice
        printf("Invalid choice!\n");
        return 1;
    }

    return 0;
}