//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = len1 < len2? len1 : len2;
    int i, j;
    int matrix[MAX_LENGTH][MAX_LENGTH];
    memset(matrix, 0, sizeof(matrix));

    for (i = 0; i < min_len; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j < min_len; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i < min_len; i++) {
        for (j = 1; j < min_len; j++) {
            int cost;
            if (str1[i - 1] == str2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = matrix[i - 1][j] + 1;
            matrix[i][j] = matrix[i][j - 1] + 1;
            matrix[i][j] = matrix[i - 1][j - 1] + cost;
        }
    }

    return matrix[len1 - 1][len2 - 1];
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, distance);

    return 0;
}