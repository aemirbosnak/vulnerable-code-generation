//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct key {
    int row1;
    int col1;
    int row2;
    int col2;
};

void generate_key(struct key *key) {
    srand(time(NULL));
    key->row1 = rand() % 3;
    key->col1 = rand() % 3;
    key->row2 = rand() % 3;
    key->col2 = rand() % 3;
}

void encrypt(char *message, struct key *key) {
    int rows = strlen(message) / 3;
    int cols = strlen(message) % 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int row = i % 3;
            int col = j % 3;
            int new_row = (row + key->row1) % 3;
            int new_col = (col + key->col1) % 3;
            message[i * 3 + j] = message[(new_row * 3 + new_col) % strlen(message)];
        }
    }
}

void decrypt(char *ciphertext, struct key *key) {
    int rows = strlen(ciphertext) / 3;
    int cols = strlen(ciphertext) % 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int row = i % 3;
            int col = j % 3;
            int new_row = (row - key->row2) % 3;
            int new_col = (col - key->col2) % 3;
            ciphertext[(new_row * 3 + new_col) % strlen(ciphertext)] = ciphertext[i * 3 + j];
        }
    }
}

int main() {
    struct key key;
    generate_key(&key);
    char message[1000];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(message, &key);
    printf("Encrypted message: %s\n", message);
    char ciphertext[1000];
    strcpy(ciphertext, message);
    decrypt(ciphertext, &key);
    printf("Decrypted message: %s\n", ciphertext);
    return 0;
}