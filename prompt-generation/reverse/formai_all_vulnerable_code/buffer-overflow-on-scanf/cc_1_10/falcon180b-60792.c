//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_LENGTH 1000

int min(int a, int b, int c)
{
    if(a < b)
    {
        if(a < c)
            return a;
        else
            return c;
    }
    else
    {
        if(b < c)
            return b;
        else
            return c;
    }
}

int levenshtein_distance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **matrix = (int **)malloc(sizeof(int *) * (len1 + 1));
    for(int i = 0; i <= len1; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        for(int j = 0; j <= len2; j++)
            matrix[i][j] = 0;
    }
    for(int i = 0; i <= len1; i++)
        matrix[i][0] = i;
    for(int j = 0; j <= len2; j++)
        matrix[0][j] = j;
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(str1[i-1] == str2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = 1 + min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
        }
    }
    free(matrix[0]);
    free(matrix);
    return matrix[len1][len2];
}

int main()
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance: %d\n", distance);
    return 0;
}