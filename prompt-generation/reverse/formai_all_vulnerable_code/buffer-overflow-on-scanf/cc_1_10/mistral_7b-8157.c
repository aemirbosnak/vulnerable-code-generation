//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char str1[101];
    char str2[101];
    int dist;
} levenshtein_result;

bool is_valid_input(char *str, int max_len) {
    int len = strlen(str);
    return len <= max_len;
}

int manhattan_distance(int x, int y) {
    return abs(x) + abs(y);
}

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

levenshtein_result levenshtein_distance(char *str1, char *str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    if (!is_valid_input(str1, 100) || !is_valid_input(str2, 100)) {
        levenshtein_result err;
        err.dist = -1;
        return err;
    }

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (tolower(str1[i - 1]) == tolower(str2[j - 1])) ? 0 : 1;
            dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + cost);
        }
    }

    levenshtein_result result;
    result.dist = dp[m][n];
    strcpy(result.str1, str1);
    strcpy(result.str2, str2);

    return result;
}

void print_result(levenshtein_result result) {
    printf("Levenshtein Distance between \"%s\" and \"%s\": %d\n", result.str1, result.str2, result.dist);
}

int main() {
    char str1[101], str2[101];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    levenshtein_result res = levenshtein_distance(str1, str2);
    print_result(res);

    return 0;
}