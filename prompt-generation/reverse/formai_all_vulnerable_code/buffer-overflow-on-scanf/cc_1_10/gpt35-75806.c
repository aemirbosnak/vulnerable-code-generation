//FormAI DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100], key[100], encrypted_message[100], decrypted_message[100];
    int i, j, option, length, key_length;

    printf("Welcome to the C Encryption program!\n");
    printf("Enter your message: ");
    fgets(message, 100, stdin);
    printf("Enter your encryption key: ");
    fgets(key, 100, stdin);

    length = strlen(message);
    key_length = strlen(key);

    for (i = 0, j = 0; i < length; i++, j++)
    {
        if (j == key_length)
            j = 0;

        encrypted_message[i] = message[i] + key[j];
    }

    printf("\nYour encrypted message is: ");
    for (i = 0; i < length; i++)
        printf("%c", encrypted_message[i]);

    printf("\n\nWhat would you like to do next?\n");
    printf("1. Decrypt the message.\n");
    printf("2. Exit the program.\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            for (i = 0, j = 0; i < length; i++, j++)
            {
                if (j == key_length)
                    j = 0;

                decrypted_message[i] = encrypted_message[i] - key[j];
            }

            printf("\nYour decrypted message is: ");
            for (i = 0; i < length; i++)
                printf("%c", decrypted_message[i]);
            printf("\n");
            break;
        case 2:
            printf("\nThank you for using the C Encryption program!\n");
            exit(0);
            break;
        default:
            printf("\nInvalid option. Please try again.\n");
            break;
    }

    return 0;
}