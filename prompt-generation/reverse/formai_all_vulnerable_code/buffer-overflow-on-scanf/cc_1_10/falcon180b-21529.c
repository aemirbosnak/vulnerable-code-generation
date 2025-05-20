//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int max_len = len1 > len2? len1 : len2;
    int dp[MAX_LENGTH][MAX_LENGTH];
    int i, j;

    // Initialize the dp array
    for (i = 0; i <= max_len; i++) {
        for (j = 0; j <= max_len; j++) {
            dp[i][j] = i * j;
        }
    }

    // Calculate the Levenshtein distance
    for (i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j] + 1;
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);

    return 0;
}