//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int levenshtein(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[MAX_LENGTH][MAX_LENGTH];
    int i, j, cost;

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
                if (i > 1 && j > 1 && s1[i - 1] == s2[j - 2] && tolower(s1[i - 2]) == tolower(s2[j - 1])) {
                    matrix[i][j] = matrix[i - 2][j - 2] + cost;
                }
                if (i > 1 && j > 1 && s1[i - 1] == s2[j - 1] && tolower(s1[i - 2])!= tolower(s2[j - 2])) {
                    matrix[i][j] = matrix[i - 2][j - 2] + 2;
                }
            }
        }
    }

    return matrix[len1][len2];
}

int main()
{
    char s1[MAX_LENGTH], s2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int distance = levenshtein(s1, s2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}