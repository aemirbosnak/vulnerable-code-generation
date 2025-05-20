//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random key
void generateKey(char* key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// function to encrypt a message using the Vigenere cipher
void encrypt(char* message, char* key, char* encrypted) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    for (int i = 0; i < messageLength; i++) {
        if (isalpha(message[i])) {
            encrypted[i] = (message[i] - 'a' + key[i % keyLength] - 'a') % 26 + 'a';
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[messageLength] = '\0';
}

// function to decrypt a message using the Vigenere cipher
void decrypt(char* encrypted, char* key, char* decrypted) {
    int encryptedLength = strlen(encrypted);
    int keyLength = strlen(key);
    for (int i = 0; i < encryptedLength; i++) {
        if (isalpha(encrypted[i])) {
            decrypted[i] = (encrypted[i] - 'a' + 'z' - key[i % keyLength] + 26) % 26 + 'a';
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[encryptedLength] = '\0';
}

int main() {
    char message[100];
    char key[100];
    char encrypted[100];
    char decrypted[100];

    // get message from user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // generate random key
    generateKey(key, strlen(message));

    // encrypt message
    encrypt(message, key, encrypted);

    // print encrypted message
    printf("Encrypted message: %s\n", encrypted);

    // decrypt message
    decrypt(encrypted, key, decrypted);

    // print decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}