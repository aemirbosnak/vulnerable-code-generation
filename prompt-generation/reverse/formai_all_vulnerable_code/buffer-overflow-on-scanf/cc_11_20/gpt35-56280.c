//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include<stdio.h>
#include<time.h>

/* This program performs benchmarking of matrix multiplication using three different algorithms:
simple, Strassen and recursive Strassen algorithm. */

#define MAX 1000      // Define maximum size of matrices
#define CUTOFF 100    // Cutoff size for recursive Strassen algorithm

double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];  // Matrices to be multiplied

// Simple matrix multiplication algorithm
void simpleMultiply(int n) 
{
    int i, j, k;
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < n; j++) 
        {
            C[i][j] = 0;
            for(k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

// Shift matrix by half in row and half in column
void shift(int n, double A[][MAX], double B[][MAX])
{
    int i, j;
    for(i = 0; i < n/2; i++)
        for(j = 0; j < n/2; j++)
            B[i][j] = A[i][j];
    for(i = 0; i < n/2; i++)
        for(j = 0; j < n/2; j++)
            B[i][j+n/2] = A[i][j+n/2];
    for(i = 0; i < n/2; i++)
        for(j = 0; j < n/2; j++)
            B[i+n/2][j] = A[i+n/2][j];
    for(i = 0; i < n/2; i++)
        for(j = 0; j < n/2; j++)
            B[i+n/2][j+n/2] = A[i+n/2][j+n/2];
}

// Strassen's matrix multiplication algorithm
void strassenMultiply(int n) 
{
    double A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    double B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    double C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    double P1[MAX][MAX], P2[MAX][MAX], P3[MAX][MAX], P4[MAX][MAX], P5[MAX][MAX], P6[MAX][MAX], P7[MAX][MAX];
    double temp1[MAX][MAX], temp2[MAX][MAX];
    int i, j, size = n/2;

    // Base case
    if(n <= CUTOFF) 
    {
        simpleMultiply(n);
        return;
    }

    // Divide matrices into submatrices
    for(i = 0; i < size; i++) 
    {
        for(j = 0; j < size; j++) 
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + size];
            A21[i][j] = A[i + size][j];
            A22[i][j] = A[i + size][j + size];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + size];
            B21[i][j] = B[i + size][j];
            B22[i][j] = B[i + size][j + size];
        }
    }

    // Recursive calls to StrassenMultiply
    shift(size, A11, temp1);
    shift(size, B12, temp2);
    strassenMultiply(size);
    simpleMultiply(size);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            C12[i][j] = C[i][j];

    simpleMultiply(size);
    shift(size, B21, temp2);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            C21[i][j] = C[i][j];

    shift(size, A22, temp1);
    strassenMultiply(size);

    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            C22[i][j] = C[i][j];

    shift(size, A21, temp1);
    strassenMultiply(size);

    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++) 
        {
            C21[i][j] += C[i][j];
            C22[i][j] += C[i][j];
        }

    shift(size, B11, temp2);
    strassenMultiply(size);

    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            C11[i][j] = C[i][j];

    shift(size, A12, temp1);
    strassenMultiply(size);

    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
        {
            C11[i][j] += C[i][j];
            C12[i][j] -= C[i][j];
        }

    // Combine submatrices into result matrix
    for(i = 0; i < size; i++) 
    {
        for(j = 0; j < size; j++) 
        {
            C[i][j] = C11[i][j];
            C[i][j + size] = C12[i][j];
            C[i + size][j] = C21[i][j];
            C[i + size][j + size] = C22[i][j];
        }
    }
}

// Recursive Strassen's matrix multiplication algorithm
void recursiveStrassenMultiply(int n)
{
    double A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    double B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    double C11[MAX][MAX], C12[MAX][MAX], C21[MAX][MAX], C22[MAX][MAX];
    double P1[MAX][MAX], P2[MAX][MAX], P3[MAX][MAX], P4[MAX][MAX], P5[MAX][MAX], P6[MAX][MAX], P7[MAX][MAX];
    double temp1[MAX][MAX], temp2[MAX][MAX];
    int i, j, size = n/2;

    // Base case
    if(n <= CUTOFF)
    {
        simpleMultiply(n);
        return;
    }

    // Divide matrices into submatrices
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + size];
            A21[i][j] = A[i + size][j];
            A22[i][j] = A[i + size][j + size];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + size];
            B21[i][j] = B[i + size][j];
            B22[i][j] = B[i + size][j + size];
        }
    }

    // Compute intermediate matrices
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            temp1[i][j] = A11[i][j] + A22[i][j];
            temp2[i][j] = B11[i][j] + B22[i][j];
        }
    }
    recursiveStrassenMultiply(size);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            C11[i][j] = C[i][j];

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            temp1[i][j] = A21[i][j] + A22[i][j];
        }
    }
    recursiveStrassenMultiply(size);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            C21[i][j] = C[i][j];

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            temp2[i][j] = B12[i][j] - B22[i][j];
        }
    }
    recursiveStrassenMultiply(size);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            C12[i][j] = C[i][j];

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            temp2[i][j] = B21[i][j] - B11[i][j];
        }
    }
    recursiveStrassenMultiply(size);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
            C22[i][j] = C[i][j];

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            temp1[i][j] = A11[i][j] + A12[i][j];
        }
    }
    recursiveStrassenMultiply(size);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
        {
            C11[i][j] = C[i][j] + C12[i][j];
            C22[i][j] += C[i][j];
        }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            temp1[i][j] = A21[i][j] - A11[i][j];
            temp2[i][j] = B11[i][j] + B12[i][j];
        }
    }
    recursiveStrassenMultiply(size);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
        {
            C21[i][j] += C[i][j];
            C22[i][j] += C[i][j];
        }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            temp1[i][j] = A12[i][j] - A22[i][j];
            temp2[i][j] = B21[i][j] + B22[i][j];
        }
    }
    recursiveStrassenMultiply(size);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
        {
            C11[i][j] += C[i][j];
        }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            temp1[i][j] = A11[i][j] - A21[i][j];
            temp2[i][j] = B11[i][j] + B22[i][j];
        }
    }
    recursiveStrassenMultiply(size);
    for(i = 0; i < size; i++)
        for(j = 0; j < size; j++)
        {
            C12[i][j] += C[i][j];
        }

    // Combine submatrices into result matrix
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + size] = C12[i][j];
            C[i + size][j] = C21[i][j];
            C[i + size][j + size] = C22[i][j];
        }
    }
}

int main()
{
    int n, i, j;
    clock_t start, end;
    double time;

    printf("Enter size of matrices (maximum %d): ", MAX);  // User input
    scanf("%d", &n);

    if(n < 1 || n > MAX)  // Error handling
    {
        printf("Invalid input.\n");
        return 0;
    }

    // Initialize matrices with random numbers
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < n; j++) 
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Benchmarking simple multiplication algorithm
    printf("Performing benchmarking of simple multiplication algorithm...\n");
    start = clock();
    simpleMultiply(n);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds.\n", time);

    // Benchmarking Strassen's multiplication algorithm
    printf("\nPerforming benchmarking of Strassen multiplication algorithm...\n");
    start = clock();
    strassenMultiply(n);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds.\n", time);

    // Benchmarking recursive Strassen's multiplication algorithm
    printf("\nPerforming benchmarking of recursive Strassen multiplication algorithm...\n");
    start = clock();
    recursiveStrassenMultiply(n);
    end = clock();
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds.\n", time);

    return 0;
}