//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define SIZE 1000 // Maximum buffer size for the message input

// Function to encrypt the message
void encrypt(char *msg, int len, int key)
{
    for (int i = 0; i < len; i++)
    {
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = (msg[i] + key - 'a') % 26 + 'a';
        }
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = (msg[i] + key - 'A') % 26 + 'A';
        }
    }
}

// Function to decrypt the message
void decrypt(char *msg, int len, int key)
{
    for (int i = 0; i < len; i++)
    {
        if (msg[i] >= 'a' && msg[i] <= 'z')
        {
            msg[i] = (msg[i] - key - 'a' + 26) % 26 + 'a';
        }
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
        {
            msg[i] = (msg[i] - key - 'A' + 26) % 26 + 'A';
        }
    }
}

int main()
{
    printf("Welcome to the CyberCrypt C implementation.\n");

    char message[SIZE];
    int key;
    int choice;
    int length = 0;

    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Encrypt message\n");
        printf("2. Decrypt message\n");
        printf("3. Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter message to encrypt: ");
            getchar(); // clear the input buffer
            fgets(message, sizeof(message), stdin);
            length = strlen(message) - 1; // Exclude the newline character from the length
            printf("Enter key: ");
            scanf("%d", &key);
            encrypt(message, length, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            printf("Enter message to decrypt: ");
            getchar(); // clear the input buffer
            fgets(message, sizeof(message), stdin);
            length = strlen(message) - 1; // Exclude the newline character from the length
            printf("Enter key: ");
            scanf("%d", &key);
            decrypt(message, length, key);
            printf("Decrypted message: %s\n", message);
            break;
        case 3:
            printf("Exiting program...\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return EXIT_SUCCESS;
}