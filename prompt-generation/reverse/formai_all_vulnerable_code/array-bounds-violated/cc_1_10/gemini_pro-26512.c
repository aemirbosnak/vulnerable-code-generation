//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the Cyphertext Structure
typedef struct _Cyphertext {
    char *ciphertext;
    int length;
} Cyphertext;

// Define the Encryption Function
Cyphertext *encrypt(char *plaintext, char *key) {
    // Allocate memory for the ciphertext
    Cyphertext *ciphertext = (Cyphertext *)malloc(sizeof(Cyphertext));
    ciphertext->length = strlen(plaintext);
    ciphertext->ciphertext = (char *)malloc(ciphertext->length);

    // Perform encryption using XOR operation
    for (int i = 0; i < ciphertext->length; i++) {
        ciphertext->ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }

    // Return the ciphertext
    return ciphertext;
}

// Define the Decryption Function
char *decrypt(Cyphertext *ciphertext, char *key) {
    // Allocate memory for the plaintext
    char *plaintext = (char *)malloc(ciphertext->length);

    // Perform decryption using XOR operation
    for (int i = 0; i < ciphertext->length; i++) {
        plaintext[i] = ciphertext->ciphertext[i] ^ key[i % strlen(key)];
    }

    // Return the plaintext
    return plaintext;
}

// Define the main function
int main() {
    // Generate a random key
    srand(time(NULL));
    int keyLength = rand() % 10 + 5; // Key length between 5 and 15 characters
    char key[keyLength];
    for (int i = 0; i < keyLength; i++) {
        key[i] = rand() % 26 + 'a'; // Generate a random lowercase letter
    }
    key[keyLength] = '\0'; // Null-terminate the key

    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext to be encrypted: ");
    fgets(plaintext, 100, stdin);

    // Encrypt the plaintext
    Cyphertext *ciphertext = encrypt(plaintext, key);

    // Display the ciphertext
    printf("Ciphertext: %s\n", ciphertext->ciphertext);

    // Decrypt the ciphertext
    char *decryptedText = decrypt(ciphertext, key);

    // Display the decrypted text
    printf("Decrypted Text: %s\n", decryptedText);

    // Free the allocated memory
    free(ciphertext->ciphertext);
    free(ciphertext);
    free(decryptedText);

    return 0;
}