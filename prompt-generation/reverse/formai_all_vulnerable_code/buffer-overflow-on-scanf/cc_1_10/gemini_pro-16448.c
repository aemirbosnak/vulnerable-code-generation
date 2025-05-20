//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the Levenshtein distance between two strings
int levenshtein(const char *s1, const char *s2)
{
    // Get the lengths of the strings
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a matrix to store the distances
    int d[m + 1][n + 1];

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= m; i++)
        d[i][0] = i;
    for (int j = 0; j <= n; j++)
        d[0][j] = j;

    // Calculate the Levenshtein distance for each cell in the matrix
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                d[i][j] = d[i - 1][j - 1];
            else
                d[i][j] = 1 + fmin(fmin(d[i - 1][j], d[i][j - 1]), d[i - 1][j - 1]);
        }
    }

    // Return the Levenshtein distance
    return d[m][n];
}

// Print a greeting to the user
void greet(void)
{
    printf("Welcome to the Levenshtein distance calculator!\n");
    printf("Enter two strings, and I will tell you how different they are.\n");
    printf("The Levenshtein distance is a measure of the number of edits (insertions, deletions, or substitutions) that are required to transform one string into another.\n");
    printf("The smaller the Levenshtein distance, the more similar the two strings are.\n");
}

// Get two strings from the user
void get_strings(char **s1, char **s2)
{
    printf("Enter the first string: ");
    scanf("%s", *s1);
    printf("Enter the second string: ");
    scanf("%s", *s2);
}

// Print the Levenshtein distance
void print_distance(int distance)
{
    printf("The Levenshtein distance between the two strings is %d.\n", distance);
}

// The main function
int main(void)
{
    // Greet the user
    greet();

    // Get two strings from the user
    char *s1 = malloc(100);
    char *s2 = malloc(100);
    get_strings(&s1, &s2);

    // Calculate the Levenshtein distance
    int distance = levenshtein(s1, s2);

    // Print the Levenshtein distance
    print_distance(distance);

    // Free the allocated memory
    free(s1);
    free(s2);

    return 0;
}