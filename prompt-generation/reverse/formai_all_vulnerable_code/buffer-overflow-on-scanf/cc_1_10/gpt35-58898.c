//FormAI DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* message, int key){
    int i=0;
    char ch;
    while(message[i]!='\0'){
        ch = message[i];
        if(islower(ch)){
            ch = (ch+key-97)%26 +97;
            message[i] = ch;
        }
        if(isupper(ch)){
            ch = (ch+key-65)%26 +65;
            message[i] = ch;
        }
        i++;        
    }
}

void decrypt(char* message, int key){
    int i=0;
    char ch;
    while(message[i]!='\0'){
        ch = message[i];
        if(islower(ch)){
            ch = (ch-key+26)%26 +97;
            message[i] = ch;
        }
        if(isupper(ch)){
            ch = (ch-key+26)%26 +65;
            message[i] = ch;
        }
        i++;        
    }
}

int main()
{
    char message[100];
    int key;
    printf("Enter the message to encrypt: ");
    fgets(message,100,stdin);
    printf("Enter the key (between 1 and 25): ");
    scanf("%d",&key);
    encrypt(message,key);
    printf("Encrypted message is: %s",message);
    decrypt(message,key);
    printf("Decrypted message is: %s",message);
    return 0;
}