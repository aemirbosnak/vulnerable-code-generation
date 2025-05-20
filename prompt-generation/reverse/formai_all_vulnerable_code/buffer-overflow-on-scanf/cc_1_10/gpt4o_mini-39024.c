//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

void caesarCipher(char *input, int shift, char *output) {
    int i;
    char ch;
    for (i = 0; input[i] != '\0'; i++) {
        ch = input[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        output[i] = ch;
    }
    output[i] = '\0';
}

void reverseCipher(char *input, char *output) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        output[i] = input[length - i - 1];
    }
    output[length] = '\0';
}

int main() {
    char message[MAX], encrypted[MAX], decrypted[MAX];
    int shift, choice;

    printf("Enter your message (max length %d): ", MAX - 1);
    fgets(message, MAX, stdin);
    message[strcspn(message, "\n")] = 0; // Remove the newline character

    printf("Choose a cipher method:\n1. Caesar Cipher\n2. Reverse Cipher\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter shift value (1-25): ");
            scanf("%d", &shift);
            if (shift < 1 || shift > 25) {
                printf("Invalid shift value. Exiting.\n");
                return 1;
            }
            caesarCipher(message, shift, encrypted);
            printf("Encrypted message (Caesar): %s\n", encrypted);
            caesarCipher(encrypted, 26 - shift, decrypted); // Decrypting
            printf("Decrypted message (Caesar): %s\n", decrypted);
            break;

        case 2:
            reverseCipher(message, encrypted);
            printf("Encrypted message (Reverse): %s\n", encrypted);
            reverseCipher(encrypted, decrypted); // Decrypting
            printf("Decrypted message (Reverse): %s\n", decrypted);
            break;

        default:
            printf("Invalid choice. Exiting.\n");
            return 1;
    }

    return 0;
}