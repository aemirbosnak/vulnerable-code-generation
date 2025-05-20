//Falcon2-11B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <string.h>

int levenshtein_distance(const char *s1, const char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a 2D array to store the distances
    int **d = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        d[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the first row and column of the array
    for (int i = 0; i < m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j < n; j++) {
        d[0][j] = j;
    }

    // Compute the distances for the remaining cells
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            int cost = 0;
            if (s1[i-1] == s2[j-1]) {
                cost = d[i-1][j-1];
            } else {
                cost = 1 + d[i-1][j] + d[i][j-1];
            }
            d[i][j] = cost;
        }
    }

    // Free the memory used by the array
    for (int i = 0; i < m; i++) {
        free(d[i]);
    }
    free(d);

    // Return the last element of the array, which contains the distance between the two strings
    return d[m-1][n-1];
}

int main() {
    const char *s1 = "kitten";
    const char *s2 = "sitting";

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);

    return 0;
}