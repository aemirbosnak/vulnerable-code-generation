//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_KEY_SIZE 100
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char* message, char* key, int key_size) {
    for (int i = 0; i < strlen(message); i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int index = (int)c - 65;
            index = (index + key_size) % 26;
            message[i] = (char)index + 65;
        }
    }
}

void decrypt(char* message, char* key, int key_size) {
    for (int i = 0; i < strlen(message); i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int index = (int)c - 65;
            index = (index - key_size + 26) % 26;
            message[i] = (char)index + 65;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_SIZE];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter key: ");
    scanf("%s", key);

    int key_size = strlen(key);

    generate_key(key, key_size);
    encrypt(message, key, key_size);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key, key_size);
    printf("Decrypted message: %s\n", message);

    return 0;
}