//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
        return c;
}

int levenshtein(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int cost;

    int matrix[m+1][n+1];

    for (int i = 0; i <= m; i++)
        matrix[i][0] = i;

    for (int j = 0; j <= n; j++)
        matrix[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1])
                cost = 0;
            else
                cost = 1;

            matrix[i][j] = min(matrix[i-1][j] + 1,
                                matrix[i][j-1] + 1,
                                matrix[i-1][j-1] + cost);
        }
    }

    return matrix[m][n];
}

int main() {
    char s1[100], s2[100];

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    int result = levenshtein(s1, s2);

    printf("The Levenshtein Distance between %s and %s is %d", s1, s2, result);

    return 0;
}