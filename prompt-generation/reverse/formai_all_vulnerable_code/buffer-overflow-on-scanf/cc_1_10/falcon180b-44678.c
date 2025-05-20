//Falcon-180B DATASET v1.0 Category: Encryption ; Style: imaginative
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define KEY "mysecretkey"

void encrypt(char* plaintext, char* ciphertext) {
    int i, j, n;
    char ch;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    n = strlen(plaintext);
    for(i = 0; i < n; i++) {
        ch = tolower(plaintext[i]);
        if(isalpha(ch)) {
            j = 0;
            while(key[j]!= '\0') {
                if(tolower(key[j]) == ch) {
                    ciphertext[i] = key[j + 1];
                    break;
                }
                j++;
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[n] = '\0';
}

void decrypt(char* ciphertext, char* plaintext) {
    int i, j, n;
    char ch;
    char key[strlen(KEY)];
    strcpy(key, KEY);
    n = strlen(ciphertext);
    for(i = 0; i < n; i++) {
        ch = tolower(ciphertext[i]);
        if(isalpha(ch)) {
            j = 0;
            while(key[j]!= '\0') {
                if(tolower(key[j]) == ch) {
                    plaintext[i] = key[j];
                    break;
                }
                j++;
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[n] = '\0';
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    printf("Enter plaintext: ");
    scanf("%[^\n]", plaintext);
    encrypt(plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, plaintext);
    printf("Plaintext: %s\n", plaintext);
    return 0;
}