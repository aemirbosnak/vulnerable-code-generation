//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 10
#define MAX_MESSAGE_LENGTH 100

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    // Get the key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message
    int message_length = strlen(message);
    int encrypted_message_length = 0;
    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            int shift = c - 'a';
            char encrypted_c = (char) ((int) c + (int) key[i % MAX_KEY_LENGTH] - 97 % 26 + 97);
            encrypted_message[encrypted_message_length++] = encrypted_c;
        } else {
            encrypted_message[encrypted_message_length++] = c;
        }
    }
    encrypted_message[encrypted_message_length] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    int decrypted_message_length = 0;
    for (int i = 0; i < encrypted_message_length; i++) {
        char c = encrypted_message[i];
        if (isalpha(c)) {
            int shift = (int) c - 97;
            char decrypted_c = (char) ((int) c - (int) key[i % MAX_KEY_LENGTH] + 26) % 26 + 'a';
            decrypted_message[decrypted_message_length++] = decrypted_c;
        } else {
            decrypted_message[decrypted_message_length++] = c;
        }
    }
    decrypted_message[decrypted_message_length] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}