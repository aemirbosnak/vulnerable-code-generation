//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10000

void encrypt(char *message, char *key)
{
    int i, j, k;
    char encrypted_message[SIZE];
    int key_length = strlen(key);
    int message_length = strlen(message);
    for (i = 0; i < message_length; i++)
    {
        if (isalpha(message[i]))
        {
            message[i] = tolower(message[i]);
        }
    }
    for (i = 0, j = 0; i < message_length; i++)
    {
        if (isalpha(message[i]))
        {
            int ascii_value = message[i] - 97;
            int key_index = ascii_value + key_length;
            encrypted_message[j++] = key[key_index % key_length];
        }
        else
        {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key)
{
    int i, j, k;
    char decrypted_message[SIZE];
    int key_length = strlen(key);
    int encrypted_message_length = strlen(encrypted_message);
    for (i = 0; i < encrypted_message_length; i++)
    {
        if (isalpha(encrypted_message[i]))
        {
            int ascii_value = encrypted_message[i] - 97;
            int key_index = ascii_value - key_length;
            if (key_index < 0)
            {
                key_index += 26;
            }
            decrypted_message[i] = key[key_index];
        }
        else
        {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[encrypted_message_length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main()
{
    char message[SIZE];
    char key[SIZE];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);
    encrypt(message, key);
    printf("\nEncrypted message: %s\n", message);
    printf("Enter encrypted message to decrypt: ");
    scanf("%s", message);
    printf("Enter decryption key: ");
    scanf("%s", key);
    decrypt(message, key);
    return 0;
}