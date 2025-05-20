//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate a random key 
int generateKey(int keySize, int key[]) {
    int i;
    srand(time(NULL));
    for(i = 0; i < keySize; i++) {
        key[i] = rand() % 10;
    }
    return 0;
}

// Function to perform encryption using key 
int encryption(int numberOfCharacters, char text[], int keySize, int key[]) {
    int i, j, k = 0;
    for(i = 0; i < numberOfCharacters; i++) {
        j = (int) text[i];
        if(j == 32) continue; // ignore spaces
        text[i] = ((j - 65 + key[k]) % 26) + 65;
        k++;
        if(k == keySize) k = 0;
    }
    return 0;
}

// Function to perform decryption using key 
int decryption(int numberOfCharacters, char text[], int keySize, int key[]) {
    int i, j, k = 0;
    for(i = 0; i < numberOfCharacters; i++) {
        j = (int) text[i];
        if(j == 32) continue; // ignore spaces
        text[i] = (((j - 65) - key[k] + 26) % 26) + 65; 
        k++;
        if(k == keySize) k = 0;
    }
    return 0;
}

int main() {
    int i, n, keySize;
    printf("Enter the number of characters in the text: ");
    scanf("%d", &n);
    char text[n+1];
    printf("Enter the text to encrypt: ");
    scanf(" %[^\n]s", text);
    printf("Enter the size of the key (between 1 and 10): ");
    scanf("%d", &keySize);
    int key[keySize];
    generateKey(keySize, key);
    encryption(n, text, keySize, key);
    printf("Encrypted text: %s\n", text);
    decryption(n, text, keySize, key);
    printf("Decrypted text: %s\n", text);
    return 0;
}