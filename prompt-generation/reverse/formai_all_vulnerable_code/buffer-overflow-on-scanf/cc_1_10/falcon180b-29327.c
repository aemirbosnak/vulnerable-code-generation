//Falcon-180B DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

char plaintext[SIZE];
char ciphertext[SIZE];

void generateKey(char key[SIZE]) {
    int i;
    for(i=0;i<SIZE;i++) {
        key[i] = rand()%26 + 'a';
    }
}

void encrypt(char plaintext[SIZE], char key[SIZE]) {
    int i;
    for(i=0;i<strlen(plaintext);i++) {
        if(isalpha(plaintext[i])) {
            if(isupper(plaintext[i])) {
                ciphertext[i] = key[(int)plaintext[i]-65];
            }
            else {
                ciphertext[i] = key[(int)plaintext[i]-97];
            }
        }
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void decrypt(char ciphertext[SIZE], char key[SIZE]) {
    int i;
    for(i=0;i<strlen(ciphertext);i++) {
        if(isalpha(ciphertext[i])) {
            if(isupper(ciphertext[i])) {
                plaintext[i] = key[(int)ciphertext[i]-65]+'A';
            }
            else {
                plaintext[i] = key[(int)ciphertext[i]-97]+'a';
            }
        }
        else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char key[SIZE];
    char plaintext[SIZE];
    char ciphertext[SIZE];
    char decryptedtext[SIZE];
    int choice;

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    generateKey(key);
    encrypt(plaintext, key);
    printf("Encrypted text: %s\n", ciphertext);

    printf("Enter your choice:\n1. Decrypt\n2. Exit\n");
    scanf("%d", &choice);

    if(choice == 1) {
        decrypt(ciphertext, key);
        printf("Decrypted text: %s\n", decryptedtext);
    }

    return 0;
}