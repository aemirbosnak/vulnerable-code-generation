//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LEN 16
#define MAX_SIZE 1024

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_LEN; i++) {
        key[i] = rand() % 26 + 'A'; // generate a random uppercase letter
    }
}

void encrypt(char *message, char *key) {
    int i, j;
    char temp[MAX_SIZE];
    strcpy(temp, message); // make a copy of the message
    for (i = 0; i < strlen(temp); i++) {
        if (isalpha(temp[i])) {
            temp[i] = toupper(temp[i]); // convert to uppercase
            temp[i] = temp[i] + key[i % KEY_LEN]; // encrypt using the key
            temp[i] = temp[i] % 26 + 'A'; // convert back to uppercase
        }
    }
    strcpy(message, temp); // overwrite the original message with the encrypted message
}

void decrypt(char *message, char *key) {
    int i, j;
    char temp[MAX_SIZE];
    strcpy(temp, message); // make a copy of the message
    for (i = 0; i < strlen(temp); i++) {
        if (isalpha(temp[i])) {
            temp[i] = toupper(temp[i]); // convert to uppercase
            temp[i] = temp[i] - key[i % KEY_LEN]; // decrypt using the key
            temp[i] = temp[i] % 26 + 'A'; // convert back to uppercase
        }
    }
    strcpy(message, temp); // overwrite the original message with the decrypted message
}

int main() {
    char message[MAX_SIZE];
    char key[KEY_LEN];
    int choice;

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    generate_key(key); // generate a random key

    printf("Encrypted message: %s\n", message);
    encrypt(message, key); // encrypt the message using the key
    printf("Decrypted message: %s\n", message);
    decrypt(message, key); // decrypt the message using the key

    return 0;
}