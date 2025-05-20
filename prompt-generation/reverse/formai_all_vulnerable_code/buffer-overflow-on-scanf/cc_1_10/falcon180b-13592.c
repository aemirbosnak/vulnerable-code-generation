//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 64
#define MAX_MSG_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char msg[MAX_MSG_LENGTH];
    char encrypted_msg[MAX_MSG_LENGTH];
} message;

void generate_key(char *key, int key_length) {
    srand(time(NULL));
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

void encrypt_message(char *message, char *key) {
    int msg_length = strlen(message);
    int key_length = strlen(key);
    int i = 0;
    for (int j = 0; j < msg_length; j++) {
        if (isalpha(message[j])) {
            message[j] = (message[j] - 'a' + key[i] - 'a') % 26 + 'a';
            i = (i + 1) % key_length;
        }
    }
}

void decrypt_message(char *encrypted_message, char *key) {
    int msg_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int i = 0;
    for (int j = 0; j < msg_length; j++) {
        if (isalpha(encrypted_message[j])) {
            encrypted_message[j] = (encrypted_message[j] - 'a' + 'a' - key[i]) % 26 + 'a';
            i = (i + 1) % key_length;
        }
    }
}

int main() {
    message msg;
    printf("Enter the message: ");
    scanf("%s", msg.msg);
    printf("Enter the key: ");
    scanf("%s", msg.key);
    generate_key(msg.key, strlen(msg.key));
    encrypt_message(msg.msg, msg.key);
    printf("Encrypted message: %s\n", msg.encrypted_msg);
    printf("Decrypted message: %s\n", msg.encrypted_msg);
    return 0;
}