//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance calculation
int levenshtein(char *s1, char *s2) {
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

    // Calculate the distances
    for (int i = 1; i <= s1len; i++) {
        for (int j = 1; j <= s2len; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(
                fmin(
                    matrix[i - 1][j] + 1,   // Deletion
                    matrix[i][j - 1] + 1    // Insertion
                ),
                matrix[i - 1][j - 1] + cost // Substitution
            );
        }
    }

    // Return the distance
    return matrix[s1len][s2len];
}

int main() {
    // Get the two strings from the user
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    return 0;
}