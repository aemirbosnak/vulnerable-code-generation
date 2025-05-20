//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_MESSAGE_SIZE 1000

char *generate_key(int key_size);
void encrypt_message(char *message, char *key);
void decrypt_message(char *message, char *key);

int main() {
    char message[MAX_MESSAGE_SIZE];
    int message_size;
    char key[MAX_KEY_SIZE];
    int key_size;

    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message_size = strlen(message);

    printf("Enter key size (between 1 and %d): ", MAX_KEY_SIZE);
    scanf("%d", &key_size);

    char *key_generated = generate_key(key_size);
    strcpy(key, key_generated);

    encrypt_message(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt_message(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

char *generate_key(int key_size) {
    char *key = malloc(key_size + 1);

    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';

    return key;
}

void encrypt_message(char *message, char *key) {
    for (int i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] + key[i % strlen(key)]) % 26 + 'a';
        }
    }
}

void decrypt_message(char *message, char *key) {
    for (int i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - key[i % strlen(key)]) % 26 + 'a';
        }
    }
}