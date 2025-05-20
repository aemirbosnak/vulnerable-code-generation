//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int key;
    int rounds;
} encryption_params;

void generate_random_key(int* key) {
    srand(time(NULL));
    *key = rand() % 256;
}

void generate_random_rounds(int* rounds) {
    srand(time(NULL));
    *rounds = rand() % 10 + 1;
}

void print_encryption_params(encryption_params* params) {
    printf("Encryption Parameters:\n");
    printf("Key: %d\n", params->key);
    printf("Rounds: %d\n", params->rounds);
}

void encrypt_message(char* message, int key, int rounds) {
    int message_length = strlen(message);
    int i, j;
    for (i = 0; i < message_length; i++) {
        message[i] = message[i] ^ key;
        for (j = 0; j < rounds; j++) {
            message[i] = message[i] ^ key;
        }
    }
}

void decrypt_message(char* message, int key, int rounds) {
    int message_length = strlen(message);
    int i, j;
    for (i = 0; i < message_length; i++) {
        message[i] = message[i] ^ key;
        for (j = 0; j < rounds; j++) {
            message[i] = message[i] ^ key;
        }
    }
}

int main() {
    encryption_params params;
    char message[100];
    generate_random_key(&params.key);
    generate_random_rounds(&params.rounds);
    printf("Encryption Parameters:\n");
    print_encryption_params(&params);
    printf("Enter a message to encrypt:\n");
    scanf("%s", message);
    encrypt_message(message, params.key, params.rounds);
    printf("Encrypted Message: %s\n", message);
    decrypt_message(message, params.key, params.rounds);
    printf("Decrypted Message: %s\n", message);
    return 0;
}