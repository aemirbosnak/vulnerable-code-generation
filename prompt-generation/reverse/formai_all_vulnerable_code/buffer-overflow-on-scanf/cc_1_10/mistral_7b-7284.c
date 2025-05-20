//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define KEY_SIZE 256
#define MESSAGE_SIZE 1024
#define ALPHABET_SIZE 26

// Cryptic Encryption Function
int encrypt(char key[KEY_SIZE], char message[MESSAGE_SIZE]) {
    int i, j, k;
    char temp;

    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            j = ((int)message[i] - 97 + (int)key[i % KEY_SIZE] - 97) % ALPHABET_SIZE;
            message[i] = (char) (j + 97);
        }
    }

    return 1;
}

// Cryptic Decryption Function
int decrypt(char key[KEY_SIZE], char encrypted_message[MESSAGE_SIZE]) {
    int i, j, k;
    char temp;

    for (i = 0; i < strlen(encrypted_message); i++) {
        if (encrypted_message[i] >= 'a' && encrypted_message[i] <= 'z') {
            j = ((int)encrypted_message[i] - 97 + KEY_SIZE - (int)key[i % KEY_SIZE] - 97 + ALPHABET_SIZE) % ALPHABET_SIZE;
            encrypted_message[i] = (char) (j + 97);
        }
    }

    return 1;
}

int main() {
    char key[KEY_SIZE], message[MESSAGE_SIZE], encrypted_message[MESSAGE_SIZE];
    int choice, len;

    printf("Enter the key (minimum %d characters): ", KEY_SIZE);
    scanf("%s", key);

    printf("\nEnter the message (minimum %d characters): ", MESSAGE_SIZE / 2);
    scanf("%s", message);
    len = strlen(message);

    // Cryptic Encryption
    encrypt(key, message);
    strcpy(encrypted_message, message);

    printf("\nEncrypted message: %s\n", encrypted_message);

    // Cryptic Decryption
    decrypt(key, encrypted_message);

    printf("\nDecrypted message: %s\n", message);

    return 0;
}