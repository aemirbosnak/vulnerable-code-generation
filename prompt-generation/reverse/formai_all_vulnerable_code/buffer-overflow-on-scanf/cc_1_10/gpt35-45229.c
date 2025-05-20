//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int lev_distance(char* s1, char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int i, j, cost;
    int d[n1+1][n2+1];

    for (i = 0; i <= n1; i++) {
        d[i][0] = i;
    }

    for (j = 0; j <= n2; j++) {
        d[0][j] = j;
    }

    for (j = 1; j <= n2; j++) {
        for (i = 1; i <= n1; i++) {
            if (s1[i-1] == s2[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+cost);
        }
    }

    return d[n1][n2];
}

int main() {
    char word1[100], word2[100];

    printf("Enter first word: ");
    scanf("%s", word1);

    printf("Enter second word: ");
    scanf("%s", word2);

    int distance = lev_distance(word1, word2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}