//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
/*WELCOME TO THE MATRIX*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100 //maximum length of input message
#define KEY_LENGTH 16 //key length should be 16 bytes

/*Function prototypes*/
void encrypt(char *message, char *key); //function to encrypt message 
void decrypt(char *message, char *key); //function to decrypt message 

/*Main function*/
int main()
{
    char message[MAX_LENGTH], key[KEY_LENGTH];
    int choice;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin); //take input message from user
    printf("Enter key (16 bytes): ");
    fgets(key, KEY_LENGTH, stdin); //take input key from user

    printf("Choose an option:\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encrypt(message, key); //encrypt message
            printf("Encrypted message: %s", message);
            break;

        case 2:
            decrypt(message, key); //decrypt message
            printf("Decrypted message: %s", message);
            break;

        default:
            printf("Invalid choice, exiting...\n");
            exit(1);
    }

    return 0;
}

/*Function to encrypt message using key*/
void encrypt(char *message, char *key)
{
    int message_len = strlen(message);
    int key_len = strlen(key);
    int i, j;

    for(i = 0, j = 0; i < message_len; ++i, ++j) {
        if(j == key_len)
            j = 0;

        message[i] = (message[i] + key[j]) % 256; //add corresponding key character to message character mod 256
    }
}

/*Function to decrypt message using key*/
void decrypt(char *message, char *key)
{
    int message_len = strlen(message);
    int key_len = strlen(key);
    int i, j;

    for(i = 0, j = 0; i < message_len; ++i, ++j) {
        if(j == key_len)
            j = 0;

        message[i] = (message[i] - key[j] + 256) % 256; //subtract corresponding key character from message character mod 256
    }
}