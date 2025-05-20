//Falcon-180B DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 1000
#define KEY_LENGTH 16

void generate_key(char* key) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char* message, char* key) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            char k = tolower(key[i % KEY_LENGTH]);
            int shift = (k - 'a') % 26;
            char result = (c - 'a' + shift) % 26 + 'a';
            message[i] = result;
        }
    }
}

void decrypt(char* message, char* key) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            char k = tolower(key[i % KEY_LENGTH]);
            int shift = (k - 'a' + 26) % 26;
            char result = (c - 'a' - shift + 26) % 26 + 'a';
            message[i] = result;
        }
    }
}

int main() {
    srand(time(NULL));
    char message[MAX_LENGTH];
    char key[KEY_LENGTH];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter a key: ");
    scanf("%s", key);
    if (strlen(key)!= KEY_LENGTH) {
        printf("Error: Key must be exactly %d characters.\n", KEY_LENGTH);
        return 1;
    }
    generate_key(key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}