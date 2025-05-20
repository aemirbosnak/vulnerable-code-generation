//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

/* Function to encrypt a string using a Caesar Cipher */
char* caesar_encrypt(char* plaintext, int shift) {
    int n = strlen(plaintext);
    char* ciphertext = (char*)malloc(n * sizeof(char));
    
    for (int i = 0; i < n; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = 'A' + ((plaintext[i] - 'A' + shift) % 26);
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = 'a' + ((plaintext[i] - 'a' + shift) % 26);
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    
    return ciphertext;
}

/* Function to decrypt a string using a Caesar Cipher */
char* caesar_decrypt(char* ciphertext, int shift) {
    int n = strlen(ciphertext);
    char* plaintext = (char*)malloc(n * sizeof(char));
    
    for (int i = 0; i < n; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = 'A' + ((ciphertext[i] - 'A' - shift + 26) % 26);
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = 'a' + ((ciphertext[i] - 'a' - shift + 26) % 26);
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    
    return plaintext;
}

int main() {
    char* plaintext = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
    char* ciphertext;
    char* decrypted;
    int shift;
    
    printf("Enter a string to encrypt: ");
    fgets(plaintext, MAX_STRING_LENGTH, stdin);
    
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    
    // Encrypt the plaintext
    ciphertext = caesar_encrypt(plaintext, shift);
    printf("Encrypted string: %s\n", ciphertext);
    
    // Decrypt the ciphertext
    decrypted = caesar_decrypt(ciphertext, shift);
    printf("Decrypted string: %s\n", decrypted);
    
    free(plaintext);
    free(ciphertext);
    free(decrypted);
    
    return 0;
}