//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c)
{
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int cost;
    int i, j;
    int **matrix = (int **)malloc((len1+1) * sizeof(int *));
    for (i = 0; i < len1+1; i++) {
        matrix[i] = (int *)malloc((len2+1) * sizeof(int));
    }

    for (i = 0; i < len1+1; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j < len2+1; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i < len1+1; i++) {
        for (j = 1; j < len2+1; j++) {
            if (str1[i-1] == str2[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            matrix[i][j] = minimum(matrix[i-1][j] + 1, 
                                    matrix[i][j-1] + 1, 
                                    matrix[i-1][j-1] + cost);
        }
    }

    int distance = matrix[len1][len2];

    for (i = 0; i < len1+1; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return distance;
}

int main()
{
    char str1[100];
    char str2[100];
    printf("Enter the first string:\n");
    scanf("%s", str1);
    printf("Enter the second string:\n");
    scanf("%s", str2);
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance between %s and %s is %d\n", str1, str2, distance);
    return 0;
}