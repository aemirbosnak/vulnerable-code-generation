//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int x, int y, int z) {
    /* returns the minimum of three integers */
    if (x < y && x < z) {
        return x;
    } else if (y < x && y < z) {
        return y;
    } else {
        return z;
    } 
}

int lev_distance(char *s, char *t) {
    /* calculates the Levenshtein distance between two strings */
    int s_len = strlen(s);
    int t_len = strlen(t);
    int d[s_len + 1][t_len + 1];
    int i, j;

    for (i = 0; i <= s_len; i++) {
        for (j = 0; j <= t_len; j++) {
            if (i == 0) {
                 d[i][j] = j;
            } else if (j == 0) {
                 d[i][j] = i;
            } else if (s[i-1] == t[j-1]) {
                d[i][j] = d[i-1][j-1];
            } else {
                 d[i][j] = min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + 1);
            }
        }
    }
    return d[s_len][t_len];
}

int main() {
    char s[100], t[100];

    printf("Enter the first string: ");
    scanf("%s", s);

    printf("Enter the second string: ");
    scanf("%s", t);

    int distance = lev_distance(s, t);

    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s, t, distance);

    return 0;
}