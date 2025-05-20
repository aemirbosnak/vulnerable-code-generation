//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FLAG "Cyberpunk2021"
#define KEY "h4ckth3pl4n3t"

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    char encrypted_message[message_length + 1];

    for (i = 0, j = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c = (c - 'a' + key_length) % 26 + 'a';
        }
        encrypted_message[j++] = c;
    }
    encrypted_message[j] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;
    char decrypted_message[message_length + 1];

    for (i = 0, j = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c = (c - 'a' - key_length + 26) % 26 + 'a';
        }
        decrypted_message[j++] = c;
    }
    decrypted_message[j] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    encrypt(message, KEY);

    char encrypted_message[100];
    strcpy(encrypted_message, message);

    char decrypted_message[100];
    decrypt(encrypted_message, KEY);

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}