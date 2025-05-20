#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    char key[256];
} User;

void encrypt(User* user, char* plaintext, char* ciphertext, int length) {
    for (int i = 0; i < length; i++) {
        ciphertext[i] = plaintext[i] ^ user->key[i % strlen(user->key)];
    }
}

void decrypt(User* user, char* ciphertext, char* plaintext, int length) {
    for (int i = 0; i < length; i++) {
        plaintext[i] = ciphertext[i] ^ user->key[i % strlen(user->key)];
    }
}

int main() {
    User alice = {"Alice", "MySecretKey123"};
    User bob = {"Bob", "AnotherSecretKey456"};

    char message[] = "Hello World!";
    char encrypted_alice[100];
    char decrypted_bob[100];

    encrypt(&alice, message, encrypted_alice, strlen(message));
    decrypt(&bob, encrypted_alice, decrypted_bob, strlen(message) + 1);

    printf("Encrypted with Alice's key: %s\n", encrypted_alice);
    printf("Decrypted with Bob's key: %s\n", decrypted_bob);

    return 0;
}
