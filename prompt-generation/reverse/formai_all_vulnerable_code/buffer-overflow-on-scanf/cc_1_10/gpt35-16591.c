//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c)
{
    if(a<b)
    {
        if(a<c)
            return a;
        else
            return c;
    }
    else
    {
        if(b<c)
            return b;
        else
            return c;
    }
}

int lev_distance(char* str1, char* str2, int m, int n)
{
    int arr[m+1][n+1];
    int i,j;
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        {
            // if first string is empty, add all the characters of the second string
            if(i==0)
                arr[i][j] = j;
            // if second string is empty, add all the characters of the first string
            else if(j==0)
                arr[i][j] = i;
            // if the characters match, then no need to do anything
            else if(str1[i-1]==str2[j-1])
                arr[i][j] = arr[i-1][j-1];
            // if the characters don't match, find the minimum of three operations: insert, delete and replace
            else
                arr[i][j] = 1 + min(arr[i][j-1], arr[i-1][j], arr[i-1][j-1]);
        }
    }
    return arr[m][n];
}

int main()
{
    char str1[100], str2[100];
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    scanf("%s", str1);
    printf("Please enter the second string: ");
    scanf("%s", str2);
    int m = strlen(str1);
    int n = strlen(str2);
    int dist = lev_distance(str1, str2, m, n);
    printf("The Levenshtein Distance between %s and %s is %d.\n", str1, str2, dist);
    printf("Hooray! Your calculation is complete!\n");
    return 0;
}