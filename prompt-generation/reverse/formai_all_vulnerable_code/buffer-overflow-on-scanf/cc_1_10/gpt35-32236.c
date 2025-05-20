//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the calculateLevenshteinDistance function
int calculateLevenshteinDistance(char *s1, char *s2)
{
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);

    int table[s1_len + 1][s2_len + 1];

    // Initialize the first row and column of the table
    for (int i = 0; i <= s1_len; i++) {
        table[i][0] = i;
    }
    for (int j = 0; j <= s2_len; j++) {
        table[0][j] = j;
    }

    // Populate the table with the Levenshtein distance values
    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            int cost = (s1[i - 1] != s2[j - 1]);
            int min_distance = table[i - 1][j] + 1;
            if (table[i][j - 1] + 1 < min_distance) {
                min_distance = table[i][j - 1] + 1;
            }
            if (table[i - 1][j - 1] + cost < min_distance) {
                min_distance = table[i - 1][j - 1] + cost;
            }
            table[i][j] = min_distance;
        }
    }

    // Return the Levenshtein distance
    return table[s1_len][s2_len];
}

// Main function that takes two strings as input and calculates their Levenshtein distance
int main()
{
    char s1[100], s2[100];
    printf("Enter two strings: ");
    scanf("%s %s", s1, s2);

    int distance = calculateLevenshteinDistance(s1, s2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}