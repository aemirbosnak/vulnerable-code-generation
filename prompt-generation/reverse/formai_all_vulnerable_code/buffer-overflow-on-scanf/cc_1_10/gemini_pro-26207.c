//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <string.h>

// Levenshtein distance function
int levenshtein(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a matrix to store the distances
    int d[m + 1][n + 1];

    // Initialize the first row and column
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }

    // Calculate the distances
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
            }
        }
    }

    // Return the distance
    return d[m][n];
}

// Helper function to find the minimum of three integers
int min(int a, int b, int c) {
    int m = a;
    if (b < m) {
        m = b;
    }
    if (c < m) {
        m = c;
    }
    return m;
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

    // Print the distance
    printf("The Levenshtein distance between the two strings is: %d\n", distance);

    return 0;
}