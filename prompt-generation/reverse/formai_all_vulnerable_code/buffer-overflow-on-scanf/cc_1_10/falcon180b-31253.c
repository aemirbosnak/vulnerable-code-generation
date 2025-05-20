//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Encryption function
void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j, k;
    int length = strlen(plaintext);

    // Generate the key matrix
    int key_matrix[length][length];
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            key_matrix[i][j] = key[j] + i;
        }
    }

    // Encrypt the plaintext
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            ciphertext[i * length + j] = plaintext[j * length + i] ^ key_matrix[i][j];
        }
    }
}

// Decryption function
void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i, j, k;
    int length = strlen(ciphertext);

    // Generate the key matrix
    int key_matrix[length][length];
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            key_matrix[i][j] = key[j] + i;
        }
    }

    // Decrypt the ciphertext
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            plaintext[j * length + i] = ciphertext[i * length + j] ^ key_matrix[i][j];
        }
    }
}

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];

    // Generate a random key
    srand(time(NULL));
    for (int i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }

    // Encrypt the plaintext
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, plaintext);
    printf("Original plaintext: %s\n", plaintext);

    return 0;
}