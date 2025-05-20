//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int encrypted_message_length = 0;
    int i;

    for (i = 0; i < message_length; i++) {
        char c = toupper(message[i]);
        int k = toupper(key[i % key_length]) - 65;
        int m = (c - 65) + k;
        if (m > 25) {
            m -= 26;
        }
        encrypted_message[encrypted_message_length++] = m + 65;
    }
    encrypted_message[encrypted_message_length] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int decrypted_message_length = 0;
    int i;

    for (i = 0; i < message_length; i++) {
        char c = toupper(message[i]);
        int k = toupper(key[i % key_length]) - 65;
        int m = (c - 65) - k;
        if (m < 0) {
            m += 26;
        }
        decrypted_message[decrypted_message_length++] = m + 65;
    }
    decrypted_message[decrypted_message_length] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter a key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}