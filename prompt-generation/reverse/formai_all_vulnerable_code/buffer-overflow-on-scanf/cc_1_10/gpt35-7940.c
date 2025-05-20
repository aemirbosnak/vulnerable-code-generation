//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c)
{
    if (a < b && a < c)
        return a;
    if (b < a && b < c)
        return b;
    return c;
}

int LevenshteinDistance(char *s1, char *s2, int m, int n)
{
    int i, j, cost;
    int distance[m+1][n+1];

    for (i = 0; i <= m; i++)
        distance[i][0] = i;
    for (j = 0; j <= n; j++)
        distance[0][j] = j;

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= m; i++) {
            if (s1[i-1] == s2[j-1])
                cost = 0;
            else
                cost = 1;
            distance[i][j] = min(distance[i-1][j] + 1, distance[i][j-1] + 1,
                                    distance[i-1][j-1] + cost);
        }
    }

    return distance[m][n];
}

int main()
{
    char s1[100], s2[100];
    int m, n;
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    m = strlen(s1);
    n = strlen(s2);

    printf("The Levenshtein Distance between %s and %s is %d\n", s1, s2,
           LevenshteinDistance(s1, s2, m, n));
    return 0;
}