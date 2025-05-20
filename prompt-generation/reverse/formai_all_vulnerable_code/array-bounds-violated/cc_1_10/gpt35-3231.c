//FormAI DATASET v1.0 Category: Modern Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 1000

int main() {
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    char key[MAX_LEN];
    int i, j, k, p_len, k_len, c_len;
    
    printf("Enter the plaintext to be encrypted: ");
    fgets(plaintext, MAX_LEN, stdin);
    p_len = strlen(plaintext);
    plaintext[p_len - 1] = '\0'; // Remove the newline character
    
    printf("Enter the encryption key: ");
    fgets(key, MAX_LEN, stdin);
    k_len = strlen(key);
    key[k_len - 1] = '\0'; // Remove the newline character
    
    // Convert the plaintext to uppercase and remove non-alphabetic characters
    for (i = 0, j = 0; i < p_len; i++) {
        if (isalpha(plaintext[i])) {
            plaintext[j] = toupper(plaintext[i]);
            j++;
        }
    }
    plaintext[j] = '\0'; // Null-terminate the plaintext
    
    // Convert the key to uppercase and remove non-alphabetic characters
    for (i = 0, j = 0; i < k_len; i++) {
        if (isalpha(key[i])) {
            key[j] = toupper(key[i]);
            j++;
        }
    }
    key[j] = '\0'; // Null-terminate the key
    
    k_len = strlen(key);
    p_len = strlen(plaintext);
    
    // Check if the key is longer than the plaintext
    if (k_len > p_len) {
        printf("Error: The key length cannot be greater than the plaintext length.\n");
        return 1;
    }
    
    // Generate the ciphertext by applying the Vigenere cipher
    for (i = 0, j = 0; i < p_len; i++, j++) {
        if (j == k_len) {
            j = 0;
        }
        k = key[j] - 'A';
        ciphertext[i] = (((plaintext[i] - 'A') + k) % 26) + 'A';
    }
    ciphertext[p_len] = '\0'; // Null-terminate the ciphertext
    
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);
    
    return 0;
}