//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Levenshtein distance calculator
int levenshtein(const char *s1, const char *s2) {
    int s1len = strlen(s1);
    int s2len = strlen(s2);

    // Create a matrix to store the distances
    int matrix[s1len + 1][s2len + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= s1len; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= s2len; j++) {
        matrix[0][j] = j;
    }

    // Calculate the Levenshtein distance for each cell in the matrix
    for (int i = 1; i <= s1len; i++) {
        for (int j = 1; j <= s2len; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1,  // Deletion
                                matrix[i][j - 1] + 1,  // Insertion
                                matrix[i - 1][j - 1] + cost);  // Substitution
        }
    }

    // Return the Levenshtein distance
    return matrix[s1len][s2len];
}

// Minimum of three integers
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// Main function
int main() {
    // Get the two strings from the user
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    return 0;
}