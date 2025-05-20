//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to encrypt message
void encrypt(char *message, int key) {
    int i, j;
    char ch;

    // loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        // get the ASCII value of the character
        ch = message[i];

        // shift the ASCII value by the key
        ch = (ch + key) % 256;

        // convert the ASCII value back to a character
        message[i] = ch;
    }
}

// function to decrypt message
void decrypt(char *message, int key) {
    int i, j;
    char ch;

    // loop through each character in the message
    for (i = 0; message[i]!= '\0'; i++) {
        // get the ASCII value of the character
        ch = message[i];

        // shift the ASCII value by the key
        ch = (ch - key + 256) % 256;

        // convert the ASCII value back to a character
        message[i] = ch;
    }
}

// function to generate a random key
int generate_key() {
    int key;
    srand(time(NULL));
    key = rand() % 256;
    return key;
}

int main() {
    char message[100];
    int key;

    // get the message from the user
    printf("Enter a message to encrypt: ");
    scanf("%[^\n]", message);

    // generate a random key
    key = generate_key();

    // encrypt the message
    encrypt(message, key);

    // display the encrypted message
    printf("Encrypted message: %s\n", message);

    // generate the same key for decryption
    key = generate_key();

    // decrypt the message
    decrypt(message, key);

    // display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}