//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z)
{
    if (x < y && x < z)
        return x;
    else if (y < x && y < z)
        return y;
    else
        return z;
}

int editDist(char *str1, char *str2, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1],        // Insert
                                   dp[i - 1][j],        // Remove
                                   dp[i - 1][j - 1]     // Replace
                                  );
        }
    }

    return dp[m][n];
}

int main()
{
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    int dist = editDist(str1, str2, strlen(str1), strlen(str2));

    printf("\nThe Levenshtein Distance between:");
    printf("\n%s", str1);
    printf("\n%s", str2);
    printf("\n\nis %d\n", dist);

    return 0;
}