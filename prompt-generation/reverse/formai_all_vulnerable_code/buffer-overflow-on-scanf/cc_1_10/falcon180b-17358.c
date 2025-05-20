//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char *s1, char *s2, int n, int m) {
    int d[n + 1][m + 1];
    int i, j;

    for (i = 0; i <= n; i++) {
        d[i][0] = i;
    }

    for (j = 0; j <= m; j++) {
        d[0][j] = j;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
            }
        }
    }

    return d[n][m];
}

int main() {
    char s1[100], s2[100];
    int n, m;

    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    n = strlen(s1);
    m = strlen(s2);

    int distance = levenshtein_distance(s1, s2, n, m);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}