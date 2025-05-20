//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compute the Levenshtein distance between two strings.
int levenshtein(const char *s1, const char *s2) {
    // Create a matrix to store the Levenshtein distances.
    int **d = malloc(sizeof(int *) * (strlen(s1) + 1));
    for (int i = 0; i < strlen(s1) + 1; i++) {
        d[i] = malloc(sizeof(int) * (strlen(s2) + 1));
    }

    // Initialize the first row and column of the matrix.
    for (int i = 0; i < strlen(s1) + 1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < strlen(s2) + 1; j++) {
        d[0][j] = j;
    }

    // Compute the Levenshtein distances for the remaining cells of the matrix.
    for (int i = 1; i < strlen(s1) + 1; i++) {
        for (int j = 1; j < strlen(s2) + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + fmin(d[i - 1][j - 1], fmin(d[i][j - 1], d[i - 1][j]));
            }
        }
    }

    // Return the Levenshtein distance.
    return d[strlen(s1)][strlen(s2)];
}

// Test the Levenshtein distance calculator.
int main() {
    // Get the two strings from the user.
    char s1[100], s2[100];
    printf("Enter the first string: ");
    gets(s1);
    printf("Enter the second string: ");
    gets(s2);

    // Compute the Levenshtein distance between the two strings.
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance.
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s1, s2, distance);

    return 0;
}