//Gemma-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: standalone
#include <stdio.h>
#include <string.h>

int levenshtein_distance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[len1][len2];
    int i, j, d;

    for (i = 0; i < len1; i++)
    {
        matrix[i][0] = i;
    }

    for (j = 0; j < len2; j++)
    {
        matrix[0][j] = j;
    }

    for (i = 1; i < len1; i++)
    {
        for (j = 1; j < len2; j++)
        {
            d = abs(str1[i - 1] - str2[j - 1]) + matrix[i - 1][j - 1];
            matrix[i][j] = d;
            if (matrix[i][j] < matrix[i - 1][j])
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            if (matrix[i][j] < matrix[i][j - 1])
            {
                matrix[i][j] = matrix[i][j - 1];
            }
        }
    }

    return matrix[len1][len2];
}

int main()
{
    char str1[] = "abc";
    char str2[] = "bcd";

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein distance between %s and %s is %d.\n", str1, str2, distance);

    return 0;
}