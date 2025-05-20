//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance calculator
int lev(const char *s, const char *t) {
    // Initialize the distance matrix
    int **d = malloc((strlen(s) + 1) * sizeof(int *));
    for (int i = 0; i < strlen(s) + 1; i++) {
        d[i] = malloc((strlen(t) + 1) * sizeof(int));
    }

    // Populate the first row and column of the distance matrix
    for (int i = 0; i < strlen(s) + 1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < strlen(t) + 1; j++) {
        d[0][j] = j;
    }

    // Compute the Levenshtein distance
    for (int i = 1; i < strlen(s) + 1; i++) {
        for (int j = 1; j < strlen(t) + 1; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    // Return the Levenshtein distance
    int result = d[strlen(s)][strlen(t)];

    // Free the distance matrix
    for (int i = 0; i < strlen(s) + 1; i++) {
        free(d[i]);
    }
    free(d);

    return result;
}

// Minimum of three integers
int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// Main function
int main() {
    // Get the input strings
    char s[100], t[100];
    printf("Enter the first string: ");
    scanf("%s", s);
    printf("Enter the second string: ");
    scanf("%s", t);

    // Compute the Levenshtein distance
    int distance = lev(s, t);

    // Print the Levenshtein distance
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s, t, distance);

    return 0;
}