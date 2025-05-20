//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int rounds;
} encryption_params;

void generate_key(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt_message(char *message, int message_length, encryption_params *params) {
    char *key = params->key;
    int key_length = params->key_length;
    int rounds = params->rounds;

    int i, j;
    for (i = 0; i < message_length; i++) {
        message[i] = toupper(message[i]);
    }

    for (i = 0; i < rounds; i++) {
        for (j = 0; j < message_length; j++) {
            message[j] = (message[j] - 'A' + key[i % key_length]) % 26 + 'A';
        }
    }
}

int main() {
    encryption_params params;

    printf("Enter the key length (1-32): ");
    scanf("%d", &params.key_length);

    if (params.key_length < 1 || params.key_length > MAX_KEY_LENGTH) {
        printf("Invalid key length.\n");
        return 1;
    }

    printf("Enter the number of rounds (1-10): ");
    scanf("%d", &params.rounds);

    if (params.rounds < 1 || params.rounds > 10) {
        printf("Invalid number of rounds.\n");
        return 1;
    }

    generate_key(params.key, params.key_length);

    printf("Enter the message to encrypt: ");
    char message[MAX_MESSAGE_LENGTH];
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    int message_length = strlen(message);

    encrypt_message(message, message_length, &params);

    printf("Encrypted message: %s\n", message);

    return 0;
}