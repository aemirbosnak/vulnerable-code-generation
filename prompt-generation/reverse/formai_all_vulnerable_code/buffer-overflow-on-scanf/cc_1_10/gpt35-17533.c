//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}

int levenshteinDistance(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);

    if (n == 0) {
        return m;
    }
    if (m == 0) {
        return n;
    }

    int d[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        d[0][j] = j;
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int substitutionCost = (s[i-1] == t[j-1]) ? 0 : 1;
            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+substitutionCost);
        }
    }

    return d[n][m];
}

int main() {
    char s[MAX_LENGTH];
    char t[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", s);

    printf("Enter second string: ");
    scanf("%s", t);

    int distance = levenshteinDistance(s, t);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s, t, distance);

    return 0;
}