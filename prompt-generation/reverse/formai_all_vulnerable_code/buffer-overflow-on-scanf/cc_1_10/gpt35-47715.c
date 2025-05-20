//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: happy
#include <stdio.h>
#include <string.h>

// Function to find minimum of three numbers
int min(int a, int b, int c)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

// Function to calculate Levenshtein distance
int levenshteinDistance(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a matrix to store distances
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            // Fill the first row
            if (i == 0)
                dp[i][j] = j;

            // Fill the first column
            else if (j == 0)
                dp[i][j] = i;

            // If characters are same
            // no operation required
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If characters are different
            // take minimum of three operations
            else
                dp[i][j] = 1 + min(dp[i - 1][j],
                                    dp[i][j - 1],
                                    dp[i - 1][j - 1]);
        }
    }

    // Return the final answer
    return dp[m][n];
}

int main()
{
    char s1[100], s2[100];

    printf("Please enter string s1:\n");
    scanf("%s", s1);

    printf("Please enter string s2:\n");
    scanf("%s", s2);

    printf("Levenshtein distance between %s and %s is %d\n",
            s1, s2, levenshteinDistance(s1, s2));

    // Happy message
    printf("Hooray, we calculated the Levenshtein distance!\n");

    return 0;
}