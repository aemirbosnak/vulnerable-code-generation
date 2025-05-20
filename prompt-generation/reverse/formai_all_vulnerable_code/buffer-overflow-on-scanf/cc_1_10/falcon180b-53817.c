//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_MSG_LEN 1000

void encrypt(char* msg, char* key) {
    int len = strlen(msg);
    int keylen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        char c = toupper(msg[i]);
        if (isalpha(c)) {
            c = (c - 'A' + j) % 26 + 'A';
        }
        printf("%c", c);
    }
}

void decrypt(char* msg, char* key) {
    int len = strlen(msg);
    int keylen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        char c = toupper(msg[i]);
        if (isalpha(c)) {
            c = (c - 'A' + 26 - j) % 26 + 'A';
        }
        printf("%c", c);
    }
}

int main() {
    char msg[MAX_MSG_LEN];
    char key[MAX_KEY_LEN];

    printf("Enter message to encrypt: ");
    fgets(msg, MAX_MSG_LEN, stdin);

    printf("Enter key: ");
    scanf("%s", key);

    printf("Encrypted message: ");
    encrypt(msg, key);
    printf("\n");

    printf("Decrypted message: ");
    decrypt(msg, key);
    printf("\n");

    return 0;
}