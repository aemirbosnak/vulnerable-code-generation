//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Levenshtein distance is a measure of the similarity between two strings.
// It is the minimum number of edits (insertions, deletions, or substitutions)
// required to transform one string into the other.

// This function calculates the Levenshtein distance between two strings.
int levenshtein(const char *a, const char *b)
{
    // Create a matrix to store the Levenshtein distances between the prefixes of a and b.
    int n = strlen(a) + 1;
    int m = strlen(b) + 1;
    int ld[n][m];

    // Initialize the first row and column of the matrix.
    for (int i = 0; i < n; i++) {
        ld[i][0] = i;
    }
    for (int j = 0; j < m; j++) {
        ld[0][j] = j;
    }

    // Calculate the Levenshtein distances between the prefixes of a and b.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            ld[i][j] = min(ld[i - 1][j] + 1,     // deletion
                            min(ld[i][j - 1] + 1, // insertion
                                ld[i - 1][j - 1] + cost)); // substitution
        }
    }

    // Return the Levenshtein distance between a and b.
    return ld[n - 1][m - 1];
}

// This function returns the minimum of three integers.
int min(int a, int b, int c)
{
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

// This is a test program.
int main()
{
    // Get the two strings from the user.
    char a[100];
    char b[100];
    printf("Enter the first string: ");
    scanf("%s", a);
    printf("Enter the second string: ");
    scanf("%s", b);

    // Calculate the Levenshtein distance between the two strings.
    int distance = levenshtein(a, b);

    // Print the Levenshtein distance.
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", a, b, distance);

    return 0;
}