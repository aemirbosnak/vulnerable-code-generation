//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

int generate_key(char* key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[MAX_KEY_LENGTH] = '\0';
    return 0;
}

int encrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key[j] - 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key[j] - 'a';
        } else {
            message[i] = message[i];
        }
        j = (j + 1) % MAX_KEY_LENGTH;
    }
    return 0;
}

int decrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - key[j] + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - key[j] + 'a';
        } else {
            message[i] = message[i];
        }
        j = (j + 1) % MAX_KEY_LENGTH;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    generate_key(key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}