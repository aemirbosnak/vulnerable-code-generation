//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Levenshtein distance between two strings
int levenshtein(char *s1, char *s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    int **d = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        d[i] = malloc((m + 1) * sizeof(int));
    }
    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        d[0][j] = j;
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = fmin(fmin(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]) + 1;
            }
        }
    }
    int result = d[n][m];
    for (int i = 0; i <= n; i++) {
        free(d[i]);
    }
    free(d);
    return result;
}

// Main function
int main(void) {
    // Get the two strings from the user
    char s1[100];
    char s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the result
    printf("The Levenshtein distance between the two strings is: %d\n", distance);

    return 0;
}