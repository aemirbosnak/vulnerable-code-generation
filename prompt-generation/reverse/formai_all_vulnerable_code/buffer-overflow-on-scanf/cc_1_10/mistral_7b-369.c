//MISTRAL-7B DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3

typedef struct {
    double data[SIZE][SIZE];
    char name[50];
} Matrix;

void read_matrix(Matrix *matrix) {
    printf("Enter the name of your beloved matrix: ");
    scanf("%s", matrix->name);
    printf("Enter the elements of %s:\n", matrix->name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%lf", &matrix->data[i][j]);
        }
    }
}

void print_matrix(const Matrix *matrix) {
    printf("\nThe romantic elements of %s are:\n", matrix->name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%10.2f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix multiply(const Matrix *a, const Matrix *b) {
    Matrix result;
    strcpy(result.name, "Love Child");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

int main() {
    Matrix a, b, c;
    read_matrix(&a);
    read_matrix(&b);
    c = multiply(&a, &b);
    print_matrix(&a);
    printf("\nThe magic of true love multiplies %s and %s to create a new romantic matrix named %s:\n", a.name, b.name, c.name);
    print_matrix(&c);
    return 0;
}