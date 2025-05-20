//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Dennis Ritchie
#include <stdio.h>

void encrypt(char *message, int shift);

int main()
{
    char message[100];
    int shift;

    // getting user input
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the shift key (1-25): ");
    scanf("%d", &shift);

    // validating the shift key
    if (shift < 1 || shift > 25)
    {
        printf("Invalid shift key! The key must be between 1-25\n");
        return 0;
    }

    // calling the encryption function
    encrypt(message, shift);

    // printing the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int shift)
{
    char ch;

    // iterating through each character in the message
    for (int i = 0; message[i] != '\0'; i++)
    {
        ch = message[i];

        // applying the shift key
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + shift;

            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + shift;

            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }
}