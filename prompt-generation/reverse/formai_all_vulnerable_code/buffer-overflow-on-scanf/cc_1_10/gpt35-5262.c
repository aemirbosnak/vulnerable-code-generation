//FormAI DATASET v1.0 Category: Modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char message[], int key)
{
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    printf("\nEncrypted message: %s", message);
}

void decrypt(char message[], int key)
{
    int i;
    char ch;
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
    printf("\nDecrypted message: %s", message);
}

int main()
{
    char message[1000];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(message, 1000, stdin);
    printf("\nEnter the encryption key: ");
    scanf("%d", &key);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}