//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100
#define KEY 4

// Function to encrypt text using a key
void encrypt(char message[MAX_CHARS], int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
    
        ch = message[i];
        
        //Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
        //Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
    }
}

// Function to decrypt text using a key
void decrypt(char message[MAX_CHARS], int key)
{
    int i;
    char ch;

    for(i = 0; message[i] != '\0'; ++i){
        
        ch = message[i];
        
        //Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
        //Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
    }
}

int main()
{
    char message[MAX_CHARS];
    int choice;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_CHARS, stdin);

    printf("\nSelect an option:\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice){
        
        case 1:
            encrypt(message, KEY);
            printf("\nEncrypted message: %s\n", message);
            break;
            
        case 2:
            decrypt(message, KEY);
            printf("\nDecrypted message: %s\n", message);
            break;
            
        default:
            printf("\nInvalid choice. Please choose 1 or 2.\n");
            break;
    }

    return 0;
}