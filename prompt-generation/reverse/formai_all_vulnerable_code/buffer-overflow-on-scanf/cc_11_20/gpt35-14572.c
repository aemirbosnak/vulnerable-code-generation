//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
/*
* Romeo and Juliet: A Cryptography Implementation 
* Written by [Author's name] 
* 
* This program encrypts and decrypts a message using a Caesar Cipher algorithm
* based on the classic love story of Romeo and Juliet. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // Maximum length of message

int main(void) {
    
    char message[MAX_LEN];
    int key;
    
    printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
    printf("Enter the message to encrypt: \n");
    fgets(message, MAX_LEN, stdin);
    
    printf("What light through yonder window breaks?\n");
    printf("Enter the key: \n");
    scanf("%d", &key);
    
    // Encrypt message
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + key) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + key) % 26 + 'A';
        }
    }
    
    printf("It is the east, and Juliet is the sun.\n");
    printf("Encrypted message: %s", message);
    
    // Decrypt message
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        }
    }
    
    printf("Arise, fair sun, and kill the envious moon.\n");
    printf("Decrypted message: %s", message);
    
    return 0;
}