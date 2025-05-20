//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024
#define PUBLIC_KEY "Public Key"
#define PRIVATE_KEY "Private Key"

typedef struct {
    char* public_key;
    char* private_key;
} KeyPair;

void generate_keys(KeyPair* key_pair) {
    char* public_key = malloc(MAX_SIZE);
    char* private_key = malloc(MAX_SIZE);

    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        char rand_char = rand() % 26 + 'a';
        strncat(public_key, &rand_char, 1);
        strncat(private_key, &rand_char, 1);
    }

    key_pair->public_key = public_key;
    key_pair->private_key = private_key;
}

void encrypt(char* message, char* public_key, char* encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + 'A' - 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 'a' - 'A';
        }

        int key_index = (int)public_key[i % strlen(public_key)] - 'a';
        ch = (ch - key_index + 26) % 26 + 'a';

        strncat(encrypted_message, &ch, 1);
    }
}

void decrypt(char* encrypted_message, char* private_key, char* decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        char ch = encrypted_message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + 'A' - 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 'a' - 'A';
        }

        int key_index = (int)private_key[i % strlen(private_key)] - 'a';
        ch = (ch - key_index - 26 + 26) % 26 + 'a';

        strncat(decrypted_message, &ch, 1);
    }
}

int main() {
    KeyPair key_pair;
    generate_keys(&key_pair);

    char message[] = "Hello, World!";
    char encrypted_message[MAX_SIZE];
    char decrypted_message[MAX_SIZE];

    encrypt(message, key_pair.public_key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key_pair.private_key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}