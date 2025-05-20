//FormAI DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Function for encryption using Caesar cipher */
void encryptCaesar(char *msg, int key) {
    int i, ch;
    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        /* Implementing the shift operation */
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }
}

/* Function for encryption using Vigenere cipher */
void encryptVigenere(char *msg, char *key) {
    int i, j, k;
    /* Finding length of key and message */
    int msgLen = strlen(msg), keyLen = strlen(key);
    /* Creating a new key based on the message length */
    char newKey[msgLen];
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen){
            j = 0;
        }
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    /* Implementing Vigenere cipher */
    for(i = 0; i < msgLen; ++i){
        char ch = ((msg[i] + newKey[i]) % 26) + 'A';
        msg[i] = ch;
    }
}

int main() {
    char msg[100], key[100];
    int choice, keyInt;
    printf("Enter a message: ");
    fgets(msg, sizeof(msg), stdin);
    printf("Enter an encryption key: ");
    fgets(key, sizeof(key), stdin);

    /* Removing newline characters */
    msg[strcspn(msg, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    printf("Choose an encryption method:\n");
    printf("1. Caesar Cipher\n");
    printf("2. Vigenere Cipher\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter a shift key: ");
            scanf("%d", &keyInt);
            encryptCaesar(msg, keyInt);
            printf("Encrypted message: %s\n", msg);
            break;
        case 2:
            encryptVigenere(msg, key);
            printf("Encrypted message: %s\n", msg);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}