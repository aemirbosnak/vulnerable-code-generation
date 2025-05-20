//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    int key[MAX_KEY_LENGTH];
    int message_length;
    char message[MAX_MESSAGE_LENGTH];
} message_t;

void generate_key(int key[MAX_KEY_LENGTH]) {
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt_message(message_t *message) {
    int key[MAX_KEY_LENGTH];
    generate_key(key);

    for (int i = 0; i < message->message_length; i++) {
        message->message[i] = (message->message[i] + key[i % MAX_KEY_LENGTH]) % 26 + 'A';
    }
}

void decrypt_message(message_t *message) {
    int key[MAX_KEY_LENGTH];
    generate_key(key);

    for (int i = 0; i < message->message_length; i++) {
        message->message[i] = (message->message[i] - key[i % MAX_KEY_LENGTH] + 26) % 26 + 'A';
    }
}

int main() {
    message_t message;
    message.message_length = 0;

    printf("Enter message to encrypt: ");
    scanf("%s", message.message);
    message.message_length = strlen(message.message);

    encrypt_message(&message);
    printf("Encrypted message: %s\n", message.message);

    decrypt_message(&message);
    printf("Decrypted message: %s\n", message.message);

    return 0;
}