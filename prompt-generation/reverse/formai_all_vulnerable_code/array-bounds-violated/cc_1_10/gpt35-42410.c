//FormAI DATASET v1.0 Category: modern Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[1000], key[1000], cipher[1000], plain_text[1000];
    int sentence_length, key_length, i, j;

    //Get the sentence to encrypt
    printf("Enter a sentence to encrypt: ");
    fgets(sentence, 1000, stdin);
    sentence_length = strlen(sentence);

    //Get the key
    printf("\nEnter the key (must be less than or equal to the sentence length): ");
    fgets(key, 1000, stdin);
    key_length = strlen(key);

    //Remove newlines from input
    if(sentence[sentence_length - 1] == '\n')
    {
        sentence[sentence_length - 1] = '\0';
        sentence_length--;
    }

    if(key[key_length - 1] == '\n')
    {
        key[key_length - 1] = '\0';
        key_length--;
    }

    //Check if key is too long
    if(key_length > sentence_length)
    {
        printf("\nError: Key length is too long\n");
        return 1;
    }

    //Encrypt the sentence
    for(i = 0, j = 0; i < sentence_length; i++, j++)
    {
        if(j == key_length)
        {
            j = 0;
        }

        cipher[i] = (sentence[i] + key[j]) % 26 + 'A';
    }

    cipher[i] = '\0';

    printf("\nEncrypted message: %s\n", cipher);

    //Decrypt the message
    for(i = 0, j = 0; i < sentence_length; i++, j++)
    {
        if(j == key_length)
        {
            j = 0;
        }

        plain_text[i] = (cipher[i] - key[j] + 26) % 26 + 'A';
    }

    plain_text[i] = '\0';

    printf("Decrypted message: %s\n", plain_text);

    return 0;
}