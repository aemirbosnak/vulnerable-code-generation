//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: invasive
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

int levenshtein_distance(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];
    int i, j;

    for (i = 0; i <= len1; i++)
    {
        for (j = 0; j <= len2; j++)
        {
            if (i == 0)
            {
                matrix[i][j] = j;
            }
            else if (j == 0)
            {
                matrix[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else
            {
                matrix[i][j] = 1 + minimum(matrix[i][j - 1], matrix[i - 1][j], matrix[i - 1][j - 1]);
            }
        }
    }

    return matrix[len1][len2];
}

int main()
{
    char str1[1000], str2[1000];
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein Distance = %d\n", distance);
    return 0;
}