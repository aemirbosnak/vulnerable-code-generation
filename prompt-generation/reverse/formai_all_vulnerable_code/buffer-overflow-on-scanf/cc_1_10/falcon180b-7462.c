//Falcon-180B DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_MESSAGE_SIZE 1000
#define ALPHABET_SIZE 26

typedef struct {
    char key[MAX_KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
} Message;

void generate_key(char* key) {
    for (int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
}

void encrypt_message(Message* message) {
    char key[MAX_KEY_SIZE] = {0};
    strcpy(key, message->key);
    generate_key(key);

    int key_index = 0;
    for (int i = 0; i < strlen(message->message); i++) {
        char c = message->message[i];
        if (c >= 'A' && c <= 'Z') {
            message->encrypted_message[i] = key[(key_index % strlen(key))];
            key_index++;
        } else {
            message->encrypted_message[i] = c;
        }
    }
}

int main() {
    Message message;
    printf("Enter the key: ");
    scanf("%s", message.key);

    printf("Enter the message to be encrypted: ");
    scanf("%s", message.message);

    encrypt_message(&message);

    printf("\nEncrypted Message: %s\n", message.encrypted_message);

    return 0;
}