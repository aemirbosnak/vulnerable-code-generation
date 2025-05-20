//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to calculate the minimum of three integers */
int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

/* Function to calculate the Levenshtein Distance */
int levenshtein_distance(char* str1, char* str2) {

    // Obtain length of the two strings
    int len1 = strlen(str1), len2 = strlen(str2);
    int i, j, cost;

    // Create a 2D table to store cost of conversions
    int** dp = (int**)malloc((len1 + 1) * sizeof(int*));
    for (i = 0; i <= len1; i++)
        dp[i] = (int*)malloc((len2 + 1) * sizeof(int));

    // Initialize the table with the base case
    for (i = 0; i <= len1; i++)
        dp[i][0] = i;

    for (j = 0; j <= len2; j++)
        dp[0][j] = j;

    // Fill in the table using the recurrence relation
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            // Calculate the cost of conversion
            if (str1[i - 1] == str2[j - 1])
                cost = 0;
            else
                cost = 1;
            // Fill in the table
            dp[i][j] = minimum(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
        }
    }

    // Obtain the final distance from the table
    int distance = dp[len1][len2];

    // Free the memory used by the table
    for (i = 0; i <= len1; i++)
        free(dp[i]);
    free(dp);

    return distance;
}

/* Main function */
int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.", str1, str2, distance);

    return 0;
}