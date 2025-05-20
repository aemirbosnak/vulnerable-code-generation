//FormAI DATASET v1.0 Category: File Encyptor ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
#define KEY 7

void encrypt(char* message, int key){
    char ch;
    int i;

    for(i=0; message[i]!='\0'; ++i){
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
}

void decrypt(char* message, int key){
    char ch;
    int i;

    for(i=0; message[i]!='\0'; ++i){
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
}

int main(){
    char message[MAX];
    int choice, key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX, stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Enter your choice:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s", message);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}