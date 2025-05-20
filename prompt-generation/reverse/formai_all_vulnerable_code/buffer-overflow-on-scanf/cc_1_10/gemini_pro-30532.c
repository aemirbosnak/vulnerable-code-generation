//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STR_LEN 1024

int levenshtein_distance(const char *str1, const char *str2, int len1, int len2) {
    int matrix[len1 + 1][len2 + 1];
    int i, j;

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    return matrix[len1][len2];
}

int min(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c;
    }
    else {
        return b < c ? b : c;
    }
}

int main(void) {
    char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
    int len1, len2;

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}