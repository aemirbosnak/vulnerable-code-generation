//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

/*Function to find minimum of three numbers */
int min(int a, int b, int c) {
    int lowest = a;
    if (b < lowest)
        lowest = b;
    if (c < lowest)
        lowest = c;
    return lowest;
}

/* Function to find Levenshtein distance between two strings */
int levenshtein_distance(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j, cost;
    int matrix[len1+1][len2+1];

    for (i = 0; i <= len1; i++)
        matrix[i][0] = i;

    for (j = 0; j <= len2; j++)
        matrix[0][j] = j;

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {

            /* If characters at current i and j positions are same,
               cost is 0. Otherwise 1. */
            if (s1[i-1] == s2[j-1])
                cost = 0;
            else
                cost = 1;

            matrix[i][j] = min(matrix[i-1][j] + 1,          /* Deletion */
                                matrix[i][j-1] + 1,         /* Insertion */
                                matrix[i-1][j-1] + cost);   /* Substitution */
        }
    }

    return matrix[len1][len2];
}

int main(void) {
    char string1[100], string2[100];
    int distance;

    printf("Welcome to the Levenshtein Distance Calculator\n\n");

    printf("Please enter the first string: ");
    scanf("%s", string1);

    printf("Please enter the second string: ");
    scanf("%s", string2);

    distance = levenshtein_distance(string1, string2);

    printf("\nThe Levenshtein distance between the two strings is %d\n", distance);

    printf("\nThe world has faced an apocalypse. The Levenshetein Distance Calculator is the only tool left for the survivors. They use the tool to calculate the distance between the mutated words in their new language. The closer the words, the closer the communication and the higher their chances of survival.\n");
    return 0;
}