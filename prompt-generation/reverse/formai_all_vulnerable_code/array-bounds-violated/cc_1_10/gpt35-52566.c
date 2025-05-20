//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int min(int a, int b, int c) {
    if(a < b && a < c)
        return a;
    else if(b < c)
        return b;
    else
        return c;
}

int calculateLevenshteinDistance(char *str1, char *str2, int len1, int len2) {
    int cost = 0;
    int i, j;
    int **matrix = (int **) malloc((len1+1) * sizeof(int *));
    for(i = 0; i <= len1; i++)
        matrix[i] = (int *) malloc((len2+1) * sizeof(int));

    for(i = 0; i <= len1; i++)
        matrix[i][0] = i;

    for(j = 0; j <= len2; j++)
        matrix[0][j] = j;

    for(i = 1; i <= len1; i++) {
        for(j = 1; j <= len2; j++) {
            cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + cost);
        }
    }
    int dist = matrix[len1][len2];

    for(i = 0; i <= len1; i++)
        free(matrix[i]);
    free(matrix);

    return dist;
}

int main() {
    char str1[MAX_STRING_LENGTH], str2[MAX_STRING_LENGTH];
    int len1, len2;

    printf("Enter the first string: ");
    fgets(str1, MAX_STRING_LENGTH, stdin);
    len1 = strlen(str1);
    str1[len1-1] = '\0';
    len1 -= 1;

    printf("Enter the second string: ");
    fgets(str2, MAX_STRING_LENGTH, stdin);
    len2 = strlen(str2);
    str2[len2-1] = '\0';
    len2 -= 1;

    int dist = calculateLevenshteinDistance(str1, str2, len1, len2);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, dist);

    return 0;
}