//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char* key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        int random_num = rand() % 94 + 33;
        key[i] = random_num;
    }
}

void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            int message_char = tolower(message[i]) - 97;
            int key_char = tolower(key[i % key_length]) - 97;
            int encrypted_char = (message_char + key_char) % 26 + 97;
            encrypted_message[i] = encrypted_char;
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            int encrypted_char = tolower(encrypted_message[i]) - 97;
            int key_char = tolower(key[i % key_length]) - 97;
            int decrypted_char = (encrypted_char - key_char + 26) % 26 + 97;
            decrypted_message[i] = decrypted_char;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
}

int main() {
    srand(time(NULL));
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    int key_length;
    printf("Enter key length (1-32): ");
    scanf("%d", &key_length);
    char key[MAX_KEY_LENGTH];
    generate_key(key, key_length);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}