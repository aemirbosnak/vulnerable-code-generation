//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int x, int y, int z)
{
    if (x < y && x < z)
        return x;
    else if (y < x && y < z)
        return y;
    else
        return z;
}

int levenshteinDistance(char *s1, char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2);
    int matrix[len1+1][len2+1];

    for (int i = 0; i <= len1; i++) 
        matrix[i][0] = i;
    for (int i = 0; i <= len2; i++) 
        matrix[0][i] = i;

    for (int i = 1; i <= len1; i++) 
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i-1] == s2[j-1]) 
                matrix[i][j] = matrix[i-1][j-1];
            else 
                matrix[i][j] = min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]) + 1;
        }
    }

    return matrix[len1][len2];
}

int main(void)
{
    char s1[MAX_LEN], s2[MAX_LEN];

    printf("Enter string 1: ");
    scanf("%s", s1);

    printf("Enter string 2: ");
    scanf("%s", s2);

    int distance = levenshteinDistance(s1, s2);

    printf("The Levenshtein Distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}