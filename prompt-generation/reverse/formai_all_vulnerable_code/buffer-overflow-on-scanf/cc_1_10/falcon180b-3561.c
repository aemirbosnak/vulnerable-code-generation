//Falcon-180B DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

/* Function to generate a random key */
void generate_key(char* key) {
    int i;
    for(i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

/* Function to encrypt a message using the Vigenere cipher */
void vigenere_encrypt(char* message, char* key) {
    int i, j, k;
    char plaintext[100];
    for(i = 0; i < strlen(message); i++) {
        plaintext[i] = toupper(message[i]);
    }
    plaintext[i] = '\0';
    for(i = 0, j = 0; i < strlen(plaintext); i++) {
        if(isalpha(plaintext[i])) {
            k = toupper(plaintext[i]) - 'A';
            k = (k + j) % 26;
            if(isalpha(key[k])) {
                message[i] = key[k];
            } else {
                message[i] = plaintext[i];
            }
            j = (j + 1) % KEY_LENGTH;
        } else {
            message[i] = plaintext[i];
        }
    }
}

/* Function to decrypt a message using the Vigenere cipher */
void vigenere_decrypt(char* message, char* key) {
    int i, j, k;
    char plaintext[100];
    for(i = 0; i < strlen(message); i++) {
        plaintext[i] = toupper(message[i]);
    }
    plaintext[i] = '\0';
    for(i = 0, j = 0; i < strlen(plaintext); i++) {
        if(isalpha(plaintext[i])) {
            k = toupper(plaintext[i]) - 'A';
            k = (k - j + 26) % 26;
            if(isalpha(key[k])) {
                message[i] = key[k];
            } else {
                message[i] = plaintext[i];
            }
            j = (j + 1) % KEY_LENGTH;
        } else {
            message[i] = plaintext[i];
        }
    }
}

int main() {
    char message[100];
    char key[KEY_LENGTH + 1];
    int choice;
    char operation;

    /* Generate a random key */
    generate_key(key);

    /* Get the message from the user */
    printf("Enter the message: ");
    scanf("%s", message);

    /* Ask the user for the operation */
    printf("Enter the operation (E for encryption, D for decryption): ");
    scanf("%c", &operation);

    /* Perform the operation */
    switch(operation) {
        case 'E':
        case 'e':
            vigenere_encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 'D':
        case 'd':
            vigenere_decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}