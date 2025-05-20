//FormAI DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

/* Function to encrypt the given message */
char* encrypt(char* message, int key) {
    int i;
    char* result = (char*)malloc(MAX_SIZE * sizeof(char));
    for(i = 0; message[i] != '\0'; i++) {
        /* Encrypt uppercase characters */
        if(message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = ((message[i] - 'A') + key) % 26 + 'A';
        }
        /* Encrypt lowercase characters */
        else if(message[i] >= 'a' && message[i] <= 'z') {
            result[i] = ((message[i] - 'a') + key) % 26 + 'a';
        }
        /* Leave spaces untouched */
        else if (message[i] == ' ') {
            result[i] = ' ';
        }
    }
    result[i] = '\0'; /* Add null character at end of string */
    return result;
}

/* Function to decrypt the given message */
char* decrypt(char* message, int key) {
    int i;
    char* result = (char*)malloc(MAX_SIZE * sizeof(char));
    for(i = 0; message[i] != '\0'; i++) {
        /* Decrypt uppercase characters */
        if(message[i] >= 'A' && message[i] <= 'Z') {
            result[i] = ((message[i] - 'A') - key + 26) % 26 + 'A';
        }
        /* Decrypt lowercase characters */
        else if(message[i] >= 'a' && message[i] <= 'z') {
            result[i] = ((message[i] - 'a') - key + 26) % 26 + 'a';
        }
        /* Leave spaces untouched */
        else if(message[i] == ' ') {
            result[i] = ' ';
        }
    }
    result[i] = '\0'; /* Add null character at end of string */
    return result;
}

int main() {
    char message[MAX_SIZE], *ciphertext, *plaintext;
    int key;

    /* Get user input */
    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter the key: ");
    scanf("%d", &key);

    /* Call encrypt function */
    ciphertext = encrypt(message, key);
    printf("Encrypted message: %s\n", ciphertext);

    /* Call decrypt function */
    plaintext = decrypt(ciphertext, key);
    printf("Decrypted message: %s\n", plaintext);

    /* Deallocate memory used for ciphertext and plaintext */
    free(ciphertext);
    free(plaintext);

    return 0;
}