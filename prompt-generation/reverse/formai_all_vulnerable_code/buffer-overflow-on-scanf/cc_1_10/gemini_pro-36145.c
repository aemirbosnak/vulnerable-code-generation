//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2) {
    // Initialize the matrix
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    int matrix[m][n];
    for (int i = 0; i < m; i++) matrix[i][0] = i;
    for (int j = 0; j < n; j++) matrix[0][j] = j;

    // Fill the matrix
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }

    // Return the last element in the matrix
    return matrix[m - 1][n - 1];
}

// Minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) return a;
        else return c;
    } else {
        if (b < c) return b;
        else return c;
    }
}

int main() {
    // Get the two strings
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the result
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}