//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LEN 100
#define MAX_MSG_LEN 1000

void generate_key(char *key, int len) {
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[len] = '\0';
}

void encrypt(char *msg, char *key, char *encrypted_msg) {
    for (int i = 0; i < strlen(msg); i++) {
        if (isalpha(msg[i])) {
            encrypted_msg[i] = (msg[i] - 'a' + rand() % 26) % 26 + 'a';
        } else {
            encrypted_msg[i] = msg[i];
        }
    }
    encrypted_msg[strlen(msg)] = '\0';
}

void decrypt(char *encrypted_msg, char *key, char *decrypted_msg) {
    for (int i = 0; i < strlen(encrypted_msg); i++) {
        if (isalpha(encrypted_msg[i])) {
            decrypted_msg[i] = (encrypted_msg[i] - 'a' - rand() % 26 + 26) % 26 + 'a';
        } else {
            decrypted_msg[i] = encrypted_msg[i];
        }
    }
    decrypted_msg[strlen(encrypted_msg)] = '\0';
}

int main() {
    char key[MAX_KEY_LEN];
    char msg[MAX_MSG_LEN];
    char encrypted_msg[MAX_MSG_LEN];
    char decrypted_msg[MAX_MSG_LEN];

    srand(time(NULL));
    generate_key(key, rand() % MAX_KEY_LEN + 1);

    printf("Enter a message to encrypt: ");
    scanf("%s", msg);

    encrypt(msg, key, encrypted_msg);
    printf("Encrypted message: %s\n", encrypted_msg);

    decrypt(encrypted_msg, key, decrypted_msg);
    printf("Decrypted message: %s\n", decrypted_msg);

    return 0;
}