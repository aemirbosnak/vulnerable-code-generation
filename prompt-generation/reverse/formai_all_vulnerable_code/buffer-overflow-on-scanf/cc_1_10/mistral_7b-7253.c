//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to calculate the Levenshtein distance using dynamic programming
int levenshtein_distance(const char *str1, const char *str2, int m, int n) {
    int dp[m + 1][n + 1];

    // Initialize first row and column
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Fill the rest of the matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[m][n];
}

// Helper function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to compare two strings and calculate their Levenshtein distance
void compare_strings(const char *str1, const char *str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    if (length1 > MAX_LENGTH || length2 > MAX_LENGTH) {
        printf("Error: strings too long\n");
        return;
    }

    int distance = levenshtein_distance(str1, str2, length1, length2);
    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);

    compare_strings(str1, str2);

    return 0;
}