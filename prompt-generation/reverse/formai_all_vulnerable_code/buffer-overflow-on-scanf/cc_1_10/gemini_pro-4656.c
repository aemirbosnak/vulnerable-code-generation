//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
// Welcome, Stellar Dev! Ready for a cosmic distance-finding adventure?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Engage the warp drive!
#define INFINITY (1 << 30)

// Define our intergalactic vessel
typedef struct {
    int rows, cols;
    char **matrix;
} Matrix;

// Warp into existence
Matrix* createMatrix(int rows, int cols) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = malloc(sizeof(char*) * rows);
    for (int i = 0; i < rows; i++) {
        matrix->matrix[i] = malloc(sizeof(char) * cols);
    }
    return matrix;
}

// Beam out of existence
void destroyMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

// Commence the hyperspace jump!
int min(int a, int b, int c) {
    return fmin(fmin(a, b), c);
}

// Engage the warp drive!
int levenshteinDistance(char *s1, char *s2) {
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    
    // Create a matrix to store the distances
    Matrix* matrix = createMatrix(s1Len + 1, s2Len + 1);
    
    // Initialize the first row and column
    for (int i = 0; i <= s1Len; i++) {
        matrix->matrix[i][0] = i;
    }
    for (int j = 0; j <= s2Len; j++) {
        matrix->matrix[0][j] = j;
    }
    
    // Compute the Levenshtein distance
    for (int i = 1; i <= s1Len; i++) {
        for (int j = 1; j <= s2Len; j++) {
            if (s1[i-1] == s2[j-1]) {
                matrix->matrix[i][j] = matrix->matrix[i-1][j-1];
            } else {
                matrix->matrix[i][j] = min(matrix->matrix[i-1][j], matrix->matrix[i][j-1], matrix->matrix[i-1][j-1]) + 1;
            }
        }
    }
    
    // Return the result
    int distance = matrix->matrix[s1Len][s2Len];
    destroyMatrix(matrix);
    return distance;
}

// Engage the interstellar communicator
int main() {
    // Set course for the console
    printf("Greetings, Stellar Navigator! Prepare for the Levenshtein Distance Adventure!\n");
    printf("Enter two celestial strings to calculate their cosmic distance:\n");
    
    // Initialize the variables like a supernova
    char s1[100], s2[100];
    
    // Beam in the strings
    printf("String 1: ");
    scanf("%s", s1);
    printf("String 2: ");
    scanf("%s", s2);
    
    // Calculate the distance using the warp core
    int distance = levenshteinDistance(s1, s2);
    
    // Broadcast the result to the universe
    printf("The cosmic distance between '%s' and '%s' is: %d light-years\n", s1, s2, distance);
    
    // End transmission
    return 0;
}