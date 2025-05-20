//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16 // size of the encryption matrix

void generate_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
}

void print_matrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void encrypt(int matrix[SIZE][SIZE], char *message) {
    int m = strlen(message);
    int n = m / SIZE;
    if (m % SIZE!= 0) {
        n++;
    }

    char *encrypted_message = (char *)malloc(n * SIZE + 1);
    encrypted_message[0] = '\0';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < SIZE; j++) {
            encrypted_message[i * SIZE + j] = message[i * SIZE + j] ^ matrix[i][j];
        }
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(int matrix[SIZE][SIZE], char *encrypted_message) {
    int m = strlen(encrypted_message);
    int n = m / SIZE;
    if (m % SIZE!= 0) {
        n++;
    }

    char *decrypted_message = (char *)malloc(n * SIZE + 1);
    decrypted_message[0] = '\0';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < SIZE; j++) {
            decrypted_message[i * SIZE + j] = encrypted_message[i * SIZE + j] ^ matrix[i][j];
        }
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    srand(time(NULL));

    int matrix[SIZE][SIZE];
    generate_matrix(matrix);
    print_matrix(matrix);

    char message[] = "Hello, world!";
    encrypt(matrix, message);

    char encrypted_message[SIZE * 2 + 1] = { 0 };
    strcat(encrypted_message, message);
    decrypt(matrix, encrypted_message);

    return 0;
}