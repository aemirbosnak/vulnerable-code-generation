//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    char *key;
    char *message;
    char *ciphertext;
} message_t;

void generate_key(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[length] = '\0';
}

void encrypt(char *key, char *message, char *ciphertext) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            ciphertext[j++] = (message[i] - 'A' + (key[i % strlen(key)] - 'A')) % 26 + 'A';
        } else {
            ciphertext[j++] = message[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char *key, char *ciphertext, char *message) {
    int i, j;
    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            message[j++] = (ciphertext[i] - 'A' - (key[i % strlen(key)] - 'A' + 26) % 26) % 26 + 'A';
        } else {
            message[j++] = ciphertext[i];
        }
    }
    message[j] = '\0';
}

int main() {
    message_t message;
    char key[MAX_SIZE];
    char message_text[MAX_SIZE];
    char ciphertext[MAX_SIZE];

    printf("Enter your message: ");
    scanf("%s", message_text);

    printf("Enter your key: ");
    scanf("%s", key);

    generate_key(message.key, strlen(key));
    encrypt(message.key, message_text, message.ciphertext);

    printf("Encrypted message: %s\n", message.ciphertext);

    decrypt(message.key, message.ciphertext, message.message);
    printf("Decrypted message: %s\n", message.message);

    return 0;
}