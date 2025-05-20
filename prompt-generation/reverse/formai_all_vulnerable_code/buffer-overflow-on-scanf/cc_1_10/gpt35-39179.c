//FormAI DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Brave-style C Modern Encryption Program

int main()
{
    //Input plaintext to be encrypted
    char plaintext[100];
    printf("Enter the plaintext to be encrypted: ");
    scanf("%[^\n]s", plaintext);

    //Input key for encryption
    char key[100];
    printf("\nEnter the key for encryption: ");
    scanf(" %[^\n]s", key);

    //Remove any whitespace from key
    int i, j;
    for(i = 0, j = 0; key[i]; i++)
    {
        if(key[i] != ' ')
            key[j++] = key[i];
    }
    key[j] = '\0';

    //Calculate length of plaintext and key
    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);

    //Add trailing zeros to key if key length is less than plaintext length
    if(key_length < plaintext_length)
    {
        int difference = plaintext_length - key_length;

        for(i = 0; i < difference; i++)
        {
            key[key_length + i] = '0';
        }
        key[key_length + i] = '\0';
    }

    //Encryption Process
    char encrypted_text[100];
    for(i = 0; i < plaintext_length; i++)
    {
        char encrypted_char = ((plaintext[i] + key[i]) % 26) + 'a';
        encrypted_text[i] = encrypted_char;
    }
    encrypted_text[i] = '\0';

    //Output encrypted text
    printf("\nEncrypted text: %s\n", encrypted_text);

    return 0;
}