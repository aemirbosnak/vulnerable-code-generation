//Falcon-180B DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to encrypt a string
void encrypt(char* str) {
    int len = strlen(str);
    int key = 7;
    for(int i=0; i<len; i++) {
        char ch = tolower(str[i]);
        if(ch >= 'a' && ch <= 'z') {
            ch = (ch + key - 97) % 26 + 97;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = (ch + key - 65) % 26 + 65;
        }
        str[i] = ch;
    }
}

// function to decrypt a string
void decrypt(char* str) {
    int len = strlen(str);
    int key = 7;
    for(int i=0; i<len; i++) {
        char ch = tolower(str[i]);
        if(ch >= 'a' && ch <= 'z') {
            ch = (ch - key + 26) % 26 + 97;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = (ch - key + 26) % 26 + 65;
        }
        str[i] = ch;
    }
}

int main() {
    char str[100];
    printf("Enter a string to encrypt: ");
    scanf("%s", str);
    encrypt(str);
    printf("Encrypted string: %s\n", str);

    printf("Enter the encrypted string to decrypt: ");
    scanf("%s", str);
    decrypt(str);
    printf("Decrypted string: %s\n", str);

    return 0;
}