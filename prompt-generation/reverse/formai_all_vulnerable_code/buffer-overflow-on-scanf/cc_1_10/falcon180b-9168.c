//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[MAX_LEN][MAX_LEN];
    int i, j;

    for (i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];

    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}