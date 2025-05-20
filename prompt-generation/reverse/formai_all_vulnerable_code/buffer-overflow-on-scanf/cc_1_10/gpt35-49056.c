//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
/*
      __  __           _____   _____              _       
     |  \/  |  ___    |  ___| /  ___|   ___   ___ (_)  ___ 
     | |\/| | / _ \   | |_    \ `--.   / _ \ / __|| | / __|
     | |  | || (_) |  |  _|    `--. \ |  __/| (__ | || (__ 
     |_|  |_| \___/   |_|     /\__/  \___| \___||_| \___|
                                           
    A program that implements a custom message encryption algorithm using C language.
*/

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char* message, int key);
void decrypt(char* message, int key);

int main()
{
    char message[MAX_SIZE];  // declaration of message array with max size of 100 characters
    int key;  // variable to store encryption key

    printf("Enter message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);  // reading message from user input

    printf("Enter encryption key: ");
    scanf("%d", &key);  // reading encryption key from user input

    encrypt(message, key);  

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char* message, int key)
{
    int i;
    int length = strlen(message);

    for (i = 0; i < length; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')  // checking if the character is in lowercase range
        {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';  // applying encryption formula for lowercase characters
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')  // checking if the character is in uppercase range
        {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';  // applying encryption formula for uppercase characters
        }
        else if (message[i] >= '0' && message[i] <= '9')  // checking if the character is a number
        {
            message[i] = (message[i] - '0' + key) % 10 + '0';  // applying encryption formula for numbers
        }
    }
}

void decrypt(char* message, int key)
{
    int i;
    int length = strlen(message);

    for (i = 0; i < length; i++)
    {
        if (message[i] >= 'a' && message[i] <= 'z')  // checking if the character is in lowercase range
        {
            message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';  // applying decryption formula for lowercase characters
        }
        else if (message[i] >= 'A' && message[i] <= 'Z')  // checking if the character is in uppercase range
        {
            message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';  // applying decryption formula for uppercase characters
        }
        else if (message[i] >= '0' && message[i] <= '9')  // checking if the character is a number
        {
            message[i] = (message[i] - '0' - key + 10) % 10 + '0';  // applying decryption formula for numbers
        }
    }
}