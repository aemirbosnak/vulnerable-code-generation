//Falcon-180B DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 256

void encrypt(char *text, char *key)
{
    int i, j, k, n;
    char *cipher = malloc(MAX_TEXT_LENGTH * sizeof(char));

    n = strlen(text);
    for (i = 0, j = 0; i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                cipher[j] = 'A' + ((text[i] - 'A' + key[j % MAX_KEY_LENGTH]) % 26);
            }
            else
            {
                cipher[j] = 'a' + ((text[i] - 'a' + key[j % MAX_KEY_LENGTH]) % 26);
            }
            j++;
        }
        else
        {
            cipher[j] = text[i];
            j++;
        }
    }
    cipher[j] = '\0';

    printf("Encrypted text: %s\n", cipher);
}

void decrypt(char *cipher, char *key)
{
    int i, j, k, n;
    char *text = malloc(MAX_TEXT_LENGTH * sizeof(char));

    n = strlen(cipher);
    for (i = 0, j = 0; i < n; i++)
    {
        if (isalpha(cipher[i]))
        {
            if (isupper(cipher[i]))
            {
                text[j] = 'A' + ((cipher[i] - 'A' - key[j % MAX_KEY_LENGTH] + 26) % 26);
            }
            else
            {
                text[j] = 'a' + ((cipher[i] - 'a' - key[j % MAX_KEY_LENGTH] + 26) % 26);
            }
            j++;
        }
        else
        {
            text[j] = cipher[i];
            j++;
        }
    }
    text[j] = '\0';

    printf("Decrypted text: %s\n", text);
}

int main()
{
    char text[MAX_TEXT_LENGTH], key[MAX_KEY_LENGTH];
    printf("Enter the text to encrypt: ");
    scanf("%[^\n]", text);
    printf("Enter the encryption key (up to %d characters): ", MAX_KEY_LENGTH);
    scanf("%[^\n]", key);

    encrypt(text, key);
    decrypt(text, key);

    return 0;
}