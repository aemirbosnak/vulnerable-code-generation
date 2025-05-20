//FormAI DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1000

int main() {
    char plaintext[2000], key[MAX_KEY_SIZE], ciphertext[2000];
    int i, j, k = 0;

    // Input plaintext
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof plaintext, stdin);

    // Input key
    printf("Enter key: ");
    fgets(key, sizeof key, stdin);

    // Calculate key length
    int keyLen = strlen(key);

    // Remove newline character from key
    key[keyLen - 1] = '\0';

    // Calculate plaintext length
    int plaintextLen = strlen(plaintext);

    // Encrypt the plaintext using the key
    for (i = 0; i < plaintextLen; i++) {
        // Get the ASCII code of the current character in the plaintext
        int asciiCode = plaintext[i];

        // Shift the ASCII code by the value of the current character in the key
        int shiftedAsciiCode = asciiCode + key[k % keyLen];

        // Wrap around if shiftedAsciiCode is greater than 127
        if (shiftedAsciiCode > 127) {
            shiftedAsciiCode = shiftedAsciiCode - 127 + 32;
        }

        // Store the shifted ASCII code in the ciphertext
        ciphertext[i] = shiftedAsciiCode;

        // Increment k
        k++;
    }

    // Print ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the key
    for (i = 0; i < plaintextLen; i++) {
        // Get the shifted ASCII code of the current character in the ciphertext
        int shiftedAsciiCode = ciphertext[i];

        // Shift the ASCII code back by the value of the current character in the key
        int asciiCode = shiftedAsciiCode - key[k % keyLen];

        // Wrap around if asciiCode is less than 32
        if (asciiCode < 32) {
            asciiCode = asciiCode + 127 - 32;
        }

        // Store the ASCII code in the plaintext
        plaintext[i] = asciiCode;

        // Increment k
        k++;
    }

    // Print plaintext
    printf("Plaintext: %s", plaintext);

    return 0;
}