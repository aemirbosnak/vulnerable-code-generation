//FormAI DATASET v1.0 Category: Modern Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program demonstrates a simple encryption algorithm
 * in C using a retro-style interface.
 */

int main()
{
    char input[100];
    char key[100];
    char encrypted[100];
    int option;
    int i, j;

    srand(time(NULL));

    printf("Welcome to Retro Encryption!\n");
    printf("===========================\n");

    printf("\nChoose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    scanf("%d", &option);

    switch (option) {
        /* Encryption */
        case 1:
            printf("\nEnter a message to encrypt: ");
            scanf("%s", input);

            /* Generate encryption key */
            for (i = 0; i < strlen(input); i++) {
                key[i] = rand() % 26 + 'a';
            }

            /* Encrypt the message */
            for (i = 0; i < strlen(input); i++) {
                encrypted[i] = (((input[i] - 'a') + (key[i] - 'a')) % 26) + 'a';
            }

            /* Print the encrypted message and key */
            printf("\nEncryption successful!\n");
            printf("Encrypted message: %s\n", encrypted);
            printf("Encryption key: %s\n", key);
            break;

        /* Decryption */
        case 2:
            printf("\nEnter an encrypted message: ");
            scanf("%s", encrypted);

            printf("Enter the encryption key: ");
            scanf("%s", key);

            /* Decrypt the message */
            for (i = 0; i < strlen(encrypted); i++) {
                input[i] = (((encrypted[i] - 'a') - (key[i] - 'a') + 26) % 26) + 'a';
            }

            /* Print the decrypted message */
            printf("\nDecryption successful!\n");
            printf("Decrypted message: %s\n", input);
            break;

        default:
            printf("\nInvalid option!\n");
            break;
    }

    return 0;
}