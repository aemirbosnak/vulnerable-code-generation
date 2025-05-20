//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_PLAINTEXT_SIZE 1024
#define MAX_CIPHERTEXT_SIZE (MAX_PLAINTEXT_SIZE + 1)

typedef struct {
    char key[MAX_KEY_SIZE + 1];
    int key_size;
    char plaintext[MAX_PLAINTEXT_SIZE + 1];
    char ciphertext[MAX_CIPHERTEXT_SIZE];
} Message;

void generate_key(Message* message) {
    char key[MAX_KEY_SIZE + 1];
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_SIZE] = '\0';
    strcpy(message->key, key);
    message->key_size = MAX_KEY_SIZE;
}

void encrypt(Message* message) {
    char plaintext[MAX_PLAINTEXT_SIZE + 1];
    strcpy(plaintext, message->plaintext);
    for (int i = 0; i < message->key_size; i++) {
        for (int j = 0; j < strlen(plaintext); j++) {
            if (isalpha(plaintext[j])) {
                plaintext[j] = toupper(plaintext[j]) ^ message->key[i];
            }
        }
    }
    strcpy(message->ciphertext, plaintext);
}

void decrypt(Message* message) {
    char plaintext[MAX_PLAINTEXT_SIZE + 1];
    strcpy(plaintext, message->ciphertext);
    for (int i = 0; i < message->key_size; i++) {
        for (int j = 0; j < strlen(plaintext); j++) {
            if (isalpha(plaintext[j])) {
                plaintext[j] = toupper(plaintext[j]) ^ message->key[i];
            }
        }
    }
    strcpy(message->plaintext, plaintext);
}

int main() {
    Message message;
    generate_key(&message);
    printf("Enter your message: ");
    scanf("%s", message.plaintext);
    printf("Encrypted message: %s\n", message.ciphertext);
    printf("Decrypted message: %s\n", message.plaintext);
    return 0;
}