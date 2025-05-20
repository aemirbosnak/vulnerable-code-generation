//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 1000

int levenshtein_distance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int **matrix = malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc(sizeof(int) * (len2 + 1));
    }

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (tolower(str1[i - 1]) == tolower(str2[j - 1])) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    int distance = matrix[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

int main()
{
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Enter string 1: ");
    fgets(str1, MAX_LEN, stdin);
    printf("Enter string 2: ");
    fgets(str2, MAX_LEN, stdin);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}