//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance function
int levenshtein(const char *s1, const char *s2) {
    // Initialize the matrix
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < n; j++) {
        matrix[0][j] = j;
    }

    // Compute the Levenshtein distance
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j] = fmin(
                matrix[i - 1][j] + 1, // Deletion
                fmin(
                    matrix[i][j - 1] + 1, // Insertion
                    matrix[i - 1][j - 1] + cost // Substitution
                )
            );
        }
    }

    // Return the Levenshtein distance
    return matrix[m - 1][n - 1];
}

// Main function
int main() {
    // Get the input strings
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Compute the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}