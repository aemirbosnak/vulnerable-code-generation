//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function that returns the minimum of three numbers
int min(int a, int b, int c)
{
    if(a <= b && a <= c)
        return a;
    else if(b <= a && b <= c)
        return b;
    else
        return c;
}

// Function to calculate the Levenshtein distance between two strings
int levDist(char *str1, char *str2, int m, int n)
{
    // Create and initialize a 2D array to store the distances
    int dist[m+1][n+1];
    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++)
            dist[i][j] = 0;
    
    // Initialize the first row and first column of the array
    for(int i=1; i<=m; i++)
        dist[i][0] = i;
    for(int j=1; j<=n; j++)
        dist[0][j] = j;
    
    // Fill in the rest of the array
    for(int j=1; j<=n; j++)
    {
        for(int i=1; i<=m; i++)
        {
            if(str1[i-1] == str2[j-1])
                dist[i][j] = dist[i-1][j-1];
            else
                dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]) + 1;
        }
    }
    
    return dist[m][n];
}

int main()
{
    char str1[MAX], str2[MAX];
    int m, n, dist;
    
    printf("#############################################\n");
    printf("#                                           #\n");
    printf("#   RETRO LEVENSHTEIN DISTANCE CALCULATOR   #\n");
    printf("#                                           #\n");
    printf("#############################################\n");
    printf("\nEnter the first string: ");
    scanf("%[^\n]s", str1);
    getchar();
    printf("Enter the second string: ");
    scanf("%[^\n]s", str2);
    getchar();
    m = strlen(str1);
    n = strlen(str2);
    dist = levDist(str1, str2, m, n);
    printf("\nThe Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, dist);
    
    return 0;
}