//Falcon-180B DATASET v1.0 Category: Encryption ; Style: standalone
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 26

char alphabet[SIZE] = "abcdefghijklmnopqrstuvwxyz";
char reverse_alphabet[SIZE] = "zyxwvutsrqponmlkjihgfedcba";

void encrypt(char* message, char* key)
{
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[message_length];
    int i, j;

    for(i=0; i<message_length; i++)
    {
        if(isalpha(message[i]))
        {
            int position = (int)message[i] - 97; // Converting the character to its corresponding position in the alphabet array
            int key_position = (int)key[i%key_length] - 97; // Converting the character in the key to its corresponding position in the alphabet array
            position = (position - key_position + 26) % 26; // Encrypting the character using the key

            encrypted_message[i] = alphabet[position];
        }
        else
        {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key)
{
    int message_length = strlen(message);
    int key_length = strlen(key);
    char decrypted_message[message_length];
    int i, j;

    for(i=0; i<message_length; i++)
    {
        if(isalpha(message[i]))
        {
            int position = (int)message[i] - 97; // Converting the character to its corresponding position in the alphabet array
            int key_position = (int)key[i%key_length] - 97; // Converting the character in the key to its corresponding position in the alphabet array
            position = (position + key_position - 1) % 26; // Decrypting the character using the key

            decrypted_message[i] = reverse_alphabet[position];
        }
        else
        {
            decrypted_message[i] = message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main()
{
    char message[100] = "Hello World!";
    char key[100] = "secret";

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}