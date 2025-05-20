//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

// Function to display the matrix
void displayMatrix(int matrix[][MAX_SIZE], int N) {
    printf("\nMatrix after Percolation:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

// Function to perform percolation
int percolation(int matrix[][MAX_SIZE], int N) {
    // Initializing variables
    int count = 0, i = 0;
    int arr[N*N];

    // Checking for top row
    for(int j = 0; j < N; j++) {
        if(matrix[0][j] == 1) {
            count++;
            arr[i++] = j; 
        }
    }

    // Checking for bottom row
    for(int j = 0; j < N; j++) {
        if(matrix[N-1][j] == 1) {
            count++;
            arr[i++] = (N-1)*N + j;
        }
    }

    // Checking for left column
    for(int i = 1; i < N-1; i++) {
        if(matrix[i][0] == 1) {
            count++;
            arr[i++] = i*N;
        }
    }

    // Checking for right column
    for(int i = 1; i < N-1; i++) {
        if(matrix[i][N-1] == 1) {
            count++;
            arr[i++] = i*N - 1;
        }
    }

    // Checking all other cells
    for(int i = 1; i < N-1; i++) {
        for(int j = 1; j < N-1; j++) {
            if(matrix[i][j] == 1) {
                if(matrix[i-1][j] == 1)
                    count++;
                if(matrix[i+1][j] == 1)
                    count++;
                if(matrix[i][j-1] == 1)
                    count++;
                if(matrix[i][j+1] == 1)
                    count++;
            }
            if(count >= 2) {
                arr[i++] = i*N + j;
                count = 0;
            }
        }
    }

    // Determining if it percolates or not
    int flag = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int index = i*N + j;
            for(int k = 0; k < i; k++) {
                if(arr[k] == index) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(flag == 1)
            break;
    }
    return flag;
}

int main() {
    // Initializing variables
    int N;

    // Taking input from user
    printf("Enter the size of matrix: ");
    scanf("%d", &N);
    printf("\n");

    // Checking for valid input
    if(N < 1 || N > MAX_SIZE) {
        printf("Invalid Input!\n");
        exit(0);
    }

    // Initializing random seed
    srand(time(0));

    // Creating matrix with random values
    int matrix[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int r = rand() % 2;
            matrix[i][j] = r;
        }
    }

    // Displaying the matrix
    printf("Initial Matrix:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Checking if it percolates or not
    int isPercolated = percolation(matrix, N);

    // Displaying the result
    if(isPercolated == 1)
        printf("\nThe matrix percolates!\n");
    else
        printf("\nThe matrix does not percolate!\n");

    return 0;
}