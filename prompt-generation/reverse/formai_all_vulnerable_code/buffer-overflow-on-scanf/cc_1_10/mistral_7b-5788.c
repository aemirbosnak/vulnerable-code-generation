//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100

int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    return z;
}

int levenshtein_distance(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    if (m > MAX_STRING_LENGTH || n > MAX_STRING_LENGTH) {
        fprintf(stderr, "Input strings are too long.\n");
        exit(EXIT_FAILURE);
    }

    if (m == 0)
        return n;

    if (n == 0)
        return m;

    int matrix[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[m][n];
}

int main() {
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}