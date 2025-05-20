//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c)
{
    if(a <= b && a <= c)
        return a;
    else if(b <= a && b <= c)
        return b;
    else
        return c;
}

int levenshteinDistance(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int matrix[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            //initially fill up the first row and column of the matrix with incrementing integers
            if(i==0)
            {
                matrix[i][j] = j;
            }
            else if(j==0)
            {
                matrix[i][j] = i;
            }

            //if the characters match, don't do anything
            else if(s1[i-1] == s2[j-1])
            {
                matrix[i][j] = matrix[i-1][j-1];
            }

            //otherwise calculate the minimum of all three operations and add 1
            else
            {
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
            }
        }
    }

    //return the final result from the matrix
    return matrix[m][n];
}

int main()
{
    char s1[100], s2[100];

    printf("Greetings, dear traveller! Let us calculate the Levenshtein Distance between two words.\n");

    printf("What shall the first word be, sire? ");
    scanf("%s", s1);

    printf("And the second word, my lord? ");
    scanf("%s", s2);

    printf("Calculating...\n");

    int result = levenshteinDistance(s1, s2);

    printf("Ah, the Levenshtein Distance between '%s' and '%s' is %d. Safe travels, my liege.\n", s1, s2, result);

    return 0;
}