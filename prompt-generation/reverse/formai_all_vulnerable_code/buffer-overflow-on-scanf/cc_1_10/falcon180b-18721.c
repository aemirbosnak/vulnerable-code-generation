//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHABET_LENGTH 26

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, int key) {
    int i = 0;
    char encrypted_message[strlen(message)];
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = ALPHABET[(int)message[i] - 65 + key % 26];
            } else {
                encrypted_message[i] = ALPHABET[(int)message[i] - 97 + key % 26];
            }
        } else {
            encrypted_message[i] = message[i];
        }
        i++;
    }
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* message, int key) {
    int i = 0;
    char decrypted_message[strlen(message)];
    while (message[i]!= '\0') {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                decrypted_message[i] = ALPHABET[(int)message[i] - 65 - key % 26 + 26] % 26;
            } else {
                decrypted_message[i] = ALPHABET[(int)message[i] - 97 - key % 26 + 26] % 26;
            }
        } else {
            decrypted_message[i] = message[i];
        }
        i++;
    }
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}