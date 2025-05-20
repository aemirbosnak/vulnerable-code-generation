//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate random key
void generate_key(char *key, int length){
    int i;
    for(i=0;i<length;i++){
        key[i] = 'A' + (rand() % 26);
    }
    key[length] = '\0';
}

// Function to perform XOR encryption
void encrypt(char *plaintext, int plaintext_len, char *key, int key_len, char *ciphertext){
    int i;
    for(i=0;i<plaintext_len;i++){
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }
    ciphertext[plaintext_len] = '\0';
}

// Function to perform XOR decryption
void decrypt(char *ciphertext, int ciphertext_len, char *key, int key_len, char *plaintext){
    int i;
    for(i=0;i<ciphertext_len;i++){
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }
    plaintext[ciphertext_len] = '\0';
}

int main(){
    char plaintext[1000], key[1000], ciphertext[1000], decrypted_plaintext[1000];
    int plaintext_len, key_len;

    // Input plaintext
    printf("Enter plaintext: ");
    scanf("%[^\n]s", plaintext);
    plaintext_len = strlen(plaintext);

    // Generate random key of same length as plaintext
    generate_key(key, plaintext_len);
    key_len = strlen(key);

    // Encrypt plaintext using XOR encryption
    encrypt(plaintext, plaintext_len, key, key_len, ciphertext);

    // Decrypt ciphertext using XOR decryption
    decrypt(ciphertext, plaintext_len, key, key_len, decrypted_plaintext);

    // Print results
    printf("\nPlaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return 0;
}