//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hello, I'm a chatbot, and today I'm going to teach you how to implement a public-key algorithm in C!\n");
    printf("Are you ready to learn? Great! Let's get started.\n");

    // Generate public and private keys
    int p = 61;
    int q = 53;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 17;
    int d = 413;

    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    // Encryption
    printf("\nNow let's encrypt a message. Type in a message (no spaces): ");
    char message[100];
    scanf("%s", message);

    int i = 0;
    int ciphertext[100];
    while (message[i] != '\0') {
        int m = message[i] - 'a';
        int c = 1;
        for (int j = 0; j < e; j++) {
            c = (c * m) % n;
        }
        ciphertext[i] = c;
        i++;
    }
    printf("Encrypted message: ");
    for (int j = 0; j < i; j++) {
        printf("%d ", ciphertext[j]);
    }

    // Decryption
    printf("\n\nTime to decrypt the message. ");

    int plaintext[100];
    for (int j = 0; j < i; j++) {
        int c = ciphertext[j];
        int m = 1;
        for (int k = 0; k < d; k++) {
            m = (m * c) % n;
        }
        plaintext[j] = m + 'a';
    }
    printf("Decrypted message: ");
    for (int j = 0; j < i; j++) {
        printf("%c", plaintext[j]);
    }

    printf("\n\nThat's it! You now know how to implement a public-key algorithm in C.\n");
    printf("Thanks for learning with me today. Have a great day!");
    
    return 0;
}