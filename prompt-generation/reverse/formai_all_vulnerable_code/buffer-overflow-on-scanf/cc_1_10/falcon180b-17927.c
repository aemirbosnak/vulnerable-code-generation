//Falcon-180B DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

void apply_key(char* message, char* key, int key_length) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = toupper(message[i] + key[j]);
            } else {
                message[i] = tolower(message[i] + key[j]);
            }
            j = (j + 1) % key_length;
        } else {
            message[i] = message[i];
        }
    }
}

void generate_key(char* key, int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int message_length, key_length;

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    message_length = strlen(message);

    // Get key length from user
    printf("Enter key length (1-100): ");
    scanf("%d", &key_length);

    // Generate key
    generate_key(key, key_length);

    // Apply key to message
    apply_key(message, key, key_length);

    // Output encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}