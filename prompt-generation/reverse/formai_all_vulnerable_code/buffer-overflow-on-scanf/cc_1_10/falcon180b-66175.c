//Falcon-180B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max_size 100

// Function to generate a random matrix
void generate_matrix(int mat[max_size][max_size]) {
    int i, j;
    for (i = 0; i < max_size; i++) {
        for (j = 0; j < max_size; j++) {
            mat[i][j] = rand() % 256;
        }
    }
}

// Function to encrypt a string using matrix multiplication
void encrypt(char str[max_size], int mat[max_size][max_size]) {
    int i, j, k, len = strlen(str);
    int encrypted_str[max_size];

    // Convert string to integer array
    for (i = 0; i < len; i++) {
        encrypted_str[i] = str[i];
    }

    // Encrypt using matrix multiplication
    for (i = 0; i < max_size; i++) {
        for (j = 0; j < max_size; j++) {
            for (k = 0; k < max_size; k++) {
                encrypted_str[i] += mat[i][k] * mat[k][j] * encrypted_str[j];
            }
        }
    }

    // Convert integer array back to string
    for (i = 0; i < len; i++) {
        str[i] = encrypted_str[i] % 256;
    }
}

int main() {
    char str[max_size];
    int mat[max_size][max_size];

    // Get input string from user
    printf("Enter a string to encrypt: ");
    scanf("%s", str);

    // Generate random matrix
    srand(time(NULL));
    generate_matrix(mat);

    // Encrypt string using matrix multiplication
    encrypt(str, mat);

    // Print encrypted string
    printf("Encrypted string: %s\n", str);

    return 0;
}