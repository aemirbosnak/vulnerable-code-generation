//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    int **data;
} matrix;

matrix *create_matrix(int rows, int cols) {
    matrix *m = (matrix *) malloc(sizeof(matrix));
    m->rows = rows;
    m->cols = cols;
    m->data = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        m->data[i] = (int *) malloc(cols * sizeof(int));
    }
    return m;
}

void destroy_matrix(matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void print_matrix(matrix *m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void encrypt_matrix(matrix *m, int key) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = (m->data[i][j] + key) % 256;
        }
    }
}

void decrypt_matrix(matrix *m, int key) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = (m->data[i][j] - key + 256) % 256;
        }
    }
}

int main() {
    srand(time(NULL));
    int rows, cols, key;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the key: ");
    scanf("%d", &key);

    matrix *m = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m->data[i][j] = rand() % 256;
        }
    }

    printf("Original Matrix:\n");
    print_matrix(m);

    encrypt_matrix(m, key);
    printf("Encrypted Matrix:\n");
    print_matrix(m);

    decrypt_matrix(m, key);
    printf("Decrypted Matrix:\n");
    print_matrix(m);

    destroy_matrix(m);
    return 0;
}