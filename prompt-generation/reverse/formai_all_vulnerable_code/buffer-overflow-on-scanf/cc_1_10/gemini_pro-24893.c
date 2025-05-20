//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a Levenshtein distance matrix
typedef struct {
    int **matrix;
    int width;
    int height;
} LevenshteinMatrix;

// A function to create a Levenshtein distance matrix
LevenshteinMatrix *levenshtein_matrix_create(const char *str1, const char *str2) {
    LevenshteinMatrix *matrix = malloc(sizeof(LevenshteinMatrix));
    if (matrix == NULL) {
        return NULL;
    }

    matrix->width = strlen(str1) + 1;
    matrix->height = strlen(str2) + 1;
    matrix->matrix = malloc(sizeof(int *) * matrix->height);
    if (matrix->matrix == NULL) {
        free(matrix);
        return NULL;
    }

    for (int i = 0; i < matrix->height; i++) {
        matrix->matrix[i] = malloc(sizeof(int) * matrix->width);
        if (matrix->matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matrix->matrix[j]);
            }
            free(matrix->matrix);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

// A function to destroy a Levenshtein distance matrix
void levenshtein_matrix_destroy(LevenshteinMatrix *matrix) {
    for (int i = 0; i < matrix->height; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

// A function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *str1, const char *str2) {
    LevenshteinMatrix *matrix = levenshtein_matrix_create(str1, str2);
    if (matrix == NULL) {
        return -1;
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i < matrix->width; i++) {
        matrix->matrix[0][i] = i;
    }
    for (int j = 0; j < matrix->height; j++) {
        matrix->matrix[j][0] = j;
    }

    // Calculate the Levenshtein distance for each cell in the matrix
    for (int i = 1; i < matrix->height; i++) {
        for (int j = 1; j < matrix->width; j++) {
            int cost = (str1[j - 1] == str2[i - 1]) ? 0 : 1;
            matrix->matrix[i][j] = fmin(fmin(matrix->matrix[i - 1][j] + 1, matrix->matrix[i][j - 1] + 1), matrix->matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the Levenshtein distance
    int distance = matrix->matrix[matrix->height - 1][matrix->width - 1];
    levenshtein_matrix_destroy(matrix);
    return distance;
}

int main() {
    // Get the two strings from the user
    char str1[100];
    char str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Calculate the Levenshtein distance between the two strings
    int distance = levenshtein_distance(str1, str2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}