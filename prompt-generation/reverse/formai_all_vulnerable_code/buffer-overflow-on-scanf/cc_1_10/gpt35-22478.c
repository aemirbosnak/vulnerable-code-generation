//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c)
{
    int min_ab = a < b ? a : b;
    return min_ab < c ? min_ab : c;
}

int levenshteinDistance(char* s1, char* s2)
{
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);
    int i, j;

    int memo[MAX_LENGTH][MAX_LENGTH];

    for(i = 0; i <= s1_length; i++)
    {
        memo[i][0] = i;
    }

    for(i = 0; i <= s2_length; i++)
    {
        memo[0][i] = i;
    }

    for(i = 1; i <= s1_length; i++)
    {
        for(j = 1; j <= s2_length; j++)
        {
            int subst_cost = s1[i-1] != s2[j-1];

            memo[i][j] = min(memo[i-1][j] + 1,
                             memo[i][j-1] + 1,
                             memo[i-1][j-1] + subst_cost);
        }
    }

    return memo[s1_length][s2_length];
}

int main()
{
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    int distance = levenshteinDistance(s1, s2);

    printf("The Levenshtein Distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}