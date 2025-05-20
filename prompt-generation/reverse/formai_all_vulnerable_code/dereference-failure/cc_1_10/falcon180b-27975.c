//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    srand(time(NULL)); // seed random number generator with current time
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = (char) (rand() % 26 + 'A'); // generate random uppercase letter
    }
    key[KEY_SIZE] = '\0'; // null terminate the string
}

void encrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_index = 0; // index to track position in key
    char encrypted_message[message_len]; // buffer to store encrypted message
    for (int i = 0; i < message_len; i++) {
        encrypted_message[i] = message[i] ^ key[key_index]; // XOR message with key
        key_index = (key_index + 1) % KEY_SIZE; // increment key index, wrapping around if necessary
    }
    encrypted_message[message_len] = '\0'; // null terminate the string
    strcpy(message, encrypted_message); // overwrite original message with encrypted message
}

void decrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_index = 0; // index to track position in key
    char decrypted_message[message_len]; // buffer to store decrypted message
    for (int i = 0; i < message_len; i++) {
        decrypted_message[i] = message[i] ^ key[key_index]; // XOR message with key
        key_index = (key_index + 1) % KEY_SIZE; // increment key index, wrapping around if necessary
    }
    decrypted_message[message_len] = '\0'; // null terminate the string
    strcpy(message, decrypted_message); // overwrite original message with decrypted message
}

int main() {
    char message[100];
    char key[KEY_SIZE + 1]; // add one for null terminator
    generate_key(key); // generate random key
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin); // read message from user (including newline character)
    encrypt(message, key); // encrypt message with key
    printf("Encrypted message: %s\n", message);
    printf("Enter encrypted message to decrypt: ");
    fgets(message, 100, stdin); // read encrypted message from user (including newline character)
    decrypt(message, key); // decrypt encrypted message with key
    printf("Decrypted message: %s\n", message);
    return 0;
}