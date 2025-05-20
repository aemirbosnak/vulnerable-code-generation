//FormAI DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 1000  // Maximum size of encryption message

void encrypt(char message[], int key); // Function to encrypt the message
void decrypt(char message[], int key); // Function to decrypt the message

int main()
{
    char message[MAX_SIZE];
    int key;

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; // Removing the newline character from the fgets input

    printf("Enter the key: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char message[], int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i]; // Assigning the ith character to the variable ch
        
        // Encrypting uppercase characters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z')
                ch = ch - 'Z' + 'A' - 1;  
            message[i] = ch;
        }
        
        // Encrypting lowercase characters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z')
                ch = ch - 'z' + 'a' - 1; 
            message[i] = ch;
        }
    }
}

void decrypt(char message[], int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i]; // Assigning the ith character to the variable ch
        
        // Decrypting uppercase characters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A')
                ch = ch + 'Z' - 'A' + 1;  
            message[i] = ch;
        }
        
        // Decrypting lowercase characters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a')
                ch = ch + 'z' - 'a' + 1; 
            message[i] = ch;
        }
    }
}