//FormAI DATASET v1.0 Category: modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Encryption function
void encrypt(char *message, int key)
{
    int i = 0;
    char ch;

    while (message[i] != '\0')
    {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if (ch > 'z')
                ch = ch - 'z' + 'a' - 1;

            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if (ch > 'Z')
                ch = ch - 'Z' + 'A' - 1;

            message[i] = ch;
        }

        i++;
    }
}

int main()
{
    char message[MAX_LEN];
    int key;

    printf("Enter the message to encrypt: ");
    fgets(message, MAX_LEN, stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    // Remove newline character from message
    message[strcspn(message, "\n")] = '\0';

    // Call the encryption function
    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}