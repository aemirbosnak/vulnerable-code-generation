//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance calculator.
int levenshtein(const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    // Create a matrix to store the distances.
    int **matrix = malloc((len1 + 1) * sizeof(int *));
    for (size_t i = 0; i <= len1; i++) {
        matrix[i] = malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column of the matrix.
    for (size_t i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (size_t j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate the distances.
    for (size_t i = 1; i <= len1; i++) {
        for (size_t j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
        }
    }

    // Return the distance.
    int distance = matrix[len1][len2];

    // Free the matrix.
    for (size_t i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

int main() {
    // Get the strings from the user.
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance.
    int distance = levenshtein(s1, s2);

    // Print the distance.
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}