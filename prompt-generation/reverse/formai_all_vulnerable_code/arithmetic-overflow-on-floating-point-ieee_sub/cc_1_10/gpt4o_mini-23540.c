//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void displayMenu();
void addMatrices();
void multiplyMatrices();
void calculateQuadraticRoots();
void calculateFactorial();
void findMaximum();
void findMinimum();

// Main function
int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6) or 0 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrices();
                break;
            case 2:
                multiplyMatrices();
                break;
            case 3:
                calculateQuadraticRoots();
                break;
            case 4:
                calculateFactorial();
                break;
            case 5:
                findMaximum();
                break;
            case 6:
                findMinimum();
                break;
            case 0:
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 0 and 6.\n");
        }
    }
    return 0;
}

// Display the menu
void displayMenu() {
    printf("\n--- C Math Exercise Menu ---\n");
    printf("1. Add Matrices\n");
    printf("2. Multiply Matrices\n");
    printf("3. Calculate Quadratic Roots\n");
    printf("4. Calculate Factorial\n");
    printf("5. Find Maximum\n");
    printf("6. Find Minimum\n");
    printf("0. Exit\n");
}

// Function to add two matrices
void addMatrices() {
    int rows, cols, i, j;
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    int matrixA[rows][cols], matrixB[rows][cols], result[rows][cols];

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Adding matrices
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    printf("Resultant Matrix after Addition:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
void multiplyMatrices() {
    int rowsA, colsA, rowsB, colsB, i, j, k;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication not possible, check dimensions.\n");
        return;
    }

    int matrixA[rowsA][colsA], matrixB[rowsB][colsB], result[rowsA][colsB];

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < rowsB; i++) {
        for (j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Multiplying matrices
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printf("Resultant Matrix after Multiplication:\n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate roots of a quadratic equation
void calculateQuadraticRoots() {
    double a, b, c, discriminant, root1, root2;

    printf("Enter coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different: root1 = %.2lf, root2 = %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and the same: root1 = root2 = %.2lf\n", root1);
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex:\n");
        printf("root1 = %.2lf + %.2lfi\n", realPart, imaginaryPart);
        printf("root2 = %.2lf - %.2lfi\n", realPart, imaginaryPart);
    }
}

// Function to calculate factorial
void calculateFactorial() {
    int num, i;
    unsigned long long factorial = 1;

    printf("Enter a number to compute its factorial: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is undefined for negative numbers.\n");
        return;
    }

    for (i = 1; i <= num; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is %llu\n", num, factorial);
}

// Function to find maximum of n numbers
void findMaximum() {
    int n, i, max;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if (i == 0) {
            max = temp; // Initialize max with first element
        } else if (temp > max) {
            max = temp;
        }
    }

    printf("The maximum element is: %d\n", max);
}

// Function to find minimum of n numbers
void findMinimum() {
    int n, i, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        if (i == 0) {
            min = temp; // Initialize min with first element
        } else if (temp < min) {
            min = temp;
        }
    }

    printf("The minimum element is: %d\n", min);
}