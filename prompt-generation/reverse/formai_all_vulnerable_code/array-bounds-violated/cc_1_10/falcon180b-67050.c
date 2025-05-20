//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_MESSAGE_SIZE 1000

int main() {
    char key[MAX_KEY_SIZE], message[MAX_MESSAGE_SIZE];
    int key_size, message_size;

    // Get the key from the user
    printf("Enter a key (up to %d characters): ", MAX_KEY_SIZE - 1);
    fgets(key, MAX_KEY_SIZE, stdin);
    key_size = strlen(key);

    // Get the message from the user
    printf("Enter a message (up to %d characters): ", MAX_MESSAGE_SIZE - 1);
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message_size = strlen(message);

    // Remove any trailing newline characters from the key and message
    key[key_size - 1] = '\0';
    message[message_size - 1] = '\0';

    // Encrypt the message using the key
    int i, j, k, n;
    for (i = 0, j = 0; i < message_size; i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            n = message[i] - 'a';

            // Apply the key to the message character
            for (k = 0; k < key_size; k++) {
                n = (n + key[k] - 'a') % 26;
            }

            // Convert the encrypted character back to uppercase and add to the output message
            message[i] = toupper((char) (n + 'a'));
        } else {
            message[i] = message[i];
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}