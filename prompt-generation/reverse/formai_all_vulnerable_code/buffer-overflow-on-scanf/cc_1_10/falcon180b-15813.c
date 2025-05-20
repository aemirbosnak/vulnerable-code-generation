//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 64

// Function to swap two characters in a string
void swap(char* str, int i, int j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

// Function to generate a random key
void generate_key(char* key) {
    srand(time(NULL));
    for(int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

// Function to encrypt a message using the Vigenere cipher
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char* result = malloc(message_length+1);
    for(int i = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if(isalpha(c)) {
            int index = tolower(key[i % key_length]) - 'a';
            c = (c - 'a' + index) % 26 + 'a';
        }
        result[i] = c;
    }
    result[message_length] = '\0';
    printf("Encrypted message: %s\n", result);
}

// Function to decrypt a message using the Vigenere cipher
void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char* result = malloc(message_length+1);
    for(int i = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if(isalpha(c)) {
            int index = tolower(key[i % key_length]) - 'a';
            c = (c - 'a' + 26 - index) % 26 + 'a';
        }
        result[i] = c;
    }
    result[message_length] = '\0';
    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[1000];
    char key[KEY_SIZE+1];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    generate_key(key);
    encrypt(message, key);
    printf("Enter the encrypted message: ");
    scanf("%s", message);
    decrypt(message, key);
    return 0;
}