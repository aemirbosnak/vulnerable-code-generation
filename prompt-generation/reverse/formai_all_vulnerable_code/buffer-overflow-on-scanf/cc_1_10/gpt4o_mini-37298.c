//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Declarations
int isPrime(int num);
void primeFactorization(int num);
double evaluatePolynomial(double *coefficients, int degree, double x);
void matrixMultiplication(int **A, int **B, int result[][3], int r1, int c1, int r2, int c2);

int main() {
    int choice, num, degree, i;
    double x;

    do {
        // Menu for user input
        printf("\nMathematical Operations Menu:\n");
        printf("1. Prime Factorization\n");
        printf("2. Polynomial Evaluation\n");
        printf("3. Matrix Multiplication\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Prime Factorization
                printf("Enter a positive integer for prime factorization: ");
                scanf("%d", &num);
                if (num > 1) {
                    printf("Prime factorization of %d: ", num);
                    primeFactorization(num);
                    printf("\n");
                } else {
                    printf("Enter an integer greater than 1.\n");
                }
                break;

            case 2:
                // Polynomial Evaluation
                printf("Enter the degree of the polynomial: ");
                scanf("%d", &degree);
                double *coefficients = (double *)malloc((degree + 1) * sizeof(double));

                printf("Enter the coefficients from highest degree to constant:\n");
                for (i = 0; i <= degree; i++) {
                    printf("Coefficient of x^%d: ", degree - i);
                    scanf("%lf", &coefficients[i]);
                }

                printf("Enter the value of x: ");
                scanf("%lf", &x);

                double resultValue = evaluatePolynomial(coefficients, degree, x);
                printf("Polynomial result: %.2lf\n", resultValue);
                free(coefficients);
                break;

            case 3:
                // Matrix Multiplication
                {
                    int r1, c1, r2, c2, j;
                    printf("Matrix A dimensions (rows and columns): ");
                    scanf("%d %d", &r1, &c1);
                    printf("Matrix B dimensions (rows and columns): ");
                    scanf("%d %d", &r2, &c2);

                    if (c1 != r2) {
                        printf("Matrix multiplication not possible. Ensure columns of A = rows of B.\n");
                        break;
                    }

                    int **A = (int **)malloc(r1 * sizeof(int *));
                    int **B = (int **)malloc(r2 * sizeof(int *));
                    for (i = 0; i < r1; i++)
                        A[i] = (int *)malloc(c1 * sizeof(int));
                    for (i = 0; i < r2; i++)
                        B[i] = (int *)malloc(c2 * sizeof(int));

                    // Input for Matrix A
                    printf("Enter elements of Matrix A:\n");
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c1; j++) {
                            printf("A[%d][%d]: ", i, j);
                            scanf("%d", &A[i][j]);
                        }
                    }

                    // Input for Matrix B
                    printf("Enter elements of Matrix B:\n");
                    for (i = 0; i < r2; i++) {
                        for (j = 0; j < c2; j++) {
                            printf("B[%d][%d]: ", i, j);
                            scanf("%d", &B[i][j]);
                        }
                    }

                    int result[3][3]; // This will depend on the maximum size

                    // Perform multiplication
                    matrixMultiplication(A, B, result, r1, c1, r2, c2);
                    printf("Resultant Matrix:\n");
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c2; j++) {
                            printf("%d ", result[i][j]);
                        }
                        printf("\n");
                    }

                    // Free allocated memory for A and B
                    for (i = 0; i < r1; i++) free(A[i]);
                    for (i = 0; i < r2; i++) free(B[i]);
                    free(A);
                    free(B);
                }
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

// Function Definitions
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void primeFactorization(int num) {
    int count;
    for (int i = 2; i <= num; i++) {
        count = 0;
        while (num % i == 0) {
            num /= i;
            count++;
        }
        if (count > 0) {
            printf("%d^%d ", i, count);
        }
    }
}

double evaluatePolynomial(double *coefficients, int degree, double x) {
    double result = 0;
    for (int i = 0; i <= degree; i++) {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

void matrixMultiplication(int **A, int **B, int result[][3], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}