//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define BITS 16 // set number of bits in ciphertext

// Function to generate random key
char *keygen()
{
    static char key[BITS];
    int i, r;
    srand(time(NULL));
    for(i=0; i<BITS; i++)
    {
        r = rand() % 2;
        if(r == 0){
            key[i] = '0';
        } 
        else{
            key[i] = '1';
        }
    }
    key[i] = '\0';

    return key;
} 

// XOR cipher function
char *xor_cipher(char *plaintext, char *key)
{
    int i, len;
    len = strlen(plaintext);

    // Allocate memory for ciphertext
    char *ciphertext = (char*) malloc(len * sizeof(char));
    for(i=0; i<len; i++){
        ciphertext[i] = plaintext[i] ^ key[i%(BITS-1)];
    }
    ciphertext[i] = '\0';

    return ciphertext;
}

// Main function
int main() 
{
    char *plaintext = "this is a secret message";
    char *key = keygen();
    char *ciphertext = xor_cipher(plaintext, key);

    printf("Plaintext : %s\n", plaintext);
    printf("Key : %s\n", key);
    printf("Ciphertext : %s\n", ciphertext);

    free(ciphertext);

    return 0;
}