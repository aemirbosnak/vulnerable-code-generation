#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            matrix[i][j] = (str1[i - 1] == str2[j - 1] ? 0 : 1);
            matrix[i][j] += min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + matrix[i][j]);
        }
    }

    return matrix[len1][len2];
}

int main() {
    char str1[1000], str2[1000];

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    printf("Levenshtein distance: %d\n", levenshtein_distance(str1, str2, len1, len2));

    return 0;
}
