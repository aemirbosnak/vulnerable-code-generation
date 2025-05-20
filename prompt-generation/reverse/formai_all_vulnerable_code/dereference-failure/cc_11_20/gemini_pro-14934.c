//GEMINI-pro DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Initialize file pointers
    FILE *fp1, *fp2;
    
    // Open a file for reading and writing
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("output.txt", "w");
    
    // Check if files were opened successfully
    if (fp1 == NULL || fp2 == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    
    // Read the number of equations from the file
    int n;
    fscanf(fp1, "%d", &n);
    
    // Allocate memory for the coefficients and constants
    double **a = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }
    double *b = (double *)malloc(n * sizeof(double));
    
    // Read the coefficients and constants from the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp1, "%lf", &a[i][j]);
        }
        fscanf(fp1, "%lf", &b[i]);
    }
    
    // Perform Gauss-Jordan elimination
    for (int i = 0; i < n; i++) {
        // Normalize the ith row
        double factor = 1.0 / a[i][i];
        for (int j = 0; j < n; j++) {
            a[i][j] *= factor;
        }
        b[i] *= factor;
        
        // Eliminate the ith column in the other rows
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            double factor = -a[j][i];
            for (int k = 0; k < n; k++) {
                a[j][k] += factor * a[i][k];
            }
            b[j] += factor * b[i];
        }
    }
    
    // Print the solution to the file
    for (int i = 0; i < n; i++) {
        fprintf(fp2, "x%d = %lf\n", i + 1, b[i]);
    }
    
    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(b);
    
    // Close the files
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}