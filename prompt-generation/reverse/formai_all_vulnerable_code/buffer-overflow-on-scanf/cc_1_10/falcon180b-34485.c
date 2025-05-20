//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    int public_key;
    int private_key;
} KeyPair;

int generate_key_pair(KeyPair* key_pair) {
    int public_key = rand() % MAX_SIZE;
    int private_key = rand() % MAX_SIZE;

    key_pair->public_key = public_key;
    key_pair->private_key = private_key;

    return 0;
}

int encrypt(int message, KeyPair* key_pair) {
    int encrypted_message = (message * key_pair->public_key) % MAX_SIZE;

    return encrypted_message;
}

int decrypt(int encrypted_message, KeyPair* key_pair) {
    int decrypted_message = (encrypted_message * key_pair->private_key) % MAX_SIZE;

    return decrypted_message;
}

int main() {
    KeyPair key_pair;
    int message;

    printf("Enter a message to encrypt: ");
    scanf("%d", &message);

    generate_key_pair(&key_pair);

    int encrypted_message = encrypt(message, &key_pair);

    printf("Encrypted message: %d\n", encrypted_message);

    int decrypted_message = decrypt(encrypted_message, &key_pair);

    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}