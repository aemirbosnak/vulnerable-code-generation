//Falcon-180B DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1000

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_SIZE] = '\0';
}

void encrypt(char *key, char *message, char *encrypted_message) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[j] = ((message[i] - 'a' + key[i % MAX_KEY_SIZE]) % 26) + 'a';
            j++;
        }
    }
    encrypted_message[j] = '\0';
}

void decrypt(char *key, char *encrypted_message, char *message) {
    int i, j;
    for (i = 0, j = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            message[j] = ((encrypted_message[i] - 'a' - key[i % MAX_KEY_SIZE] + 26) % 26) + 'a';
            j++;
        }
    }
    message[j] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    generate_key(key);

    char message[MAX_MESSAGE_SIZE];
    printf("Enter your message: ");
    scanf("%s", message);

    char encrypted_message[MAX_MESSAGE_SIZE];
    encrypt(key, message, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    char decrypted_message[MAX_MESSAGE_SIZE];
    decrypt(key, encrypted_message, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}