//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: lively
#include<stdio.h>
#include<string.h>

int minimum(int a, int b, int c)
{
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else
        return c;
}

int levenshteinDistance(char str1[], char str2[], int m, int n)
{
    int matrix[m+1][n+1];

    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++)
        {
            if(i==0)
                matrix[i][j] = j;
            else if(j==0)
                matrix[i][j] = i;
            else if(str1[i-1] == str2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = 1 + minimum(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
        }

    return matrix[m][n];
}

int main()
{
    char str1[100], str2[100];

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    int m = strlen(str1);
    int n = strlen(str2);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d", str1, str2, levenshteinDistance(str1, str2, m, n));

    return 0;
}