//FormAI DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000

void encrypt(char *message, char *key);
void decrypt(char *message, char *key);

int main()
{
    char message[MAX_LENGTH];
    char key[MAX_LENGTH];
    int choice;
    srand(time(0));
    
    printf("Welcome to the C Encryption program!\n\n");
    printf("Please enter the message you want to encrypt: \n");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Removing newline character
    
    printf("Please enter the encryption key (must be the same length as the message): \n");
    fgets(key, MAX_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Removing newline character
    
    printf("\nPlease choose an option: \n1. Encrypt message\n2. Decrypt message\n");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
            encrypt(message, key);
            printf("\nEncrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("\nDecrypted message: %s\n", message);
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }
    
    return 0;
}

void encrypt(char *message, char *key)
{
    int key_length = strlen(key);
    for (int i = 0; i < strlen(message); i++)
    {
        message[i] = (message[i] + key[i % key_length]) % 128; // Modulus 128 for ASCII encoding
    }
}

void decrypt(char *message, char *key)
{
    int key_length = strlen(key);
    for (int i = 0; i < strlen(message); i++)
    {
        message[i] = (message[i] - key[i % key_length] + 128) % 128; // Modulus 128 for ASCII encoding
    }
}