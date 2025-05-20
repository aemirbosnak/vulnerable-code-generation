//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c)
{
    int min = a;
    
    if (b < min)
    {
        min = b;
    }
    
    if (c < min)
    {
        min = c;
    }
    
    return min;
}

int LevenshteinDistance(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int distance[len1 + 1][len2 + 1];
    
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0)
            {
                distance[i][j] = j;
            }
            else if (j == 0)
            {
                distance[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                distance[i][j] = distance[i - 1][j - 1];
            }
            else
            {
                distance[i][j] = 1 + minimum(distance[i][j - 1],
                                             distance[i - 1][j],
                                             distance[i - 1][j - 1]);
            }
        }
    }
    
    return distance[len1][len2];
}

int main()
{
    char s1[50];
    char s2[50];
    
    printf("Enter the first string: ");
    scanf("%s", s1);
    
    printf("Enter the second string: ");
    scanf("%s", s2);
    
    int distance = LevenshteinDistance(s1, s2);
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", s1, s2, distance);
    
    return 0;
}