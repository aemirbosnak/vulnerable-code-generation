//FormAI DATASET v1.0 Category: Modern Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function for encrypting the message
void encrypt(char message[], int key) {
    int i;
    for(i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    printf("\nEncrypted message: %s", message);
}

// function for decrypting the message
void decrypt(char message[], int key) {
    int i;
    for(i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
    }
    printf("\nDecrypted message: %s", message);
}

int main() {
    char message[1000];
    int key, choice;
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    printf("\nEnter key for encryption and decryption: ");
    scanf("%d", &key);
    while(1) {
        printf("\n1. Encrypt the message");
        printf("\n2. Decrypt the message");
        printf("\n3. Exit the program");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: encrypt(message, key);
                    break;
            case 2: decrypt(message, key);
                    break;
            case 3: printf("\nExiting the program...");
                    exit(0);
            default: printf("\nInvalid choice!");
        }
    }
    return 0;
}