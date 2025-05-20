//FormAI DATASET v1.0 Category: modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateKey(char key[], int len);
void encrypt(char message[], char key[], int len);
void decrypt(char message[], char key[], int len);

int main(void) {
    char message[100], key[100];
    int len;

    printf("Please enter the message to encrypt (max 100 characters): ");
    fgets(message, 100, stdin);
    printf("Please enter the length of the message (max 100): ");
    scanf("%d", &len);

    generateKey(key, len);

    printf("\nMessage before encryption: %s\n", message);

    encrypt(message, key, len);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key, len);

    printf("Decrypted message: %s\n", message);

    return 0;
}

void generateKey(char key[], int len) {
    int i;
    srand(time(0));
    for (i = 0; i < len; i++) {
        key[i] = rand() % 256;
    }
    key[i] = '\0';
    printf("\nKey: %s\n", key);
}

void encrypt(char message[], char key[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        message[i] = message[i] ^ key[i];
    }
}

void decrypt(char message[], char key[], int len) {
    encrypt(message, key, len);
}