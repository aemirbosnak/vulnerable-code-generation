//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_PLAIN_LENGTH 1024

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[MAX_KEY_LENGTH] = '\0';
}

// Function to encrypt a message using a key
void encrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (char) (((int) message[i] - 97 + (int) key[j % strlen(key)]) % 26 + 97);
            j++;
        }
    }
}

// Function to decrypt a message using a key
void decrypt(char* message, char* key) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (char) (((int) message[i] - 97 - (int) key[j % strlen(key)]) % 26 + 97);
            j++;
        }
    }
}

// Function to print a message in a retro style
void print_message(char* message) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            printf("%c", message[i]);
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    char message[MAX_PLAIN_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    // Generate key
    generate_key(key);

    // Encrypt message
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: ");
    print_message(message);

    // Decrypt message
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: ");
    print_message(message);

    return 0;
}