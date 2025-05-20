//Falcon-180B DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int key_length;
    int message_length;

    // Get key from user
    printf("Enter encryption key: ");
    scanf("%s", key);
    key_length = strlen(key);

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    message_length = strlen(message);

    // Encrypt message using key
    int j = 0;
    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isupper(c)) {
            c = 'A' + ((c - 'A' + key_length) % key_length);
        } else if (islower(c)) {
            c = 'a' + ((c - 'a' + key_length) % key_length);
        }
        encrypted_message[j++] = c;
    }
    encrypted_message[j] = '\0';

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message using key
    j = 0;
    for (int i = 0; i < message_length; i++) {
        char c = encrypted_message[i];
        if (isupper(c)) {
            c = 'A' + ((c - 'A' - key_length + 26) % 26);
        } else if (islower(c)) {
            c = 'a' + ((c - 'a' - key_length + 26) % 26);
        }
        decrypted_message[j++] = c;
    }
    decrypted_message[j] = '\0';

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}