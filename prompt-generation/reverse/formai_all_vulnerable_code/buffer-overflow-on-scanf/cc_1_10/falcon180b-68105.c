//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message
void encrypt(char* message, char* key) {
    int i, j, n = strlen(message);
    char cipher[n];

    // Create a table for the key
    char table[26];
    for (i = 0; i < 26; i++) {
        table[i] = i + (int)key[0] - 97;
        if (table[i] > 25) {
            table[i] -= 26;
        }
    }

    // Encrypt the message
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            j = tolower(message[i]) - 97;
            cipher[i] = table[j];
        } else {
            cipher[i] = message[i];
        }
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", cipher);
}

// Function to decrypt a message
void decrypt(char* message, char* key) {
    int i, j, n = strlen(message);
    char plain[n];

    // Create a table for the key
    char table[26];
    for (i = 0; i < 26; i++) {
        table[i] = i - (int)key[0] + 97;
        if (table[i] < 97) {
            table[i] += 26;
        }
    }

    // Decrypt the message
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            j = table[message[i] - 97];
            plain[i] = j < 97? j + 26 : j;
        } else {
            plain[i] = message[i];
        }
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", plain);
}

// Function to generate a random key
void generate_key(char* key) {
    int i;
    for (i = 0; i < 5; i++) {
        key[i] = rand() % 26 + 97;
    }
    key[5] = '\0';
}

int main() {
    char message[100], key[6];

    // Generate a random key
    generate_key(key);

    // Encrypt the message
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    encrypt(message, key);

    // Decrypt the encrypted message
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);

    return 0;
}