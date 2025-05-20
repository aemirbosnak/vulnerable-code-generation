//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 256

int main() {
    char message[1000];
    char key[MAX_KEY_SIZE];
    int key_size;
    char encrypted_message[1000];
    char decrypted_message[1000];

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%[^\n]", message);

    // Get key from user
    printf("Enter encryption key: ");
    scanf("%s", key);
    key_size = strlen(key);

    // Encrypt message using Caesar cipher
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = 'A' + ((message[i] - 'A' + key_size) % 26);
            } else {
                encrypted_message[i] = 'a' + ((message[i] - 'a' + key_size) % 26);
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }

    // Display encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message using Caesar cipher
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                decrypted_message[i] = 'A' + ((encrypted_message[i] - 'A' - key_size + 26) % 26);
            } else {
                decrypted_message[i] = 'a' + ((encrypted_message[i] - 'a' - key_size + 26) % 26);
            }
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    // Display decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}