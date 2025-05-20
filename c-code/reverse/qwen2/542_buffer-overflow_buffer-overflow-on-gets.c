#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024

int min(int a, int b, int c) {
    return (a < b ? a : b) < c ? (a < b ? a : b) : c;
}

void calculateLevenshteinDistance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[MAX_LEN][MAX_LEN];

    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }

    printf("Levenshtein Distance: %d\n", dp[len1][len2]);
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter first string: ");
    gets(str1); // Vulnerable to buffer overflow

    printf("Enter second string: ");
    gets(str2); // Vulnerable to buffer overflow

    calculateLevenshteinDistance(str1, str2);

    return 0;
}
