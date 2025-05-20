//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_VECTOR_SIZE 1000
#define MAX_TERMS 1000

typedef struct {
    double coef;
    int degree;
} polynomial;

polynomial *create_polynomial(int degree) {
    polynomial *poly = (polynomial *)malloc(sizeof(polynomial));
    poly->coef = 0;
    poly->degree = degree;
    return poly;
}

void add_term(polynomial *poly, double coef, int degree) {
    if (poly->degree + degree > MAX_TERMS) {
        printf("Error: Too many terms in polynomial.\n");
        exit(1);
    }
    poly->coef += coef;
    poly->degree += degree;
}

void print_polynomial(polynomial *poly) {
    int i;
    for (i = poly->degree; i >= 0; i--) {
        if (poly->coef!= 0) {
            printf("%lf", poly->coef);
            if (i > 0) {
                printf("x");
            }
        } else {
            printf("0");
        }
    }
}

int main() {
    int i, j, n, m;
    double **data;
    polynomial *poly;
    FILE *fp;

    // Read data from file
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }
    fscanf(fp, "%d %d", &n, &m);
    data = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        data[i] = (double *)malloc(m * sizeof(double));
        for (j = 0; j < m; j++) {
            fscanf(fp, "%lf", &data[i][j]);
        }
    }
    fclose(fp);

    // Perform linear regression
    for (i = 0; i < n; i++) {
        poly = create_polynomial(m - 1);
        for (j = 0; j < m; j++) {
            add_term(poly, data[i][j], j);
        }
        printf("Polynomial for row %d:\n", i+1);
        print_polynomial(poly);
        printf("\n");
    }

    return 0;
}