//Falcon-180B DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32

void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    // If the key is too long, truncate it
    if (key_length > MAX_KEY_LENGTH) {
        key_length = MAX_KEY_LENGTH;
    }

    // Initialize the encryption table
    int table[256] = {0};
    for (int i = 0; i < key_length; i++) {
        table[(int)key[i]] = i;
    }

    // Encrypt the message
    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            int key_index = (int)toupper(c);
            if (key_index >= 'A' && key_index <= 'Z') {
                key_index -= 'A';
            } else if (key_index >= 'a' && key_index <= 'z') {
                key_index -= 'a';
            } else {
                key_index = 0;
            }
            c = (char)table[key_index];
        }
        printf("%c", c);
    }
}

int main() {
    char message[1000];
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    char key[MAX_KEY_LENGTH];
    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);

    encrypt(message, key);

    return 0;
}