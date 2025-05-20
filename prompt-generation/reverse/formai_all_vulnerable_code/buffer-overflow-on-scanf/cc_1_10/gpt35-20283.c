//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    char message[MAX_SIZE], key[MAX_SIZE], encrypted[MAX_SIZE], decrypted[MAX_SIZE];
    int choice, i;

    // take user input for message and key
    printf("Enter the message: ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter the key: ");
    fgets(key, MAX_SIZE, stdin);

    // remove newline character from user input
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // print menu and take user input for encryption or decryption
    printf("\n1. Encrypt\n2. Decrypt\nEnter your choice: ");
    scanf("%d", &choice);

    // perform encryption or decryption
    switch (choice) {
        case 1:
            // perform encryption
            if (strlen(key) < strlen(message)) {
                printf("\nError: Key length should be at least as long as the message length");
                return 0;
            }
            for (i = 0; i < strlen(message); i++) {
                encrypted[i] = ((message[i] + key[i]) % 26) + 'A';
            }
            encrypted[i] = '\0';

            // print the encrypted message
            printf("\nEncrypted message: %s", encrypted);
            break;
        case 2:
            // perform decryption
            if (strlen(key) < strlen(message)) {
                printf("\nError: Key length should be at least as long as the message length");
                return 0;
            }
            for (i = 0; i < strlen(message); i++) {
                decrypted[i] = ((message[i] - key[i] + 26) % 26) + 'A';
            }
            decrypted[i] = '\0';

            // print the decrypted message 
            printf("\nDecrypted message: %s", decrypted);
            break;
        default:
            printf("\nInvalid choice");
    }

    return 0;
}