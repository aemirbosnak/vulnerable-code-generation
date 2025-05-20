//FormAI DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

/* This program demonstrates an example of C Encryption using a simple Caesar Cipher algorithm */

char encrypted[MAX_SIZE];
char decrypted[MAX_SIZE];

void encryption(char str[], int key) {
    int i;
    char ch;

    for(i=0; str[i] != '\0'; i++) {
        ch = str[i];

        if(ch >= 'a' && ch <= 'z') {
            ch += key;

            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            
            encrypted[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch += key;

            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            encrypted[i] = ch;
        }
        else {
            encrypted[i] = ch;
        }
    }
}

void decryption(char str[], int key) {
    int i;
    char ch;

    for(i=0; str[i] != '\0'; i++) {
        ch = str[i];

        if(ch >= 'a' && ch <= 'z') {
            ch -= key;

            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            
            decrypted[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch -= key;

            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }

            decrypted[i] = ch;
        }
        else {
            decrypted[i] = ch;
        }
    }
}

int main() {
    char str[MAX_SIZE];
    int key;

    printf("Enter a string to encrypt: ");
    fgets(str, MAX_SIZE, stdin);

    printf("\nEnter key for encryption: ");
    scanf("%d", &key);

    encryption(str, key);
    
    printf("\nEncrypted message: %s", encrypted);

    decryption(encrypted, key);

    printf("\nDecrypted message: %s", decrypted);

    return 0;
}