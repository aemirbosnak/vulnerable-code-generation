//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "MySecretKey123"

void encrypt(char* message, int key) {
    int i, j, temp;
    char ch;
    for(i = 0; message[i]!= '\0'; i++) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch > 'z') {
                ch = ch - 26;
            }
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch > 'Z') {
                ch = ch - 26;
            }
        }
        message[i] = ch;
    }
}

void decrypt(char* message, int key) {
    int i, j, temp;
    char ch;
    for(i = 0; message[i]!= '\0'; i++) {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a') {
                ch = ch + 26;
            }
        } else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A') {
                ch = ch + 26;
            }
        }
        message[i] = ch;
    }
}

void main() {
    char message[100];
    int key = 0;
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter key (0-25): ");
    scanf("%d", &key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
}