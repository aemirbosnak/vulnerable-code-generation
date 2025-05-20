//Falcon-180B DATASET v1.0 Category: Encryption ; Style: real-life
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_KEY_LENGTH 50
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted[MAX_MESSAGE_LENGTH];
    char decrypted[MAX_MESSAGE_LENGTH];
} message_t;

void generate_key(char *key) {
    int i;
    for(i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
}

void encrypt(message_t *message) {
    int i, j;
    for(i = 0, j = 0; i < strlen(message->message); i++) {
        if(isalpha(message->message[i])) {
            message->encrypted[j] = message->message[i];
            j++;
        }
    }
    message->encrypted[j] = '\0';
}

void decrypt(message_t *message) {
    int i, j;
    for(i = 0, j = 0; i < strlen(message->encrypted); i++) {
        if(isalpha(message->encrypted[i])) {
            message->decrypted[j] = message->encrypted[i];
            j++;
        }
    }
    message->decrypted[j] = '\0';
}

int main() {
    message_t message;
    printf("Enter the message to encrypt: ");
    scanf("%s", message.message);
    printf("Enter the key: ");
    scanf("%s", message.key);
    generate_key(message.key);
    encrypt(&message);
    printf("Encrypted message: %s\n", message.encrypted);
    decrypt(&message);
    printf("Decrypted message: %s\n", message.decrypted);
    return 0;
}