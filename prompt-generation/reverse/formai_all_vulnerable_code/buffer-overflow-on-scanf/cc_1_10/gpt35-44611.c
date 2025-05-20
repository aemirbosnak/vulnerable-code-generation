//FormAI DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *msg, int key)
{
    int i;
    for(i = 0; i < strlen(msg); i++)
    {
        msg[i] = msg[i] + key; // Encrypt each character by adding the key
    }
}

void decrypt(char *msg, int key)
{
    int i;
    for(i = 0; i < strlen(msg); i++)
    {
        msg[i] = msg[i] - key; // Decrypt each character by subtracting the key
    }
}

int main()
{
    char message[100];
    int key, choice;

    while(1)
    {
        printf("Enter message to encrypt or decrypt: ");
        fgets(message, 100, stdin);
        message[strcspn(message, "\n")] = '\0'; // Remove newline character from input

        printf("Enter encryption key: ");
        scanf("%d", &key);

        printf("Enter choice 1 for encryption, 2 for decryption: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                encrypt(message, key);
                printf("Encrypted message is: %s\n", message);
                break;
            case 2:
                decrypt(message, key);
                printf("Decrypted message is: %s\n", message);
                break;
            default:
                printf("Invalid choice, please enter 1 or 2.\n");
                break;
        }

        while(getchar() != '\n'); // Flush input buffer before next iteration
    }

    return 0;
}