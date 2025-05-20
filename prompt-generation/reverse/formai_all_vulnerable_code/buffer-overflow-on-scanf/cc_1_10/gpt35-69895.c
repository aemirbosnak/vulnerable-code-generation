//FormAI DATASET v1.0 Category: Modern Encryption ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to perform encryption
char* encrypt(char* message, int key)
{
    int len = strlen(message);
    char* encrypted = (char*)malloc((len+1)*sizeof(char));
    
    for(int i=0; i<len; i++)
    {
        char ch = message[i];
        // encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z')
        {
            ch = (((ch-'A')+key)%26)+'A';
        }
        // encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z')
        {
            ch = (((ch-'a')+key)%26)+'a';
        }
        encrypted[i] = ch;
    }
    encrypted[len] = '\0';
    return encrypted;
}

// function to perform decryption
char* decrypt(char* message, int key)
{
    int len = strlen(message);
    char* decrypted = (char*)malloc((len+1)*sizeof(char));
    
    for(int i=0; i<len; i++)
    {
        char ch = message[i];
        // decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z')
        {
            ch = (((ch-'A')-key+26)%26)+'A';
        }
        // decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z')
        {
            ch = (((ch-'a')-key+26)%26)+'a';
        }
        decrypted[i] = ch;
    }
    decrypted[len] = '\0';
    return decrypted;
}

int main()
{
    printf("Welcome to the Modern Encryption program!\n");
    printf("----------------------------------------\n\n");
  
    char message[100], choice;
    int key;
    
    do
    {
        printf("Enter a message to encrypt: ");
        gets(message);
        printf("Enter a key to encrypt the message: ");
        scanf("%d", &key);
        
        char* encrypted = encrypt(message, key);
        printf("\nEncrypted message: %s\n\n", encrypted);
        
        char* decrypted = decrypt(encrypted, key);
        printf("Decrypted message: %s\n\n", decrypted);
        
        free(encrypted);
        free(decrypted);
        
        printf("Do you want to continue? (Y/N): ");
        fflush(stdin);
        scanf("%c", &choice);
        printf("\n");
    } while (choice == 'Y' || choice == 'y');
    
    printf("Thank you for using the Modern Encryption program!\n");
    printf("-------------------------------------------------\n");
    
    return 0;
}