//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int rows, cols;
    char *data;
} matrix;

void init_matrix(matrix *m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
    m->data = (char *)malloc(rows * cols * sizeof(char));
    memset(m->data, 0, rows * cols * sizeof(char));
}

void free_matrix(matrix *m) {
    free(m->data);
}

void print_matrix(matrix *m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", m->data[i * cols + j]);
        }
        printf("\n");
    }
}

void encrypt(matrix *m, int key) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (isalpha(m->data[i * m->cols + j])) {
                m->data[i * m->cols + j] = (char)(tolower(m->data[i * m->cols + j]) + key - 97);
            }
        }
    }
}

void decrypt(matrix *m, int key) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            if (isalpha(m->data[i * m->cols + j])) {
                m->data[i * m->cols + j] = (char)(tolower(m->data[i * m->cols + j]) - key + 97);
            }
        }
    }
}

void generate_random_matrix(matrix *m, int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m->data[i * cols + j] = rand() % 26 + 'a';
        }
    }
}

int main() {
    int rows, cols, key;
    char inp[100];
    matrix plaintext, ciphertext, decrypted;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    init_matrix(&plaintext, rows, cols);
    init_matrix(&ciphertext, rows, cols);
    init_matrix(&decrypted, rows, cols);

    generate_random_matrix(&plaintext, rows, cols);

    printf("Plaintext:\n");
    print_matrix(&plaintext, rows, cols);

    printf("Enter the encryption key: ");
    scanf("%d", &key);

    encrypt(&plaintext, key);

    printf("Ciphertext:\n");
    print_matrix(&ciphertext, rows, cols);

    decrypt(&ciphertext, key);

    printf("Decrypted text:\n");
    print_matrix(&decrypted, rows, cols);

    free_matrix(&plaintext);
    free_matrix(&ciphertext);
    free_matrix(&decrypted);

    return 0;
}