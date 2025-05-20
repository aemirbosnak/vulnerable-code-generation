//Falcon-180B DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_PLAIN_TEXT_SIZE 256

// Function to get the user input for key
void get_key(char *key, int key_size) {
    printf("Enter the encryption key (up to %d characters): ", key_size);
    scanf("%s", key);
}

// Function to encrypt the plaintext using the key
void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, k = 0;
    for (i = 0; plaintext[i]!= '\0'; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[k] = (char) ((int) plaintext[i] + (int) key[j]);
            j = (j + 1) % MAX_KEY_SIZE;
            k++;
        } else {
            ciphertext[k] = plaintext[i];
            k++;
        }
    }
    ciphertext[k] = '\0';
}

// Function to decrypt the ciphertext using the key
void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, k = 0;
    for (i = 0; ciphertext[i]!= '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[k] = (char) ((int) ciphertext[i] - (int) key[j]);
            j = (j + 1) % MAX_KEY_SIZE;
            k++;
        } else {
            plaintext[k] = ciphertext[i];
            k++;
        }
    }
    plaintext[k] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char plaintext[MAX_PLAIN_TEXT_SIZE];
    char ciphertext[MAX_PLAIN_TEXT_SIZE];

    // Get the key from the user
    get_key(key, MAX_KEY_SIZE);

    // Get the plaintext from the user
    printf("Enter the plaintext to encrypt (up to %d characters): ", MAX_PLAIN_TEXT_SIZE);
    scanf("%s", plaintext);

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);

    // Display the encrypted ciphertext
    printf("Encrypted Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, plaintext);

    // Display the decrypted plaintext
    printf("Decrypted Plaintext: %s\n", plaintext);

    return 0;
}