//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Caesar cipher encryption function
char *caesar_encrypt(char *plaintext, int key) {
    int i;
    int len = strlen(plaintext);
    char *ciphertext = malloc(len + 1);
    for (i = 0; i < len; i++) {
        ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Caesar cipher decryption function
char *caesar_decrypt(char *ciphertext, int key) {
    int i;
    int len = strlen(ciphertext);
    char *plaintext = malloc(len + 1);
    for (i = 0; i < len; i++) {
        plaintext[i] = (ciphertext[i] - 'a' - key + 26) % 26 + 'a';
    }
    plaintext[len] = '\0';
    return plaintext;
}

// Vigenere cipher encryption function
char *vigenere_encrypt(char *plaintext, char *key) {
    int i;
    int j;
    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);
    char *ciphertext = malloc(plaintext_len + 1);
    for (i = 0; i < plaintext_len; i++) {
        ciphertext[i] = (plaintext[i] - 'a' + key[i % key_len] - 'a') % 26 + 'a';
    }
    ciphertext[plaintext_len] = '\0';
    return ciphertext;
}

// Vigenere cipher decryption function
char *vigenere_decrypt(char *ciphertext, char *key) {
    int i;
    int j;
    int key_len = strlen(key);
    int ciphertext_len = strlen(ciphertext);
    char *plaintext = malloc(ciphertext_len + 1);
    for (i = 0; i < ciphertext_len; i++) {
        plaintext[i] = (ciphertext[i] - 'a' - key[i % key_len] + 'a' + 26) % 26 + 'a';
    }
    plaintext[ciphertext_len] = '\0';
    return plaintext;
}

// Playfair cipher encryption function
char *playfair_encrypt(char *plaintext, char *key) {
    int i;
    int j;
    int k;
    int plaintext_len = strlen(plaintext);
    char *ciphertext = malloc(plaintext_len + 1);
    char key_matrix[5][5];

    // Create the key matrix
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            key_matrix[i][j] = key[i * 5 + j];
        }
    }

    // Process the plaintext in pairs
    for (i = 0; i < plaintext_len; i += 2) {
        // Get the indices of the two characters in the key matrix
        int row1 = (plaintext[i] - 'a') / 5;
        int col1 = (plaintext[i] - 'a') % 5;
        int row2 = (plaintext[i + 1] - 'a') / 5;
        int col2 = (plaintext[i + 1] - 'a') % 5;

        // Perform the encryption
        if (row1 == row2) {
            ciphertext[i] = key_matrix[row1][(col1 + 1) % 5];
            ciphertext[i + 1] = key_matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            ciphertext[i] = key_matrix[(row1 + 1) % 5][col1];
            ciphertext[i + 1] = key_matrix[(row2 + 1) % 5][col2];
        } else {
            ciphertext[i] = key_matrix[row1][col2];
            ciphertext[i + 1] = key_matrix[row2][col1];
        }
    }

    ciphertext[plaintext_len] = '\0';
    return ciphertext;
}

// Playfair cipher decryption function
char *playfair_decrypt(char *ciphertext, char *key) {
    int i;
    int j;
    int k;
    int ciphertext_len = strlen(ciphertext);
    char *plaintext = malloc(ciphertext_len + 1);
    char key_matrix[5][5];

    // Create the key matrix
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            key_matrix[i][j] = key[i * 5 + j];
        }
    }

    // Process the ciphertext in pairs
    for (i = 0; i < ciphertext_len; i += 2) {
        // Get the indices of the two characters in the key matrix
        int row1 = (ciphertext[i] - 'a') / 5;
        int col1 = (ciphertext[i] - 'a') % 5;
        int row2 = (ciphertext[i + 1] - 'a') / 5;
        int col2 = (ciphertext[i + 1] - 'a') % 5;

        // Perform the decryption
        if (row1 == row2) {
            plaintext[i] = key_matrix[row1][(col1 - 1 + 5) % 5];
            plaintext[i + 1] = key_matrix[row2][(col2 - 1 + 5) % 5];
        } else if (col1 == col2) {
            plaintext[i] = key_matrix[(row1 - 1 + 5) % 5][col1];
            plaintext[i + 1] = key_matrix[(row2 - 1 + 5) % 5][col2];
        } else {
            plaintext[i] = key_matrix[row1][col2];
            plaintext[i + 1] = key_matrix[row2][col1];
        }
    }

    plaintext[ciphertext_len] = '\0';
    return plaintext;
}

int main() {
    char *plaintext = "attackatdawn";
    char *key = "playfair";
    char *ciphertext;

    // Encrypt the plaintext using the Caesar cipher
    ciphertext = caesar_encrypt(plaintext, 3);
    printf("Caesar cipher ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the Caesar cipher
    plaintext = caesar_decrypt(ciphertext, 3);
    printf("Caesar cipher plaintext: %s\n", plaintext);

    // Encrypt the plaintext using the Vigenere cipher
    ciphertext = vigenere_encrypt(plaintext, key);
    printf("Vigenere cipher ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the Vigenere cipher
    plaintext = vigenere_decrypt(ciphertext, key);
    printf("Vigenere cipher plaintext: %s\n", plaintext);

    // Encrypt the plaintext using the Playfair cipher
    ciphertext = playfair_encrypt(plaintext, key);
    printf("Playfair cipher ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the Playfair cipher
    plaintext = playfair_decrypt(ciphertext, key);
    printf("Playfair cipher plaintext: %s\n", plaintext);

    return 0;
}