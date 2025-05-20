//FormAI DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[100], key;
    int i, choice, len;

    printf("Welcome to the hilarious encryption program!\n\n");

    while(1)
    {
        printf("What would you like to do?\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nEnter a message to encrypt: ");
            scanf("%s", message);
            printf("Enter a key: ");
            scanf(" %c", &key);

            len = strlen(message);

            for(i = 0; i < len; i++)
            {
                message[i] = message[i] ^ key;
            }

            printf("\nEncrypted message: %s\n", message);
        }
        else if(choice == 2)
        {
            printf("\nEnter a message to decrypt: ");
            scanf("%s", message);
            printf("Enter a key: ");
            scanf(" %c", &key);

            len = strlen(message);

            for(i = 0; i < len; i++)
            {
                message[i] = message[i] ^ key;
            }

            printf("\nDecrypted message: %s\n", message);
        }
        else if(choice == 3)
        {
            printf("\nThanks for using the hilarious encryption program!\n");
            break;
        }
        else
        {
            printf("\nThat's not a valid choice! Try again.\n");
        }
    }

    return 0;
}