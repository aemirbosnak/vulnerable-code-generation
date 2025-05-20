//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Function to calculate the minimum of three numbers
int min(int a, int b, int c)
{
    int min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;

    return min;
}

// Function to calculate the Levenshtein Distance between two strings
int levenshteinDistance(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a 2D array to store the results of the subproblems
    int dp[len1 + 1][len2 + 1];

    // Initialize the first row and column to their respective indices
    for (int i = 0; i <= len1; i++)
        dp[i][0] = i;
    for (int j = 0; j <= len2; j++)
        dp[0][j] = j;

    // Fill up the rest of the matrix based on the recursive formula
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
        }
    }

    // Return the bottom-right element of the matrix
    return dp[len1][len2];
}

int main()
{
    char s1[100], s2[100];

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    int distance = levenshteinDistance(s1, s2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}