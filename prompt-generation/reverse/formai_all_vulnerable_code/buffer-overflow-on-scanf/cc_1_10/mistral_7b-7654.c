//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    else
        return z;
}

int levenshtein_distance(char *str1, char *str2, int m, int n) {
    int matrix[MAX_LENGTH + 1][MAX_LENGTH + 1];
    int i, j, cost;

    // Initialize first row and first column
    for (i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= n; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            cost = (tolower(str1[i - 1]) == tolower(str2[j - 1])) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[m][n];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int length1, length2, distance;

    printf("Enter first string: ");
    scanf("%s", str1);
    length1 = strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    length2 = strlen(str2);

    distance = levenshtein_distance(str1, str2, length1, length2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}