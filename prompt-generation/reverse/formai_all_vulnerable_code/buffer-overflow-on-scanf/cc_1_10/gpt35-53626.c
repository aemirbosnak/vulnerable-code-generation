//FormAI DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main()
{
    char message[100];
    char key[100];
    int choice;

    printf("Welcome to the Modern Encryption program!\n");

    do {
        printf("\nWould you like to:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit the program\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the message you want to encrypt: ");
                scanf(" %[^\n]%*c", message);
                printf("Enter the key (must be the same length as the message): ");
                scanf("%s", key);
                encrypt(message, key);
                printf("\nEncrypted message: %s\n", message);
                break;

            case 2:
                printf("\nEnter the message you want to decrypt: ");
                scanf(" %[^\n]%*c", message);
                printf("Enter the key (must be the same length as the message): ");
                scanf("%s", key);
                decrypt(message, key);
                printf("\nDecrypted message: %s\n", message);
                break;

            case 3:
                printf("\nThank you for using the Modern Encryption program! Goodbye.\n");
                exit(0);

            default:
                printf("\nThat is not a valid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

/* Encrypts a message using a given key */
void encrypt(char *message, char *key)
{
    int i;
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[100];

    if (message_length != key_length) {
        printf("The message and key must be the same length for encryption.");
        exit(1);
    }

    for (i=0; i<message_length; i++) {
        encrypted_message[i] = message[i] ^ key[i];
    }

    encrypted_message[i] = '\0';
    strcpy(message, encrypted_message);
}

/* Decrypts a message using a given key */
void decrypt(char *message, char *key)
{
    encrypt(message, key);
}