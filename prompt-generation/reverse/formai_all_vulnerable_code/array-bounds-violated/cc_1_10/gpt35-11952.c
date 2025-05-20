//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshteinDistance(char *s1, int len1, char *s2, int len2) {
    int cost[2][MAX_LEN+1];
    int i, j, res;
    for (j = 0; j <= len2; j++) {
        cost[0][j] = j;
    }
    for (i = 1; i <= len1; i++) {
        cost[i % 2][0] = i;
        for (j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                cost[i % 2][j] = cost[(i-1) % 2][j-1];
            } else {
                cost[i % 2][j] = min(1 + cost[(i-1) % 2][j], 
                                     1 + cost[i % 2][j-1], 
                                     1 + cost[(i-1) % 2][j-1]);
            }
        }
    }
    res = cost[len1 % 2][len2];
    return res;
}

int main() {
    char s1[MAX_LEN];
    char s2[MAX_LEN];
    int len1, len2, dist;

    printf("Enter the first string: ");
    fgets(s1, MAX_LEN, stdin);
    len1 = strlen(s1);
    if (s1[len1-1] == '\n') {
        s1[--len1] = '\0';
    }

    printf("Enter the second string: ");
    fgets(s2, MAX_LEN, stdin);
    len2 = strlen(s2);
    if (s2[len2-1] == '\n') {
        s2[--len2] = '\0';
    }

    dist = levenshteinDistance(s1, len1, s2, len2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, dist);

    return 0;
}