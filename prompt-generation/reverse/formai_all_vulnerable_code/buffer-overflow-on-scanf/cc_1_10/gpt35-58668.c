//FormAI DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementation of Modern Encryption method - Rabin-Karp algorithm
/*
 Rabin-Karp algorithm is a string searching algorithm that searches for a pattern in a larger text by hashing the pattern 
 and then comparing the hash value to that of different substrings of the text.
*/

#define d 256 // Number of characters in the input alphabet
#define q 101 // Prime number used for hashing

// Function to perform encryption using Rabin-Karp algorithm
void encrypt(char* plaintext, char* key){
    int n = strlen(plaintext);
    int m = strlen(key);
    int i, j;
    int p = 0;  // Hash value for pattern
    int t = 0;  // Hash value for text
    int h = 1;  // Hash value for d^(m-1)

    // Calculate the hash value of pattern and the hash value of first m-length substring of the plaintext
    for (i = 0; i < m; i++){
        p = (d * p + key[i]) % q;
        t = (d * t + plaintext[i]) % q;
    }

    // Calculate the hash value of h = d^(m-1)
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Slide the pattern over the plaintext and compare hash values of pattern and substring
    for (i = 0; i <= n - m; i++){
        // Check if hash values of pattern and substring match
        if (p == t){
            // Check if pattern and substring match character by character
            for (j = 0; j < m; j++){
                if (plaintext[i+j] != key[j])
                    break;
            }
            if (j == m){ // Complete match found
                // Shift each character in the plaintext by corresponding character in key
                for (j = 0; j < m; j++)
                    plaintext[i+j] += key[j];
            }
        }
        // Calculate hash value of next substring of length m
        if (i < n - m){
            t = (d * (t - plaintext[i]*h) + plaintext[i+m]) % q;  // subtracting the first digit (Leftmost) and adding the next digit (Rightmost)
            if (t < 0)
                t = (t + q);  // Modulo correction for negative values
        }
    }
}

// Function to perform decryption using Rabin-Karp algorithm
void decrypt(char* ciphertext, char* key){
    int n = strlen(ciphertext);
    int m = strlen(key);
    int i, j;
    int p = 0;  // Hash value for pattern
    int t = 0;  // Hash value for text
    int h = 1;  // Hash value for d^(m-1)

    // Calculate the hash value of pattern and the hash value of first m-length substring of the ciphertext
    for (i = 0; i < m; i++){
        p = (d * p + key[i]) % q;
        t = (d * t + ciphertext[i]) % q;
    }

    // Calculate the hash value of h = d^(m-1)
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Slide the pattern over the ciphertext and compare hash values of pattern and substring
    for (i = 0; i <= n - m; i++){
        // Check if hash values of pattern and substring match
        if (p == t){
            // Check if pattern and substring match character by character
            for (j = 0; j < m; j++){
                if (ciphertext[i+j] - key[j] < 0 || ciphertext[i+j] - key[j] > 255){
                    // Decryption failed, reset ciphertext to original value
                    for (j = 0; j < m; j++)
                        ciphertext[i+j] -= key[j];
                    break;
                }
                ciphertext[i+j] -= key[j];
            }
            if (j == m){ // Complete match found and decrypted
                break;
            }
        }
        // Calculate hash value of next substring of length m
        if (i < n - m){
            t = (d * (t - ciphertext[i]*h) + ciphertext[i+m]) % q;  // subtracting the first digit (Leftmost) and adding the next digit (Rightmost)
            if (t < 0)
                t = (t + q);  // Modulo correction for negative values
        }
    }
}

int main(){
    printf("Enter plaintext: ");
    char plaintext[1000];
    scanf("%[^\n]s", plaintext);
    getchar();

    printf("Enter encryption key: ");
    char key[100];
    scanf("%[^\n]s", key);
    getchar();

    encrypt(plaintext, key);
    printf("Encrypted ciphertext: %s\n", plaintext);

    decrypt(plaintext, key);
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}