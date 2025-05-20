//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LEN 50

char key[MAX_STRING_LEN];
char message[MAX_STRING_LEN];

void generateKey(int keyLen) {
    srand(time(NULL));
    int i;
    for (i = 0; i < keyLen; i++) {
        key[i] = (char)(rand() % 26 + 65);
    }
    key[i] = '\0';
}

void encrypt(char *plainText, char *key) {
    int i;
    int len = strlen(plainText);
    for (i = 0; i < len; i++) {
        plainText[i] = (((plainText[i] + key[i % strlen(key)]) % 26) + 65);
    }
}

void decrypt(char *encryptedText, char *key) {
    int i;
    int len = strlen(encryptedText);
    for (i = 0; i < len; i++) {
        encryptedText[i] = (((encryptedText[i] - key[i % strlen(key)] + 26) % 26) + 65);
    }
}

int main() {
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    int keyLen;
    printf("Enter the length of the key: ");
    scanf("%d", &keyLen);

    generateKey(keyLen);
    printf("Key: %s\n", key);

    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}