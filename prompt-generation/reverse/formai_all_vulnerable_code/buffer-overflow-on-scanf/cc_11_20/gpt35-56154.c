//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int key, choice;
    char message[100], encrypted_message[100], decrypted_message[100];

    printf("Welcome to the Cryptography Implementation Program\n");
    printf("Please select an option: \n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the message to encrypt: ");
            scanf("%s", message);
            printf("Enter the key: ");
            scanf("%d", &key);

            // Encryption
            for(int i = 0; message[i] != '\0'; ++i)
            {
                if(message[i] >= 'A' && message[i] <= 'Z')
                {
                    encrypted_message[i] = (message[i] + key - 'A') % 26 + 'A';
                }
                else if(message[i] >= 'a' && message[i] <= 'z')
                {
                    encrypted_message[i] = (message[i] + key - 'a') % 26 + 'a';
                }
            }
            printf("Encrypted message: %s\n", encrypted_message);
            break;

        case 2:
            printf("Enter the encrypted message: ");
            scanf("%s", encrypted_message);
            printf("Enter the key: ");
            scanf("%d", &key);

            // Decryption
            for(int i = 0; encrypted_message[i] != '\0'; ++i)
            {
                if(encrypted_message[i] >= 'A' && encrypted_message[i] <= 'Z')
                {
                    decrypted_message[i] = (encrypted_message[i] - key - 'A' + 26) % 26 + 'A';
                }
                else if(encrypted_message[i] >= 'a' && encrypted_message[i] <= 'z')
                {
                    decrypted_message[i] = (encrypted_message[i] - key - 'a' + 26) % 26 + 'a';
                }
            }
            printf("Decrypted message: %s\n", decrypted_message);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}