//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16

int main() {
    char message[100];
    char key[KEY_LENGTH];
    char encrypted_message[100];
    char decrypted_message[100];
    int i, j, k;
    int key_index = 0;

    // Get message from user
    printf("Enter message: ");
    scanf("%s", message);

    // Get key from user
    printf("Enter key (must be %d characters long): ", KEY_LENGTH);
    for (i = 0; i < KEY_LENGTH; i++) {
        scanf("%c", &key[i]);
    }

    // Encrypt message
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (message[i] + key[key_index] - 65) % 26 + 65;
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0';

    // Decrypt message
    for (i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (encrypted_message[i] - key[key_index] - 65) % 26 + 65;
            key_index = (key_index + 1) % KEY_LENGTH;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[strlen(encrypted_message)] = '\0';

    // Print encrypted and decrypted messages
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}