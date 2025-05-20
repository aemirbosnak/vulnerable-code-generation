//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to shift a character by a given amount
char shift_char(char c, int amount) {
    if (isupper(c)) {
        return toupper((c - amount + 26) % 26 + 'A');
    } else if (islower(c)) {
        return tolower((c - amount + 26) % 26 + 'a');
    } else {
        return c;
    }
}

// Function to encrypt a message using a given key
void encrypt(char* message, char* key) {
    int key_index = 0;
    char encrypted_message[strlen(message)];
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = shift_char(message[i], key[key_index] - 'A');
        key_index++;
        if (key_index >= strlen(key)) {
            key_index = 0;
        }
    }
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt a message using a given key
void decrypt(char* message, char* key) {
    int key_index = 0;
    char decrypted_message[strlen(message)];
    for (int i = 0; i < strlen(message); i++) {
        decrypted_message[i] = shift_char(message[i], 'A' - key[key_index]);
        key_index++;
        if (key_index >= strlen(key)) {
            key_index = 0;
        }
    }
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    char key[100];
    printf("Enter a message: ");
    scanf("%s", message);
    printf("Enter a key: ");
    scanf("%s", key);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}