//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define ALPHABET_SIZE 26
#define KEY_SIZE 100

typedef struct {
    char message[SIZE];
    char encrypted_message[SIZE];
    char decrypted_message[SIZE];
} message_t;

void generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = 'a' + rand() % ALPHABET_SIZE;
    }
    key[KEY_SIZE - 1] = '\0';
}

void encrypt_message(message_t* message, char* key) {
    int i, j;
    for (i = 0, j = 0; message->message[i]!= '\0'; i++) {
        if (message->message[i] >= 'a' && message->message[i] <= 'z') {
            message->encrypted_message[j] = 'a' + ((message->message[i] - 'a' + (key[i % KEY_SIZE] - 'a')) % ALPHABET_SIZE);
        } else {
            message->encrypted_message[j] = message->message[i];
        }
        j++;
    }
    message->encrypted_message[j] = '\0';
}

void decrypt_message(message_t* message, char* key) {
    int i, j;
    for (i = 0, j = 0; message->encrypted_message[i]!= '\0'; i++) {
        if (message->encrypted_message[i] >= 'a' && message->encrypted_message[i] <= 'z') {
            message->decrypted_message[j] = 'a' + ((message->encrypted_message[i] - 'a' - (key[i % KEY_SIZE] - 'a')) % ALPHABET_SIZE + 26) % ALPHABET_SIZE;
        } else {
            message->decrypted_message[j] = message->encrypted_message[i];
        }
        j++;
    }
    message->decrypted_message[j] = '\0';
}

int main() {
    message_t message;
    char key[KEY_SIZE];

    printf("Enter a message: ");
    scanf("%s", message.message);

    generate_key(key);

    printf("Encrypted message: %s\n", message.encrypted_message);

    decrypt_message(&message, key);

    printf("Decrypted message: %s\n", message.decrypted_message);

    return 0;
}