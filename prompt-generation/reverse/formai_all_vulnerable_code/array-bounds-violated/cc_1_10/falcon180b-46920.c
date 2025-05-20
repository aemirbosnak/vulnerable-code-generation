//Falcon-180B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int message_length, key_length, i, j, k;

    // Get message from user
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message_length = strlen(message);

    // Remove newline character
    message[message_length - 1] = '\0';

    // Get key from user
    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key_length = strlen(key);

    // Remove newline character
    key[key_length - 1] = '\0';

    // Convert message and key to uppercase
    for (i = 0; i < message_length; i++) {
        message[i] = toupper(message[i]);
    }
    for (i = 0; i < key_length; i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt message
    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isalpha(key[j])) {
                message[i] = 'A' + ((message[i] - 'A' + key[j] - 'A') % 26);
            } else {
                message[i] = 'A' + ((message[i] - 'A' + key[j] - 'A' - 1) % 26);
            }
        } else {
            message[i] = message[i];
        }
        j = (j + 1) % key_length;
    }

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}