//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leven(int len1, int len2, char *word1, char *word2);

int main()
{
    int len1, len2, result;
    char word1[50], word2[50];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first word: ");
    scanf("%s", word1);
    printf("Please enter the second word: ");
    scanf("%s", word2);
    
    len1 = strlen(word1);
    len2 = strlen(word2);
    
    result = leven(len1, len2, word1, word2);
    
    printf("The Levenshtein Distance between %s and %s is %d.\n", word1, word2, result);
    printf("Now here is a puzzle for you to solve!\n");
    printf("What is the longest word you can create by removing %d letters from %s?\n", result, word1);

    return 0;
}

int leven(int len1, int len2, char *word1, char *word2)
{
    int matrix[len1 + 1][len2 + 1];
    int i, j, cost;
    
    for (i = 0; i <= len1; i++)
    {
        for (j = 0; j <= len2; j++)
        {
            if (i == 0) matrix[i][j] = j;
            else if (j == 0) matrix[i][j] = i;
            else if (word1[i - 1] == word2[j - 1]) matrix[i][j] = matrix[i - 1][j - 1];
            else
            {
                cost = 1; //default cost
                if (i > 1 && j > 1 && word1[i - 2] == word2[j - 1] && word1[i - 1] == word2[j - 2]) //transposition check
                    cost = 0.5;
                matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
            }
        }
    }
    
    return matrix[len1][len2];
}