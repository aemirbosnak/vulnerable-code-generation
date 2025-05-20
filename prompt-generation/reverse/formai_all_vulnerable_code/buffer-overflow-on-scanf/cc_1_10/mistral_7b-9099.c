//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void print_matrix(int matrix[MAX_LENGTH + 1][MAX_LENGTH + 1]) {
    int i, j;
    for (i = 0; i <= MAX_LENGTH; i++) {
        for (j = 0; j <= MAX_LENGTH; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int calculate_levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    int i, j, cost, prev_cost;

    int matrix[len1 + 1][len2 + 1];

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            cost = str1[i - 1] == str2[j - 1] ? 0 : 1;
            prev_cost = matrix[i - 1][j];

            matrix[i][j] = 1 + MIN(MIN(prev_cost, matrix[i][j - 1]), prev_cost + cost);
        }
    }

    return matrix[len1][len2];
}

int MIN(int a, int b) {
    return a < b ? a : b;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int len1, len2;

    printf("Enter first string: ");
    scanf("%s", str1);
    len1 = strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    len2 = strlen(str2);

    int distance = calculate_levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein Distance: %d\n", distance);

    int matrix[len1 + 1][len2 + 1];
    calculate_levenshtein_distance(str1, str2, len1, len2);
    printf("Matrix:\n");
    print_matrix(matrix);

    return 0;
}