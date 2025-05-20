//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to return minimum of three integers
int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    else
        return z;
}

// function to calculate the Levenshtein Distance between two strings
int LevenshteinDistance(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int d[m+1][n+1];

    // initialize first row and column of the matrix
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }

    // fill in the rest of the matrix
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (s[i-1] == t[j-1]) {
                d[i][j] = d[i-1][j-1];
            } else {
                d[i][j] = min(
                    d[i-1][j] + 1,   // deletion
                    d[i][j-1] + 1,   // insertion
                    d[i-1][j-1] + 1  // substitution
                );
            }
        }
    }

    return d[m][n];
}

int main() {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    printf("Levenshtein Distance: %d\n", LevenshteinDistance(s1, s2));

    return 0;
}