//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_MESSAGE_SIZE 1000

void generate_key(char* key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char* message, int message_size, char* key, int key_size) {
    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' + key[i % key_size] - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char* message, int message_size, char* key, int key_size) {
    for (int i = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' - key[i % key_size] - 'a' + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    int key_size;
    printf("Enter the size of the encryption key (1-100): ");
    scanf("%d", &key_size);

    if (key_size < 1 || key_size > MAX_KEY_SIZE) {
        printf("Invalid key size.\n");
        return 1;
    }

    char key[MAX_KEY_SIZE];
    generate_key(key, key_size);

    encrypt(message, strlen(message), key, key_size);
    printf("Encrypted message: %s\n", message);

    decrypt(message, strlen(message), key, key_size);
    printf("Decrypted message: %s\n", message);

    return 0;
}