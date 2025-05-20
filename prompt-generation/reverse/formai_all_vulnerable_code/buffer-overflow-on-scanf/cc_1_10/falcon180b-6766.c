//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void generate_key(int key[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            key[i][j] = rand() % 26 + 1;
        }
    }
}

void encrypt(char message[100], int key[SIZE][SIZE]) {
    int length = strlen(message);
    char encrypted_message[100];
    encrypted_message[0] = '\0';

    for (int i = 0; i < length; i++) {
        if (isalpha(message[i])) {
            int row = message[i] - 'a';
            int col = key[row][i % SIZE] - 1;

            if (col < 0) {
                col += 26;
            }

            encrypted_message[i] = col + 'a';
        } else {
            encrypted_message[i] = message[i];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char encrypted_message[100], int key[SIZE][SIZE]) {
    int length = strlen(encrypted_message);
    char decrypted_message[100];
    decrypted_message[0] = '\0';

    for (int i = 0; i < length; i++) {
        if (isalpha(encrypted_message[i])) {
            int row = encrypted_message[i] - 'a';
            int col = key[i % SIZE][row] - 1;

            if (col < 0) {
                col += 26;
            }

            decrypted_message[i] = col + 'a';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100];
    printf("Enter a message: ");
    scanf("%s", message);

    int key[SIZE][SIZE];
    generate_key(key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}