//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
    char plaintext[SIZE];
    char ciphertext[SIZE];
    int key;
    int i, j;

    // Get plaintext from user
    printf("Enter plaintext: ");
    fgets(plaintext, SIZE, stdin);

    // Remove newline character from plaintext
    plaintext[strcspn(plaintext, "\n")] = '\0';

    // Get key from user
    printf("Enter key: ");
    scanf("%d", &key);

    // Encrypt plaintext using key
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] + key;
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                ciphertext[i] = ciphertext[i] - 26;
            } else {
                ciphertext[i] = ciphertext[i] + 26;
            }
        } else if (isdigit(ciphertext[i])) {
            ciphertext[i] = ciphertext[i] + 10;
        }
    }

    // Print ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt ciphertext using key
    for (i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] - key;
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                plaintext[i] = plaintext[i] + 26;
            } else {
                plaintext[i] = plaintext[i] - 26;
            }
        } else if (isdigit(plaintext[i])) {
            plaintext[i] = plaintext[i] - 10;
        }
    }

    // Print plaintext
    printf("Plaintext: %s\n", plaintext);

    return 0;
}