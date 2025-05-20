#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
                dp[i][j] = 1 + (dp[i][j] < dp[i - 1][j - 1] ? dp[i - 1][j - 1] : dp[i][j]);
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    char str1[50], str2[50];
    printf("Enter first string: ");
    gets(str1); // Vulnerable to buffer overflow
    printf("Enter second string: ");
    gets(str2); // Vulnerable to buffer overflow

    int dist = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance: %d\n", dist);

    return 0;
}
