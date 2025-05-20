//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char* message, int key) {
    int i, len = strlen(message);
    for(i=0; i<len; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (char) (((int) message[i] - 65 + key) % 26 + 65);
            } else {
                message[i] = (char) (((int) message[i] - 97 + key) % 26 + 97);
            }
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char* message, int key) {
    int i, len = strlen(message);
    for(i=0; i<len; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (char) (((int) message[i] - 65 - key + 26) % 26 + 65);
            } else {
                message[i] = (char) (((int) message[i] - 97 - key + 26) % 26 + 97);
            }
        }
    }
}

// Function to generate a random key between 1 and 25
int generateKey() {
    int key = rand() % 26 + 1;
    return key;
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    int key = generateKey();

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}