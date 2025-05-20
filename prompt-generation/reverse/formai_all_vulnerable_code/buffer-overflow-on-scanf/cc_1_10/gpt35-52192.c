//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) { min = b; }
    if (c < min) { min = c; }
    return min;
}

int levenshtein(char *a, int m, char *b, int n) {

    int **d;
    d = (int**) calloc(m+1, sizeof(int*));
    for (int i = 0; i <= m; i++) {
        d[i] = (int*) calloc(n+1, sizeof(int));
        d[i][0] = i;
    }

    for (int j = 1; j <= n; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int del = d[i-1][j] + 1;
            int ins = d[i][j-1] + 1;
            int sub = d[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1);
            d[i][j] = min(del, ins, sub);
        }
    }

    int distance = d[m][n];

    // Free the memory allocated for the matrix
    for (int i = 0; i < m+1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;

}

int main() {

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("This program calculates the minimum number of edits needed\n");
    printf("to transform one string into another.\n\n");

    char a[100], b[100];
    int m, n;

    printf("Please enter the first string: ");
    scanf("%s", a);
    m = strlen(a);

    printf("Please enter the second string: ");
    scanf("%s", b);
    n = strlen(b);

    int dist = levenshtein(a, m, b, n);

    printf("\n%s and %s have a Levenshtein distance of %d.\n", a, b, dist);

    printf("\nThank you for using the Levenshtein Distance Calculator!\n");

    return 0;

}