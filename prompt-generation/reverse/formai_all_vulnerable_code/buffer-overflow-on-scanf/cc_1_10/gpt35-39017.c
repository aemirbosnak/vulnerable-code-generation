//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char msg[], int key) {
    int i;
    char ch;
    for(i = 0; i < strlen(msg); ++i) {
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z') {
            ch += key;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch += key;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }
}

void decrypt(char msg[], int key) {
    int i;
    char ch;
    for(i = 0; i < strlen(msg); ++i) {
        ch = msg[i];
        if(ch >= 'a' && ch <= 'z') {
            ch -= key;
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch -= key;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
        }
    }
}

int main() {
    char msg[1000];
    int key;
    printf("Enter a message to encrypt: ");
    fgets(msg, 1000, stdin);
    printf("Enter key value: ");
    scanf("%d", &key);
    encrypt(msg, key);
    printf("Encrypted message: %s", msg);
    decrypt(msg, key);
    printf("Decrypted message: %s", msg);
    return 0;
}