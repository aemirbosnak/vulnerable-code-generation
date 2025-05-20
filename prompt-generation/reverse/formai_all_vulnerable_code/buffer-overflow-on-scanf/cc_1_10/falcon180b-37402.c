//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 256

int main() {
    char key[MAX_KEY_LENGTH + 1];
    char message[MAX_MESSAGE_LENGTH + 1];
    char encrypted_message[MAX_MESSAGE_LENGTH + 1];
    char decrypted_message[MAX_MESSAGE_LENGTH + 1];

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%s", key);

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%s", message);

    // Encrypt the message using the key
    int key_index = 0;
    int message_index = 0;
    while (message_index < strlen(message)) {
        if (isalpha(message[message_index])) {
            message[message_index] = (message[message_index] - 'a' + key[key_index]) % 26 + 'a';
        }
        key_index = (key_index + 1) % strlen(key);
        message_index++;
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    key_index = 0;
    message_index = 0;
    while (message_index < strlen(message)) {
        if (isalpha(message[message_index])) {
            message[message_index] = (message[message_index] - 'a' - key[key_index] + 26) % 26 + 'a';
        }
        key_index = (key_index + 1) % strlen(key);
        message_index++;
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}