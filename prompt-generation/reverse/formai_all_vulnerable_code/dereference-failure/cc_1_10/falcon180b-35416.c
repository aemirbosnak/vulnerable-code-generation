//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define KEY_SIZE 16

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char* message, char* key, char* encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char c = toupper(message[i]);
            int index = c - 'A';
            encrypted_message[i] = key[index % KEY_SIZE];
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            char c = encrypted_message[i];
            int index = 0;
            while (key[index]!= c) {
                index++;
            }
            decrypted_message[i] = 'A' + index;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
}

int main() {
    char message[MAX_SIZE];
    char key[KEY_SIZE + 1];
    char encrypted_message[MAX_SIZE];
    char decrypted_message[MAX_SIZE];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    generate_key(key);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}