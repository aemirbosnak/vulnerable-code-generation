//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: curious
// In the enigmatic realm of cryptography, where secrets dance under the veil of obfuscation, a tale unfolds.

#include <stdio.h>
#include <string.h>

// Enter the labyrinth of characters, where each holds a key to a hidden world.
typedef unsigned char cipherByte;

// A curious function that shall embark on a journey into the heart of encryption.
char *encode(char *message, cipherByte *key, int keyLen) {
    int msgLen = strlen(message);
    char *encodedMsg = malloc(msgLen + 1); // One for the null terminator.

    // As the key whispers its secrets, each byte of the message transforms.
    for (int i = 0; i < msgLen; i++) {
        encodedMsg[i] = (message[i] ^ key[i % keyLen]) & 0xFF;
    }

    // The encoded message emerges, a tapestry of cryptic characters.
    encodedMsg[msgLen] = '\0'; // Seal the message with a null terminator.
    return encodedMsg;
}

// Now, let us unravel the enigma, guided by the key's guiding light.
char *decode(char *encodedMsg, cipherByte *key, int keyLen) {
    int encodedLen = strlen(encodedMsg);
    char *decodedMsg = malloc(encodedLen + 1);

    // With each step, the shrouded message slowly reveals its secrets.
    for (int i = 0; i < encodedLen; i++) {
        decodedMsg[i] = (encodedMsg[i] ^ key[i % keyLen]) & 0xFF;
    }

    // The decoded message emerges, its original form restored.
    decodedMsg[encodedLen] = '\0';
    return decodedMsg;
}

int main(void) {
    // Let the user whisper their secrets, and we shall guard them with the utmost care.
    printf("Enter a message to encrypt: ");
    char *message = malloc(1024); // Let's not limit our imagination.
    gets(message);

    // The key, a string of characters destined to protect the message's essence.
    printf("Enter a key (less than 256 characters): ");
    cipherByte key[256];
    gets((char *) key);

    // The key's length, a beacon guiding us through the encryption labyrinth.
    int keyLen = strlen((char *) key);

    // Invoke the encryption ritual, transforming the message into an enigmatic code.
    char *encodedMsg = encode(message, key, keyLen);

    // As the user peers into the encrypted message, they witness the power of the key.
    printf("Encoded Message: %s\n", encodedMsg);

    // Now, let us break the seal, returning the message to its original form.
    char *decodedMsg = decode(encodedMsg, key, keyLen);

    // The decoded message emerges, its secrets revealed once more.
    printf("Decoded Message: %s\n", decodedMsg);

    // Our duty fulfilled, we release the resources held captive by this cryptic adventure.
    free(message);
    free(encodedMsg);
    free(decodedMsg);
    return 0;
}