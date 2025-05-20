//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) 
{
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int levenshtein(char *a, char *b, int m, int n) 
{
    int matrix[m + 1][n + 1];
    
    for(int i = 0; i <= m; i++) 
    {
        for(int j = 0; j <= n; j++) 
        {
            if(i == 0) 
            {
                matrix[i][j] = j;
            } 
            else if(j == 0) 
            {
                matrix[i][j] = i;
            } 
            else if(a[i - 1] == b[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1];
            } 
            else 
            {
                matrix[i][j] = 1 + min(matrix[i][j - 1], matrix[i - 1][j], matrix[i - 1][j - 1]);
            }
        }
    }
  
    return matrix[m][n];
}

int main() 
{
    char a[100], b[100];
    printf("Enter string 1: ");
    scanf("%s", a);
    printf("Enter string 2: ");
    scanf("%s", b);

    int m = strlen(a), n = strlen(b);
    int distance = levenshtein(a, b, m, n);

    printf("Levenshtein Distance between %s and %s is: %d\n", a, b, distance);

    return 0;
}