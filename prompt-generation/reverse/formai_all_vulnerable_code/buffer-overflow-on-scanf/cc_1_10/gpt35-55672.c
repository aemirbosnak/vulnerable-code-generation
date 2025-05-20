//FormAI DATASET v1.0 Category: Modern Encryption ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//Function to encrypt the string
void encrypt(char *message, int key){
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

//Function to decrypt the string
void decrypt(char *message, int key){
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

//Function to generate a random key
int generateKey(){
    int key;
    srand(time(0));
    key = rand() % 25 + 1;
    return key;
}

int main(){
    char message[100];
    int key, choice;
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            key = generateKey();
            encrypt(message, key);
            printf("\nEncrypted message: %s\n", message);
            printf("Key: %d\n", key);
            break;
        case 2:
            printf("Enter the key: ");
            scanf("%d", &key);
            decrypt(message, key);
            printf("\nDecrypted message: %s\n", message);
            break;
        default:
            printf("Invalid option!\n");
    }
    return 0;
}