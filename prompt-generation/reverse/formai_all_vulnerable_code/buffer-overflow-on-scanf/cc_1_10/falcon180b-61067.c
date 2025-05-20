//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1024

typedef struct {
    int public_key;
    int private_key;
} key_pair;

key_pair generate_keys() {
    key_pair keys;
    int public_key = rand() % 10000 + 1;
    int private_key = rand() % 10000 + 1;
    keys.public_key = public_key;
    keys.private_key = private_key;
    return keys;
}

void encrypt_message(char* message, int public_key) {
    int i = 0;
    int len = strlen(message);
    for (i = 0; i < len; i++) {
        message[i] = message[i] ^ public_key;
    }
}

void decrypt_message(char* message, int private_key) {
    int i = 0;
    int len = strlen(message);
    for (i = 0; i < len; i++) {
        message[i] = message[i] ^ private_key;
    }
}

int main() {
    char message[MAX_LENGTH];
    key_pair keys = generate_keys();
    int public_key = keys.public_key;
    int private_key = keys.private_key;
    printf("Enter a message: ");
    scanf("%[^\n]s", message);
    encrypt_message(message, public_key);
    printf("Encrypted message: %s\n", message);
    decrypt_message(message, private_key);
    printf("Decrypted message: %s\n", message);
    return 0;
}