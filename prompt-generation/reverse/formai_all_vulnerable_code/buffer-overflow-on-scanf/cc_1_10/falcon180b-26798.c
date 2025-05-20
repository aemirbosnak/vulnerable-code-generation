//Falcon-180B DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_MESSAGE_LEN 1000

void generate_key(char *key, int key_len) {
    int i;
    for(i=0; i<key_len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_len] = '\0';
}

void encrypt(char *message, char *key, char *ciphertext) {
    int i, j;
    for(i=0, j=0; i<strlen(message); i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                ciphertext[j++] = 'A' + ((message[i]-'A'+key[i%strlen(key)]) % 26);
            } else {
                ciphertext[j++] = 'a' + ((message[i]-'a'+key[i%strlen(key)]) % 26);
            }
        } else {
            ciphertext[j++] = message[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char *ciphertext, char *key, char *message) {
    int i, j;
    for(i=0, j=0; i<strlen(ciphertext); i++) {
        if(isalpha(ciphertext[i])) {
            if(isupper(ciphertext[i])) {
                message[j++] = 'A' + (ciphertext[i]-'A'-key[i%strlen(key)+1] + 26) % 26;
            } else {
                message[j++] = 'a' + (ciphertext[i]-'a'-key[i%strlen(key)+1] + 26) % 26;
            }
        } else {
            message[j++] = ciphertext[i];
        }
    }
    message[j] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LEN], key[MAX_KEY_LEN], ciphertext[MAX_MESSAGE_LEN];

    printf("Enter message to be encrypted: ");
    scanf("%s", message);

    generate_key(key, strlen(message));

    encrypt(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}