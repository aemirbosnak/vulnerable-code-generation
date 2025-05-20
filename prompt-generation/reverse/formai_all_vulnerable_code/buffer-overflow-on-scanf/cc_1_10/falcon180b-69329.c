//Falcon-180B DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define KEY "MySecretKey"
#define KEY_LENGTH 10

// Function to encrypt a string using a key
void encrypt(char* message, char* key, int key_length) {
    int i, j;
    char encrypted_message[1000];

    for(i = 0, j = 0; message[i]!= '\0'; i++) {
        if(isalpha(message[i])) {
            encrypted_message[j++] = (char) ((int) message[i] + (int) key[i % key_length]);
        } else {
            encrypted_message[j++] = message[i];
        }
    }

    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt a string using a key
void decrypt(char* encrypted_message, char* key, int key_length) {
    int i, j;
    char decrypted_message[1000];

    for(i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if(isalpha(encrypted_message[i])) {
            decrypted_message[j++] = (char) ((int) encrypted_message[i] - (int) key[i % key_length]);
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }

    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000];
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    encrypt(message, KEY, KEY_LENGTH);
    decrypt(message, KEY, KEY_LENGTH);

    return 0;
}