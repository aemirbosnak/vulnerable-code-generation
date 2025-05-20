//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
// Romeo and Juliet Cryptography Implementation
// By Chatbot

#include <stdio.h>

int main() {
    char message[100], cipher[100];
    int key, choice, i;

    printf("O Romeo, Romeo! wherefore art thou Romeo?\n");

    printf("Enter your message, my sweet Juliet: ");
    fgets(message, sizeof(message), stdin);

    printf("\nChoose thy cipher, dear Juliet:\n");
    printf("1. Caesar Cipher\n2. Vigenere Cipher\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nHow many shifts must our love make, O Romeo? ");
            scanf("%d", &key);

            for (i = 0; message[i] != '\0'; ++i) {
                if (message[i] >= 'a' && message[i] <= 'z') {
                    cipher[i] = 'a' + (message[i] - 'a' + key) % 26;
                }
                else if (message[i] >= 'A' && message[i] <= 'Z') {
                    cipher[i] = 'A' + (message[i] - 'A' + key) % 26;
                }
                else {
                    cipher[i] = message[i];
                }
            }

            printf("\nBehold, our love is now encrypted, Juliet: %s", cipher);
            break;

        case 2:
            printf("\nWhat is thy love token, Romeo? ");
            scanf("%s", &cipher);

            for (i = 0; message[i] != '\0'; ++i) {
                if (message[i] >= 'a' && message[i] <= 'z') {
                    cipher[i] = 'a' + (message[i] - 'a' + cipher[i] - 'a') % 26;
                }
                else if (message[i] >= 'A' && message[i] <= 'Z') {
                    cipher[i] = 'A' + (message[i] - 'A' + cipher[i] - 'a') % 26;
                }
                else {
                    cipher[i] = message[i];
                }

                if (cipher[i] == '\0') {
                    i = -1;
                }
            }

            printf("\nOur love is now encrypted with the Vigenere Cipher, Romeo: %s", cipher);
            break;

        default:
            printf("\nAlas, our love cannot be ciphered in such a fashion.");
            break;
    }

    printf("\nParting is such sweet sorrow, but our love shall now be encoded forevermore.");

    return 0;
}