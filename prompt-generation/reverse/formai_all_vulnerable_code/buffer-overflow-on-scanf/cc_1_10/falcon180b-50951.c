//Falcon-180B DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 100
#define MAX_TEXT_LENGTH 1000

void encrypt(char *key, char *text, char *encrypted_text)
{
    int key_length = strlen(key);
    int text_length = strlen(text);

    if (key_length > MAX_KEY_LENGTH || text_length > MAX_TEXT_LENGTH)
    {
        printf("Error: Key or text is too long.\n");
        exit(1);
    }

    int i, j, k;
    for (i = 0, j = 0; i < text_length; i++, j++)
    {
        if (j == key_length)
        {
            j = 0;
        }

        char c = tolower(text[i]);
        if (isalpha(c))
        {
            c = (c + key[j] - 'a' + 26) % 26 + 'a';
        }

        encrypted_text[i] = c;
    }

    encrypted_text[text_length] = '\0';
}

void decrypt(char *key, char *encrypted_text, char *decrypted_text)
{
    int key_length = strlen(key);
    int encrypted_length = strlen(encrypted_text);

    if (key_length > MAX_KEY_LENGTH || encrypted_length > MAX_TEXT_LENGTH)
    {
        printf("Error: Key or encrypted text is too long.\n");
        exit(1);
    }

    int i, j, k;
    for (i = 0, j = 0; i < encrypted_length; i++, j++)
    {
        if (j == key_length)
        {
            j = 0;
        }

        char c = tolower(encrypted_text[i]);
        if (isalpha(c))
        {
            c = (c - key[j] + 26) % 26 + 'a';
        }

        decrypted_text[i] = c;
    }

    decrypted_text[encrypted_length] = '\0';
}

int main()
{
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char encrypted_text[MAX_TEXT_LENGTH];
    char decrypted_text[MAX_TEXT_LENGTH];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the text: ");
    scanf("%s", text);

    encrypt(key, text, encrypted_text);

    printf("Encrypted text: %s\n", encrypted_text);

    decrypt(key, encrypted_text, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}