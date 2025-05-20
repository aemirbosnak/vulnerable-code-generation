//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    else
        return c;
}

int levenshtein_distance(char *s1, int len1, char *s2, int len2)
{
    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min(dp[i][j - 1],
                                    dp[i - 1][j],
                                    dp[i - 1][j - 1]);
        }
    }
 
    return dp[len1][len2];
}
 
int main()
{
    char s1[100], s2[100];
    
    printf("Enter first string: ");
    scanf("%s", s1);
    
    printf("Enter second string: ");
    scanf("%s", s2);
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    int distance = levenshtein_distance(s1, len1, s2, len2);
    
    printf("Levenshtein Distance: %d", distance);
    
    return 0;
}