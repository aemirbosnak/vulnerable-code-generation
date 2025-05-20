//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROUNDS 100
#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 64

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char *message, char *key, int rounds) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[MAX_MESSAGE_LENGTH];

    for (int i = 0; i < message_length; i++) {
        int message_index = (int)message[i] - 97;
        int key_index = (int)key[i % key_length] - 97;
        encrypted_message[i] = (char)(message_index + key_index + rounds) % 26 + 97;
    }

    encrypted_message[message_length] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key, int rounds) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char decrypted_message[MAX_MESSAGE_LENGTH];

    for (int i = 0; i < encrypted_message_length; i++) {
        int encrypted_index = (int)encrypted_message[i] - 97;
        int key_index = (int)key[i % key_length] - 97;
        int decrypted_index = (encrypted_index - key_index - rounds + 26) % 26;
        decrypted_message[i] = (char)decrypted_index + 97;
    }

    decrypted_message[encrypted_message_length] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    srand(time(NULL));

    char message[MAX_MESSAGE_LENGTH];
    printf("Enter message: ");
    scanf("%s", message);

    char key[MAX_KEY_LENGTH];
    generate_key(key, MAX_KEY_LENGTH);

    int rounds;
    printf("Enter number of rounds (1-100): ");
    scanf("%d", &rounds);

    encrypt(message, key, rounds);
    decrypt(message, key, rounds);

    return 0;
}