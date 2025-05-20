//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void encrypt(char[],int);
void decrypt(char[],int);

int main()
{
    char message[100];
    int key, choice;
    
    printf("Welcome to Brave Encryption Program!\n\n");
    printf("Insert message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // remove trailing newline character
    printf("Insert encryption key: ");
    scanf("%d",&key);
    
    printf("\nChoose an option:\n");
    printf("1. Encrypt message\n");
    printf("2. Decrypt message\n");
    printf("Your choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:
            encrypt(message, key);
            printf("\nEncryption complete!\n\n");
            break;
        case 2:
            decrypt(message, key);
            printf("\nDecryption complete!\n\n");
            break;
        default:
            printf("\nInvalid choice\n\n");
    }
    
    return 0;
}

void encrypt(char message[], int key)
{
    int i, ascii;
    char encrypted_message[100];
    
    for(i=0;i<strlen(message);i++)
    {
        ascii = message[i] + key; // shift value by key
        if(message[i] == ' ') // handle space character separately
            encrypted_message[i] = ' ';
        else if(ascii > 122) // loop back to 'a' if needed
            encrypted_message[i] = ascii - 26;
        else if(ascii > 90 && ascii < 97) // ensure only letters are encrypted
            encrypted_message[i] = message[i];
        else if(ascii > 57 && ascii < 65) // ensure only letters and numbers are encrypted
            encrypted_message[i] = message[i];
        else
            encrypted_message[i] = ascii;
    }
    
    printf("\nEncrypted message: %s\n", encrypted_message);
}

void decrypt(char message[], int key)
{
    int i, ascii;
    char decrypted_message[100];
    
    for(i=0;i<strlen(message);i++)
    {
        ascii = message[i] - key; // shift value back by key
        if(message[i] == ' ') // handle space character separately
            decrypted_message[i] = ' ';
        else if(ascii < 65) // loop back to 'Z' if needed
            decrypted_message[i] = ascii + 26;
        else if(ascii > 90 && ascii < 97) // ensure only letters are decrypted
            decrypted_message[i] = message[i];
        else if(ascii > 57 && ascii < 65) // ensure only letters and numbers are decrypted
            decrypted_message[i] = message[i];
        else
            decrypted_message[i] = ascii;
    }
    
    printf("\nDecrypted message: %s\n", decrypted_message);
}