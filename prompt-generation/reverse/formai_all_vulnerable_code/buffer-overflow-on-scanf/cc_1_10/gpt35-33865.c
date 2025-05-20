//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

void simpleEncrypt(char *message)
//function to encrypt a message using a simple algorithm
{
    int i;
    for(i=0;i<strlen(message);i++)
    {
        if(message[i]>='A' && message[i]<='Z')
            message[i]=(char)(((int)message[i]-65+3)%26+65);
        else if(message[i]>='a' && message[i]<='z')
            message[i]=(char)(((int)message[i]-97+3)%26+97);
    }
    printf("Encrypted message: %s\n",message);
}

void simpleDecrypt(char *message)
//function to decrypt a message encrypted using the simple algorithm
{
    int i;
    for(i=0;i<strlen(message);i++)
    {
        if(message[i]>='A' && message[i]<='Z')
            message[i]=(char)(((int)message[i]-65-3+26)%26+65);
        else if(message[i]>='a' && message[i]<='z')
            message[i]=(char)(((int)message[i]-97-3+26)%26+97);
    }
    printf("Decrypted message: %s\n",message);
}

void keyEncrypt(char *message,int key)
//function to encrypt a message using a key offset
{
    int i;
    for(i=0;i<strlen(message);i++)
    {
        if(message[i]>='A' && message[i]<='Z')
            message[i]=(char)(((int)message[i]-65+key)%26+65);
        else if(message[i]>='a' && message[i]<='z')
            message[i]=(char)(((int)message[i]-97+key)%26+97);
    }
    printf("Encrypted message: %s\n",message);
}

void keyDecrypt(char *message,int key)
//function to decrypt a message encrypted using the key offset
{
    int i;
    for(i=0;i<strlen(message);i++)
    {
        if(message[i]>='A' && message[i]<='Z')
            message[i]=(char)(((int)message[i]-65-key+26)%26+65);
        else if(message[i]>='a' && message[i]<='z')
            message[i]=(char)(((int)message[i]-97-key+26)%26+97);
    }
    printf("Decrypted message: %s\n",message);
}


int main()
{
    char message[200];
    int choice,key;
    printf("Enter the message to encrypt: ");
    scanf("%[^\n]s",message);
    printf("\nChoose the type of Encryption:\n1. Simple Encryption/Decryption\n2. Key Encryption/Decryption\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: simpleEncrypt(message);
                simpleDecrypt(message);
                break;
        case 2: printf("Enter the integer key offset: ");
                scanf("%d",&key);
                keyEncrypt(message,key);
                keyDecrypt(message,key);
                break;
        default: printf("Invalid choice!\n");
    }
    return 0;
}