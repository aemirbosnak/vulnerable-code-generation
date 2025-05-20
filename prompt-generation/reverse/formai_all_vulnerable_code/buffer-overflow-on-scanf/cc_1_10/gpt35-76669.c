//FormAI DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to encrypt the message
void encrypt(char *message, int key){
    char ch;
    for(int i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key; //Encrypting a lowercase alphabet
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key; //Encrypting a uppercase alphabet
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, int key){
    char ch;
    for(int i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key; //Decrypting a lowercase alphabet
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key; //Decrypting a uppercase alphabet
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
}

int main(){
    char message[1000];
    int key = 0, choice = 0;
    printf("ENTER THE MESSAGE TO BE ENCRYPTED: ");
    fgets(message, 1000, stdin);

    // Generating a random key for encryption and decryption
    srand(time(0));
    key = (rand() % 25) + 1;

    printf("ENTER YOUR CHOICE:\n");
    printf("1: ENCRYPT THE MESSAGE\n");
    printf("2: DECRYPT THE MESSAGE\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            encrypt(message, key);
            printf("\nCIPHER TEXT: %s", message);
            break;
        
        case 2:
            decrypt(message, key);
            printf("\nPLAIN TEXT: %s", message);
            break;

        default:
            printf("\nINVALID CHOICE!!");
            break;
    }
    return 0;
}