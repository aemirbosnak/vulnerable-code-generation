//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt message using Caesar cipher
void encrypt(char* message, int key) {
    int i, j;
    char ch;
    for(i = 0; message[i]!= '\0'; i++) {
        ch = message[i];
        if(isalpha(ch)) {
            if(isupper(ch)) {
                ch = ch + key - 65;
                if(ch > 90) {
                    ch = ch - 26;
                }
            } else {
                ch = ch + key - 97;
                if(ch > 122) {
                    ch = ch - 26;
                }
            }
            message[i] = ch;
        }
    }
}

// Function to decrypt message using Caesar cipher
void decrypt(char* message, int key) {
    int i, j;
    char ch;
    for(i = 0; message[i]!= '\0'; i++) {
        ch = message[i];
        if(isalpha(ch)) {
            if(isupper(ch)) {
                ch = ch - key - 65;
                if(ch < 65) {
                    ch = ch + 26;
                }
            } else {
                ch = ch - key - 97;
                if(ch < 97) {
                    ch = ch + 26;
                }
            }
            message[i] = ch;
        }
    }
}

int main() {
    char message[1000];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("\nEncrypted message: %s\n", message);

    printf("Enter the decryption key (0-25): ");
    scanf("%d", &key);

    decrypt(message, key);

    printf("\nDecrypted message: %s\n", message);

    return 0;
}