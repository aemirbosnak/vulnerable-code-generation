//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MSG_LEN 1000
#define MAX_KEY_LEN 10
#define ALPHABET_LEN 26

// Function to encrypt the message using Caesar cipher
void encrypt(char* msg, int key, char* result) {
    int i = 0;
    while (msg[i]!= '\0') {
        if (isalpha(msg[i])) {
            result[i] = (char) ((msg[i] + key - 65) % 26 + 65);
        } else {
            result[i] = msg[i];
        }
        i++;
    }
    result[i] = '\0';
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* msg, int key, char* result) {
    int i = 0;
    while (msg[i]!= '\0') {
        if (isalpha(msg[i])) {
            result[i] = (char) ((msg[i] - key - 65) % 26 + 65);
        } else {
            result[i] = msg[i];
        }
        i++;
    }
    result[i] = '\0';
}

// Function to generate a random key
void generate_key(char* key, int len) {
    int i;
    for (i = 0; i < len; i++) {
        key[i] = (char) (rand() % 26 + 65);
    }
    key[len] = '\0';
}

// Function to get a string input from user
void get_input(char* str, int max_len) {
    printf("Enter %s: ", str);
    fgets(str, max_len, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    char msg[MAX_MSG_LEN], key[MAX_KEY_LEN], result[MAX_MSG_LEN];
    int len, i;

    // Get message from user
    printf("Enter message to encrypt/decrypt: ");
    get_input(msg, MAX_MSG_LEN);

    // Get key from user
    printf("Enter key (1-9): ");
    scanf("%d", &len);
    generate_key(key, len);

    // Encrypt message
    encrypt(msg, len, result);
    printf("Encrypted message: %s\n", result);

    // Decrypt message
    decrypt(result, len, msg);
    printf("Decrypted message: %s\n", msg);

    return 0;
}