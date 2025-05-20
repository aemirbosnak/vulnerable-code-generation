//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Function to calculate the Levenshtein Distance between two strings
int calculateLevenshteinDistance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
  
    int matrix[MAX_LEN][MAX_LEN];
  
    // Initializing the matrix
    for (int i=0; i<=len1; i++)
    {
        for (int j=0; j<=len2; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Filling the first row and first column of the matrix
    for (int i=0; i<=len1; i++)
    {
        matrix[i][0] = i;
    }
    for (int j=0; j<=len2; j++)
    {
        matrix[0][j] = j;
    }
  
    for (int i=1; i<=len1; i++)
    {
        for (int j=1; j<=len2; j++)
        {
            if (str1[i-1] == str2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = 1 + min(matrix[i-1][j-1], min(matrix[i][j-1], matrix[i-1][j]));
        }
    }
  
    return matrix[len1][len2];
}

// Function to find the minimum of two numbers
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    char str1[MAX_LEN], str2[MAX_LEN];
  
    printf("Enter the first string: ");
    scanf("%s", str1);
  
    printf("Enter the second string: ");
    scanf("%s", str2);
  
    int distance = calculateLevenshteinDistance(str1, str2);
  
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d.", str1, str2, distance);
  
    return 0;
}