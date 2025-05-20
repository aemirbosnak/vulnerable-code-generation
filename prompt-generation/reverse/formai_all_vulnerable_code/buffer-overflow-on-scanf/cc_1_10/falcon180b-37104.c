//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the key and plaintext/ciphertext
typedef struct {
    char key[16];
    char plaintext[100];
    char ciphertext[100];
} message;

// Function to encrypt the plaintext using the key
void encrypt(message *m) {
    int i, j, k = 0;
    char temp;
    
    // XOR each character in the plaintext with the corresponding character in the key
    for (i = 0; i < strlen(m->plaintext); i++) {
        temp = m->plaintext[i];
        m->ciphertext[i] = temp ^ m->key[k];
        k = (k+1) % 16;
    }
}

// Function to decrypt the ciphertext using the key
void decrypt(message *m) {
    int i, j, k = 0;
    char temp;
    
    // XOR each character in the ciphertext with the corresponding character in the key
    for (i = 0; i < strlen(m->ciphertext); i++) {
        temp = m->ciphertext[i];
        m->plaintext[i] = temp ^ m->key[k];
        k = (k+1) % 16;
    }
}

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[15] = '\0';
}

int main() {
    message m;
    char key[16];
    
    // Generate a random key
    generate_key(key);
    
    // Prompt the user to enter a plaintext message
    printf("Enter a message to encrypt:\n");
    scanf("%s", m.plaintext);
    
    // Encrypt the plaintext using the key
    encrypt(&m);
    
    // Print the ciphertext
    printf("Encrypted message: %s\n", m.ciphertext);
    
    // Decrypt the ciphertext using the key
    decrypt(&m);
    
    // Print the plaintext
    printf("Decrypted message: %s\n", m.plaintext);
    
    return 0;
}