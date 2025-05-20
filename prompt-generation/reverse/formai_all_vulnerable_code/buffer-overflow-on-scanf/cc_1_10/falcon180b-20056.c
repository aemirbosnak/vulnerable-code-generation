//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000

void generate_key(char* key) {
    srand(time(NULL));
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[strlen(key)] = '\0';
}

void encrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + 13 - (key[j] - 'a')) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + 13 - (key[j] - 'a')) % 26 + 'a';
            }
        }
        j++;
        if (key[j] == '\0') {
            j = 0;
        }
    }
}

void decrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' - (key[j] - 'a' + 13)) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' - (key[j] - 'a' + 13)) % 26 + 'a';
            }
        }
        j++;
        if (key[j] == '\0') {
            j = 0;
        }
    }
}

int main() {
    char message[MAX_LENGTH], key[MAX_LENGTH];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);
    generate_key(key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}