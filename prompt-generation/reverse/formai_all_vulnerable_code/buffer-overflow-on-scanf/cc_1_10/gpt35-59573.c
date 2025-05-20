//FormAI DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Function to perform encryption using Caesar Cipher
void encrypt(char message[], int key)
{
    char ch;
    int i;

    // Iterate through each character in the message
    for(i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];

        // Encrypt only alphabets
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if(ch > 'z')
                ch = ch - 'z' + 'a' - 1;

            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if(ch > 'Z')
                ch = ch - 'Z' + 'A' - 1;

            message[i] = ch;
        }
    }
}

int main()
{
    char message[100];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s", message);

    return 0;
}