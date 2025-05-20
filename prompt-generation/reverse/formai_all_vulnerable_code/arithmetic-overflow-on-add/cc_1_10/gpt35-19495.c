//FormAI DATASET v1.0 Category: Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void encrypt(char message[], int shift);
void decrypt(char message[], int shift);

int main() {
    char message[MAX_STRING_LENGTH];
    int shift;

    printf("Enter a message: ");
    fgets(message, MAX_STRING_LENGTH, stdin);

    printf("Enter a shift (between 1 and 25): ");
    scanf("%d", &shift);

    encrypt(message, shift);
    printf("Encrypted message: %s", message);

    decrypt(message, shift);
    printf("Decrypted message: %s", message);

    return 0;
}

void encrypt(char message[], int shift) {
    int i;
    char ch;

    for (i = 0; message[i] != '\0'; i++) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            // Apply shift to lowercase letters
            ch = ch + shift;

            // Wrap around z to a if necessary
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }

        if (ch >= 'A' && ch <= 'Z') {
            // Apply shift to uppercase letters
            ch = ch + shift;

            // Wrap around Z to A if necessary
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}

void decrypt(char message[], int shift) {
    // Decrypting is just encrypting with the opposite shift
    encrypt(message, -shift);
}