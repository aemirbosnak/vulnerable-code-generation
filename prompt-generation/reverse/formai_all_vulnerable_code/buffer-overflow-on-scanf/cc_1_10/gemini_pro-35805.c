//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: active
#include <stdio.h>
#include <string.h>

// Compute the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances between the prefixes of s1 and s2.
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    int matrix[m][n];

    // Initialize the first row and column of the matrix.
    for (int i = 0; i < m; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < n; j++) {
        matrix[0][j] = j;
    }

    // Compute the Levenshtein distances between the prefixes of s1 and s2.
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + fmin(matrix[i - 1][j], fmin(matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }

    // Return the Levenshtein distance between s1 and s2.
    return matrix[m - 1][n - 1];
}

int main() {
    // Get the two strings from the user.
    char s1[100];
    char s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Compute the Levenshtein distance between the two strings.
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance.
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}