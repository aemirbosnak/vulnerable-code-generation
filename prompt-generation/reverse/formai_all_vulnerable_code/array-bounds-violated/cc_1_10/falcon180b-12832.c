//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

int main() {
    int i, j;
    char message[SIZE], key[SIZE], cipher[SIZE];
    int key_length, message_length;
    int temp;

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, SIZE, stdin);
    message_length = strlen(message);

    // Get key from user
    printf("Enter key: ");
    fgets(key, SIZE, stdin);
    key_length = strlen(key);

    // Remove newline character from key
    temp = strlen(key) - 1;
    key[temp] = '\0';

    // Check if key is valid
    if (key_length > SIZE) {
        printf("Error: Key is too long.\n");
        return 0;
    }

    // Encrypt message
    for (i = 0; i < message_length; i++) {
        cipher[i] = message[i];
    }

    for (i = 0, j = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                cipher[i] = ((message[i] - 65 + key[j] - 65) % 26) + 65;
            } else {
                cipher[i] = ((message[i] - 97 + key[j] - 97) % 26) + 97;
            }
            j++;
            if (j == key_length) {
                j = 0;
            }
        }
    }

    // Output cipher
    printf("Cipher: %s\n", cipher);

    return 0;
}