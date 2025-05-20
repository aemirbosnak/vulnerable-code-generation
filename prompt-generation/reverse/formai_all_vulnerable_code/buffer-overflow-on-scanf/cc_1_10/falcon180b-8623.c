//Falcon-180B DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_KEY_SIZE 64
#define MAX_MESSAGE_SIZE 1024
#define MAX_CHARACTERS 256

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % MAX_CHARACTERS + 'A';
    }
    key[MAX_KEY_SIZE - 1] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j, k;
    char temp;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
        }
    }
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < strlen(key); j++) {
            k = (i * j) % strlen(key);
            temp = message[i];
            message[i] = message[i] ^ key[k];
            key[k] = temp;
        }
    }
}

void decrypt(char *message, char *key) {
    int i, j, k;
    char temp;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
        }
    }
    for (i = 0; i < strlen(message); i++) {
        for (j = 0; j < strlen(key); j++) {
            k = (i * j) % strlen(key);
            temp = message[i];
            message[i] = message[i] ^ key[k];
            key[k] = temp;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE], key[MAX_KEY_SIZE];
    int i;
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    generate_key(key);
    printf("\nEncrypted message: %s\n", message);
    encrypt(message, key);
    printf("\nDecrypted message: %s\n", message);
    return 0;
}