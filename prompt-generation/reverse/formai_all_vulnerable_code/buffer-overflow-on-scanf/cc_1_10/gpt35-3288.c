//FormAI DATASET v1.0 Category: Modern Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define ENCRYPTION_KEY 4

void encrypt(char *str)
{
    int i;
    int key = ENCRYPTION_KEY;
    int length = strlen(str);

    for (i = 0; i <= length; i++)
    {
        str[i] = str[i] + key;
    }
}

void decrypt(char *str)
{
    int i;
    int key = ENCRYPTION_KEY;
    int length = strlen(str);

    for (i = 0; i <= length; i++)
    {
        str[i] = str[i] - key;
    }
}

int main()
{
    char message[MAX_LENGTH];
    char encrypted_message[MAX_LENGTH];
    char decrypted_message[MAX_LENGTH];
    int option;

    printf("Welcome to Modern Encryption!\n\n");

    printf("Please enter your message (maximum %d characters):\n", MAX_LENGTH);
    fgets(message, MAX_LENGTH, stdin);

    printf("\nPlease select an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        memcpy(encrypted_message, message, MAX_LENGTH);
        encrypt(encrypted_message);
        printf("Your message has been encrypted: %s\n", encrypted_message);
        break;

    case 2:
        memcpy(decrypted_message, message, MAX_LENGTH);
        decrypt(decrypted_message);
        printf("Your message has been decrypted: %s\n", decrypted_message);
        break;

    default:
        printf("Invalid option. Please try again.\n");
        exit(1);
    }

    return 0;
}