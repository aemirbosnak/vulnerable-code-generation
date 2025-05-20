//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: inquisitive
#include<stdio.h>
#include<string.h>
#define MAX_LEN 100

/* Function to calculate Levenshtein Distance between two strings */
int levenshtein_distance(char* string1, char* string2, int len1, int len2)
{
    int matrix[MAX_LEN][MAX_LEN];

    for(int i=0; i<=len1; i++)
    {
        for(int j=0; j<=len2; j++)
        {
            if(i==0)
                matrix[i][j] = j;
            else if(j==0)
                matrix[i][j] = i;
            else if(string1[i-1] == string2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
        }
    }

    return matrix[len1][len2];
}

/* Function to return minimum of three integers */
int min(int a, int b, int c)
{
    if(a < b && a < c)
        return a;
    else if(b < a && b < c)
        return b;
    else
        return c;
}

int main()
{
    char string1[MAX_LEN];
    char string2[MAX_LEN];
    int len1, len2;

    printf("Welcome to the Levenshtein Distance Calculator!\n\n");

    while(1)
    {
        printf("Enter string 1 (type \"exit\" to quit): ");
        scanf("%s", string1);

        if(strcmp(string1, "exit") == 0)
            break;

        printf("Enter string 2: ");
        scanf("%s", string2);

        len1 = strlen(string1);
        len2 = strlen(string2);

        printf("Levenshtein Distance between \"%s\" and \"%s\" is %d\n\n", string1, string2, levenshtein_distance(string1, string2, len1, len2));
    }

    printf("Thanks for using the Levenshtein Distance Calculator!\n");

    return 0;
}