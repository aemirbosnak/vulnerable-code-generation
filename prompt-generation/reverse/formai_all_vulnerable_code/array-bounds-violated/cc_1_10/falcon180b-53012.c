//Falcon-180B DATASET v1.0 Category: Encryption ; Style: light-weight
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_KEY_SIZE 50

//Function to encrypt the message
void encrypt(char* message, char* key)
{
    int i, j, k = 0;
    char encrypted_message[MAX_KEY_SIZE];

    for(i=0; message[i]!='\0'; i++)
    {
        if(isalpha(message[i]))
        {
            //Encrypt uppercase characters
            if(isupper(message[i]))
            {
                encrypted_message[k] = (char)(((int)message[i] + (int)key[j]) % 26 + 65);
            }
            //Encrypt lowercase characters
            else
            {
                encrypted_message[k] = (char)(((int)message[i] + (int)key[j]) % 26 + 97);
            }
            j = (j + 1) % strlen(key);
            k++;
        }
        else
        {
            encrypted_message[k] = message[i];
            k++;
        }
    }
    encrypted_message[k] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

//Function to decrypt the message
void decrypt(char* encrypted_message, char* key)
{
    int i, j, k = 0;
    char decrypted_message[MAX_KEY_SIZE];

    for(i=0; encrypted_message[i]!='\0'; i++)
    {
        if(isalpha(encrypted_message[i]))
        {
            //Decrypt uppercase characters
            if(isupper(encrypted_message[i]))
            {
                decrypted_message[k] = (char)(((int)encrypted_message[i] - (int)key[j] + 26) % 26 + 65);
            }
            //Decrypt lowercase characters
            else
            {
                decrypted_message[k] = (char)(((int)encrypted_message[i] - (int)key[j] + 26) % 26 + 97);
            }
            j = (j + 1) % strlen(key);
            k++;
        }
        else
        {
            decrypted_message[k] = encrypted_message[i];
            k++;
        }
    }
    decrypted_message[k] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main()
{
    char message[MAX_KEY_SIZE], key[MAX_KEY_SIZE];
    int i, n;

    //Take message as input from user
    printf("Enter message to encrypt/decrypt: ");
    fgets(message, MAX_KEY_SIZE, stdin);
    n = strlen(message);

    //Remove newline character from message
    message[--n] = '\0';

    //Take key as input from user
    printf("Enter encryption/decryption key: ");
    scanf("%s", key);

    //Encrypt the message using the key
    encrypt(message, key);

    //Decrypt the encrypted message using the same key
    decrypt(message, key);

    return 0;
}