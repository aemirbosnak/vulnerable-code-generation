//FormAI DATASET v1.0 Category: modern Encryption ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void encrypt(char *str, int key){
    //Encrypt function to encrypt the message using key
    
    int i = 0;
    while(str[i]!='\0'){
        str[i] = str[i] + key;
        i++;
    }
}

void decrypt(char *str, int key){
    //Decrypt function to decrypt the message using key
    
    int i = 0;
    while(str[i]!='\0'){
        str[i] = str[i] - key;
        i++;
    }
}

int main()
{
    char message[1000];
    int key;
    
    printf("Enter message to encrypt: ");
    fgets(message,sizeof(message),stdin);
    
    printf("Enter key: ");
    scanf("%d",&key);
    
    encrypt(message,key); //Encrypting the message
    
    //Printing the encrypted message
    printf("\nEncrypted message: ");
    int i = 0;
    while(message[i]!='\0'){
        printf("%c",message[i]);
        i++;
    }
    
    decrypt(message,key); //Decrypting the message
    
    //Printing the decrypted message
    printf("\nDecrypted message: ");
    i = 0;
    while(message[i]!='\0'){
        printf("%c",message[i]);
        i++;
    }
    
    return 0;
}