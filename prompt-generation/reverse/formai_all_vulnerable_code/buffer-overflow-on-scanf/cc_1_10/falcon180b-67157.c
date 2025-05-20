//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Define the encryption key
#define KEY "Cyberpunk2021"

// Define the encryption function
void encrypt(char *message, int length) {
    char key[strlen(KEY)];
    strcpy(key, KEY);
    for (int i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }
    for (int i = 0; i < length; i++) {
        char letter = message[i];
        if (isalpha(letter)) {
            letter = tolower(letter);
            int index = letter - 'a';
            message[i] = key[index % strlen(key)];
        }
    }
}

// Define the decryption function
void decrypt(char *message, int length) {
    char key[strlen(KEY)];
    strcpy(key, KEY);
    for (int i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }
    for (int i = 0; i < length; i++) {
        char letter = message[i];
        if (isalpha(letter)) {
            letter = tolower(letter);
            int index = letter - 'a';
            message[i] = key[(index + 26) % strlen(key)];
        }
    }
}

// Define the main function
int main() {
    srand(time(NULL));
    char message[100];
    printf("Enter your message: ");
    scanf("%s", message);
    int length = strlen(message);
    printf("Encrypted message: ");
    encrypt(message, length);
    printf("\n");
    printf("Decrypted message: ");
    decrypt(message, length);
    printf("\n");
    return 0;
}