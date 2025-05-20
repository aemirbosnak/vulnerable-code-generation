//Falcon-180B DATASET v1.0 Category: Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char message[], char key[], int key_length)
{
    int i, j, k;
    char ciphertext[MAX_MESSAGE_LENGTH];
    for (i = 0, j = 0; i < strlen(message); i++)
    {
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                ciphertext[j] = ((int)message[i] + key_length - 65) % 26 + 65;
            }
            else
            {
                ciphertext[j] = ((int)message[i] + key_length - 97) % 26 + 97;
            }
        }
        else
        {
            ciphertext[j] = message[i];
        }
        j++;
    }
    ciphertext[j] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char ciphertext[], char key[], int key_length)
{
    int i, j, k;
    char message[MAX_MESSAGE_LENGTH];
    for (i = 0, j = 0; i < strlen(ciphertext); i++)
    {
        if (isalpha(ciphertext[i]))
        {
            if (isupper(ciphertext[i]))
            {
                message[j] = ((int)ciphertext[i] - key_length - 65) % 26 + 65;
            }
            else
            {
                message[j] = ((int)ciphertext[i] - key_length - 97) % 26 + 97;
            }
        }
        else
        {
            message[j] = ciphertext[i];
        }
        j++;
    }
    message[j] = '\0';
    printf("Message: %s\n", message);
}

int main()
{
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int key_length;
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter key to encrypt: ");
    scanf("%s", key);
    key_length = strlen(key);
    encrypt(message, key, key_length);
    printf("Enter key to decrypt: ");
    scanf("%s", key);
    key_length = strlen(key);
    decrypt(message, key, key_length);
    return 0;
}