//FormAI DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *message, int key);

int main()
{
    char message[1000], ch;
    int i, key;

    printf("Enter a message to encrypt:\n");
    fgets(message, sizeof(message), stdin);

    printf("Enter key:\n");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int key)
{
    if (*message == '\0')
    {
        return;
    }
    else
    {
        char ch = *message;

        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }

            *message = ch;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            *message = ch;
        }

        encrypt(message + 1, key);
    }
}