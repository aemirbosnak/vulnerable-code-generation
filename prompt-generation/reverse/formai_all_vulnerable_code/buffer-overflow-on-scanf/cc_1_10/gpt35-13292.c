//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c)
{
    if(a < b && a < c)
        return a;
    else if(b < a && b < c)
        return b;
    else
        return c;
}

int calculateLevenshteinDistance(char* s1, char* s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int distanceMatrix[m+1][n+1];

    for(int i=0; i<=m; ++i)
        distanceMatrix[i][0] = i;

    for(int j=0; j<=n; ++j)
        distanceMatrix[0][j] = j;

    for(int i=1; i<=m; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            int deletion = distanceMatrix[i-1][j] + 1;
            int insertion = distanceMatrix[i][j-1] + 1;
            int substitution = distanceMatrix[i-1][j-1] + cost;
            distanceMatrix[i][j] = min(deletion, insertion, substitution);
        }
    }

    return distanceMatrix[m][n];
}

int main()
{
    char s1[100], s2[100];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    int distance = calculateLevenshteinDistance(s1, s2);
    printf("The Levenshtein distance between %s and %s is %d\n", s1, s2, distance);
    return 0;
}