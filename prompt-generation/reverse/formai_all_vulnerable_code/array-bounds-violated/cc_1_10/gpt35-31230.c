//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to calculate minimum of 3 numbers
int min(int a, int b, int c)
{
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}

// Function to calculate levenshtein distance between 2 strings
int levenshtein_distance(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int matrix[MAX_LENGTH][MAX_LENGTH];

    // Initializing top row and left column with increasing values
    for(int i=0;i<=len1;i++)
        matrix[i][0]=i;
    for(int j=0;j<=len2;j++)
        matrix[0][j]=j;

    // Filling up the matrix row by row
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(s1[i-1]==s2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
        }
    }

    // Returning the final value of the bottom right corner
    return matrix[len1][len2];
}

int main(void)
{
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter the first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    str1[strlen(str1)-1] = '\0';

    printf("Enter the second string: ");
    fgets(str2, MAX_LENGTH, stdin);
    str2[strlen(str2)-1] = '\0';

    int distance = levenshtein_distance(str1, str2);

    printf("The levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}