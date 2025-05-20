//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein distance between two strings
int levenshtein(const char *str1, const char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);

    // Create matrix to store distances
    int matrix[m + 1][n + 1];

    // Initialize first row and column
    for (int i = 0; i <= m; i++)
        matrix[i][0] = i;
    for (int j = 0; j <= n; j++)
        matrix[0][j] = j;

    // Calculate distances
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else
                matrix[i][j] = 1 + fmin(fmin(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]);
        }
    }

    // Return distance
    return matrix[m][n];
}

// Main function
int main()
{
    // Get input strings
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Calculate Levenshtein distance
    int distance = levenshtein(str1, str2);

    // Print distance
    printf("Levenshtein distance: %d\n", distance);

    return 0;
}