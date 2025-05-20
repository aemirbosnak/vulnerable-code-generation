//FormAI DATASET v1.0 Category: Encryption ; Style: multiplayer
#include<stdio.h>

// Function to convert plaintext to ciphertext using Caesar cipher
void caesar_cipher(char* plaintext, int key)
{
    int i = 0;
    char ch;

    // Iterate through each character in the string
    while(plaintext[i] != '\0')
    {
        ch = plaintext[i];

        // Encrypt uppercase letters using the key
        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;

            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }

            plaintext[i] = ch;
        }

        // Encrypt lowercase letters using the key
        else if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;

            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            plaintext[i] = ch;
        }

        i++;
    }
}

int main()
{
    char plaintext[100];
    int key;

    printf("Enter a string: ");
    fgets(plaintext, 100, stdin);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the plaintext using Caesar cipher
    caesar_cipher(plaintext, key);

    printf("Encrypted text: %s", plaintext);

    return 0;
}