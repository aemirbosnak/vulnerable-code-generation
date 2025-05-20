//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* A simple implementation of the Caesar Cipher using C */

// function to encrypt plaintext using Caesar Cipher
char *caesar_encrypt(char *plaintext, int key) {
    int len = strlen(plaintext);
    char *ciphertext = (char *) malloc(len * sizeof(char)); // allocate memory for ciphertext
    for (int i = 0; i < len; i++) {
        ciphertext[i] = (plaintext[i] + key - 65) % 26 + 65; // apply Caesar Cipher formula
    }
    ciphertext[len] = '\0'; // terminate the ciphertext string
    return ciphertext;
}

// function to decrypt ciphertext using Caesar Cipher
char *caesar_decrypt(char *ciphertext, int key) {
    int len = strlen(ciphertext);
    char *plaintext = (char *) malloc(len * sizeof(char)); // allocate memory for plaintext
    for (int i = 0; i < len; i++) {
        plaintext[i] = (ciphertext[i] - key - 65 + 26) % 26 + 65; // apply inverse Caesar Cipher formula
    }
    plaintext[len] = '\0'; // terminate the plaintext string
    return plaintext;
}

int main() {
    char plaintext[100]; // assume plaintext length does not exceed 100
    int key;
    bool valid_key = false;
    while (!valid_key) {
        printf("Enter key (1-25): ");
        scanf("%d", &key);
        if (key >= 1 && key <= 25) {
            valid_key = true; // if key is between 1 and 25, set valid_key flag to true
        } else {
            printf("Invalid key! Please enter a key between 1 and 25.\n");
        }
    }
    printf("Enter plaintext: ");
    getchar(); // absorb the newline character from previous scanf()
    fgets(plaintext, 100, stdin); // read plaintext using fgets
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove newline character from plaintext
    char *ciphertext = caesar_encrypt(plaintext, key); // encrypt plaintext using Caesar Cipher
    printf("Ciphertext: %s\n", ciphertext);
    char *decrypted_text = caesar_decrypt(ciphertext, key); // decrypt ciphertext using Caesar Cipher
    printf("Decrypted Text: %s\n", decrypted_text);
    free(ciphertext); // free memory used for ciphertext
    free(decrypted_text); // free memory used for plaintext after decryption
    return 0;
}