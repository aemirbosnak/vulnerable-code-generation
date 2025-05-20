//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void generate_key(char key[SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char message[100], char key[SIZE]) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char letter = toupper(message[i]);
            int index = letter - 'A';
            if (letter < 'Z') {
                message[i] = (key[index % SIZE] + letter) % 26 + 'A';
            } else {
                message[i] = (key[index % SIZE] + letter - 26) % 26 + 'A';
            }
        }
    }
}

void decrypt(char encrypted_message[100], char key[SIZE]) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            char letter = toupper(encrypted_message[i]);
            int index = letter - 'A';
            if (letter < 'Z') {
                encrypted_message[i] = (26 - key[index % SIZE] + letter) % 26 + 'A';
            } else {
                encrypted_message[i] = (26 - key[index % SIZE] + letter - 26) % 26 + 'A';
            }
        }
    }
}

int main() {
    char message[100], encrypted_message[100], key[SIZE];

    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]", message);

    generate_key(key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}