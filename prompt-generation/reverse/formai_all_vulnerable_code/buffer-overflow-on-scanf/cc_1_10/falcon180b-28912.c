//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 256
#define HASH_LENGTH 32

typedef struct {
    char key[MAX_KEY_LENGTH];
    size_t key_length;
    char message[MAX_MESSAGE_LENGTH];
    size_t message_length;
    char hash[HASH_LENGTH];
} crypt_t;

void generate_hash(crypt_t *crypt) {
    char buffer[MAX_MESSAGE_LENGTH + MAX_KEY_LENGTH];
    size_t buffer_length = crypt->message_length + crypt->key_length;
    strcpy(buffer, crypt->message);
    strcat(buffer, crypt->key);
    crypt->hash[0] = 0x7A;
    size_t i = 1;
    for (i = 1; i < buffer_length; i++) {
        int sum = 0;
        sum += (int)buffer[i - 1] ^ (int)crypt->hash[i - 1];
        crypt->hash[i] = (char)sum;
    }
}

int main() {
    crypt_t crypt;
    crypt.key_length = 0;
    crypt.message_length = 0;
    crypt.hash[0] = 0;
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter message: ");
    scanf("%s", message);
    strcpy(crypt.key, key);
    strcpy(crypt.message, message);
    crypt.key_length = strlen(key);
    crypt.message_length = strlen(message);
    generate_hash(&crypt);
    printf("Key: %s\n", crypt.key);
    printf("Message: %s\n", crypt.message);
    printf("Hash: ");
    for (int i = 0; i < HASH_LENGTH; i++) {
        printf("%02X", crypt.hash[i]);
    }
    printf("\n");
    return 0;
}