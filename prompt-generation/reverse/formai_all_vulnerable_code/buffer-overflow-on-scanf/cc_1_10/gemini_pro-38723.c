//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256

int main()
{
    char *str1, *str2;
    int len1, len2, i, j, cost;
    int matrix[MAX_LEN][MAX_LEN];

    printf("Enter two strings to calculate Levenshtein distance: ");
    scanf("%s %s", str1, str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    // Initialize matrix with zeros
    for (i = 0; i <= len1; i++)
    {
        for (j = 0; j <= len2; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Fill first row and first column with non-zero values
    for (i = 1; i <= len1; i++)
    {
        matrix[i][0] = i;
    }
    for (j = 1; j <= len2; j++)
    {
        matrix[0][j] = j;
    }

    // Calculate Levenshtein distance
    for (i = 1; i <= len1; i++)
    {
        for (j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                cost = 0;
            }
            else
            {
                cost = 1;
            }

            matrix[i][j] = min(matrix[i - 1][j] + 1,             // Deletion
                               min(matrix[i][j - 1] + 1,         // Insertion
                                   matrix[i - 1][j - 1] + cost)); // Substitution
        }
    }

    // Print the Levenshtein distance
    printf("Levenshtein distance: %d\n", matrix[len1][len2]);

    return 0;
}

int min(int a, int b, int c)
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