//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(const char *string1, const char *string2)
{
    int string_length1 = strlen(string1);
    int string_length2 = strlen(string2);

    // Allocate enough memory for our matrix
    int **matrix = malloc((string_length1 + 1) * sizeof(int *));
    for (int i = 0; i <= string_length1; i++)
    {
        matrix[i] = malloc((string_length2 + 1) * sizeof(int));
        matrix[i][0] = i;
    }
    for (int j = 0; j <= string_length2; j++)
    {
        matrix[0][j] = j;
    }

    // Perform the calculation
    for (int i = 1; i <= string_length1; i++)
    {
        for (int j = 1; j <= string_length2; j++)
        {
            int cost = (string1[i - 1] == string2[j - 1]) ? 0 : 1;
            matrix[i][j] = fmin(matrix[i - 1][j] + 1,
                                 fmin(matrix[i][j - 1] + 1,
                                      matrix[i - 1][j - 1] + cost));
        }
    }

    // Store the result and free the memory
    int result = matrix[string_length1][string_length2];
    for (int i = 0; i <= string_length1; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return result;
}

int main()
{
    char string1[100], string2[100];
    printf("Welcome to the Levenshtein Distance Calculator! Enter two words and we will tell you how similar they are.\n");
    printf("First word: ");
    scanf("%s", string1);
    printf("Second word: ");
    scanf("%s", string2);
    int distance = levenshtein_distance(string1, string2);
    printf("\nThe Levenshtein distance between %s and %s is %d.\n", string1, string2, distance);
    printf("Thanks for using our calculator, come back soon!\n");
    return 0;
}