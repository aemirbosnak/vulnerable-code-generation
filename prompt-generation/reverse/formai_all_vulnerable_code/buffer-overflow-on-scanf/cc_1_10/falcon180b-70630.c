//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16

void generate_key(char* key) {
    int i;
    for(i=0; i<KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i;
    for(i=0; i<strlen(plaintext); i++) {
        if(isalpha(plaintext[i])) {
            ciphertext[i] = (char)((int)plaintext[i] + (int)key[i%KEY_SIZE] - 65 % 26 + 65);
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i;
    for(i=0; i<strlen(ciphertext); i++) {
        if(isalpha(ciphertext[i])) {
            plaintext[i] = (char)((int)ciphertext[i] - (int)key[i%KEY_SIZE] - 65 % 26 + 65);
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char plaintext[1000];
    char key[KEY_SIZE+1];
    char ciphertext[1000];
    char decrypted_text[1000];
    srand(time(NULL));
    generate_key(key);
    printf("Enter plaintext: ");
    scanf("%[^\n]", plaintext);
    printf("Plaintext: %s\n", plaintext);
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, key, decrypted_text);
    printf("Decrypted text: %s\n", decrypted_text);
    return 0;
}