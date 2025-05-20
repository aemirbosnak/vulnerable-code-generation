//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message
void encrypt(char *message, int key)
{
    int i;
    char c;

    // Iterate through the message and shift the characters by the key value
    for(i=0; message[i]!='\0'; i++){
        c = message[i];

        if(islower(c)){
            c = ((c - 'a') + key) % 26 + 'a';
        }
        else if(isupper(c)){
            c = ((c - 'A') + key) % 26 + 'A';
        }

        message[i] = c;
    }
}

// Function to decrypt the message
void decrypt(char *message, int key)
{
    int i;
    char c;

    // Iterate through the message and shift the characters back to their original position
    for(i=0; message[i]!='\0'; i++){
        c = message[i];

        if(islower(c)){
            c = ((c - 'a') - key + 26) % 26 + 'a';
        }
        else if(isupper(c)){
            c = ((c - 'A') - key + 26) % 26 + 'A';
        }

        message[i] = c;
    }
}

int main()
{
    char message[100], option;
    int key;

    // Get the message and encryption key from the user
    printf("Enter the message to be encrypted: \n");
    scanf("%[^\n]s", message);

    printf("Enter the encryption key: \n");
    scanf("%d", &key);

    // Encrypt the message and print the encrypted result
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Get the user's option to decrypt the message
    printf("Do you want to decrypt this message? (Y/N): \n");
    scanf(" %c", &option);

    if(option=='Y' || option=='y'){
        // Decrypt the message and print the result
        decrypt(message, key);
        printf("Decrypted message: %s\n", message);
    }

    return 0;
}