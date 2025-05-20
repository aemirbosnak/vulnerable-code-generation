//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to find the minimum of three numbers
int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

// Levenshtein distance calculation function
int levenshtein(const char *s1, const char *s2) {
    // Initialize the distance matrix
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    int d[m][n];
    for (int i = 0; i < m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < n; j++) {
        d[0][j] = j;
    }

    // Calculate the distance matrix
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + cost);
        }
    }

    // Return the distance
    return d[m - 1][n - 1];
}

// Main function
int main() {
    // Get the input strings
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