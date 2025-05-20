//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int calculate_distance(char* s1, char* s2);
int min(int a, int b, int c);

int main()
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    printf("Enter the first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    printf("Enter the second string: ");
    fgets(str2, MAX_LENGTH, stdin);

    int distance = calculate_distance(str1, str2);
    printf("The Levenshtein distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}

int calculate_distance(char* s1, char* s2)
{
    int len1 = strlen(s1) - 1;
    int len2 = strlen(s2) - 1;
    int matrix[MAX_LENGTH][MAX_LENGTH];
    int i, j;

    for (i = 0; i <= len1; i++)
        matrix[i][0] = i;
    for (j = 0; j <= len2; j++)
        matrix[0][j] = j;

    for (i = 1; i <= len1; i++)
    {
        for (j = 1; j <= len2; j++)
        {
            if (s1[i-1] == s2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = min(matrix[i-1][j],
                                    matrix[i][j-1],
                                    matrix[i-1][j-1]) + 1;
        }
    }
    return matrix[len1][len2];
}

int min(int a, int b, int c)
{
    if (a < b && a < c)
        return a;
    if (b < a && b < c)
        return b;
    if (c < a && c < b)
        return c;
}