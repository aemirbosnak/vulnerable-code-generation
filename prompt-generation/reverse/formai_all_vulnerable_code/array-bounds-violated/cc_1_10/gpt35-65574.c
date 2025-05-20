//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: careful
#include <stdio.h>
#include <string.h>

/* Define maximum length of each string */
#define MAXLEN 100

/* Define function to calculate minimum of three values */
int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

/* Define function to calculate Levenshtein Distance */
int levenshteinDistance(char *s1, char *s2) {
    /* Calculate length of each string */
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    /* Define 2D array to store distances */
    int distance[len1 + 1][len2 + 1];

    /* Initialize first row */
    for (int i = 0; i <= len1; i++)
        distance[i][0] = i;

    /* Initialize first column */
    for (int j = 0; j <= len2; j++)
        distance[0][j] = j;

    /* Calculate Levenshtein Distance for each substring */
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1])
                distance[i][j] = distance[i - 1][j - 1];
            else
                distance[i][j] = 1 + min(distance[i][j - 1], distance[i - 1][j], distance[i - 1][j - 1]);
        }
    }

    /* Return final Levenshtein Distance */
    return distance[len1][len2];
}

/* Main function */
int main() {
    /* Define two strings */
    char str1[MAXLEN], str2[MAXLEN];

    /* Input first string */
    printf("Enter first string: ");
    fgets(str1, MAXLEN, stdin);

    /* Input second string */
    printf("Enter second string: ");
    fgets(str2, MAXLEN, stdin);

    /* Remove newline character */
    str1[strlen(str1) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';

    /* Calculate and print Levenshtein Distance */
    printf("Levenshtein Distance: %d\n", levenshteinDistance(str1, str2));

    /* Terminate program */
    return 0;
}