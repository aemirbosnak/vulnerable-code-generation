//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 1000

int min(int a, int b) {
    return a < b? a : b;
}

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **matrix = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1]));
            }
        }
    }
    int result = matrix[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return result;
}

int main() {
    char str1[MAX_STRING_SIZE];
    char str2[MAX_STRING_SIZE];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance: %d\n", distance);
    return 0;
}