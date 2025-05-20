//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char*, char*);

int main()
{
    char string1[50], string2[50];

    printf("Enter the first string: ");
    scanf("%s", string1);
    
    printf("Enter the second string: ");
    scanf("%s", string2);

    int distance = levenshtein_distance(string1, string2);

    printf("The Levenshtein distance between %s and %s is %d\n", string1, string2, distance);

    return 0;
}

int levenshtein_distance(char* string1, char* string2)
{
    int m = strlen(string1)+1;
    int n = strlen(string2)+1;

    int distance[m][n];

    for(int i=0; i<m; ++i)
        distance[i][0] = i;

    for(int j=0; j<n; ++j)
        distance[0][j] = j;

    for(int i=1; i<m; ++i)
    {
        for(int j=1; j<n; ++j)
        {
            int cost = 0;
            if(string1[i-1] != string2[j-1])
                cost = 1;

            distance[i][j] = fmin(fmin(distance[i-1][j]+1, distance[i][j-1]+1), distance[i-1][j-1]+cost);
        }
    }

    return distance[m-1][n-1];
}