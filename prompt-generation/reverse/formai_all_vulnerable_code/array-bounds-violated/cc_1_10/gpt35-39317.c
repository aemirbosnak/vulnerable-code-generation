//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void levenshteinDistance(char str1[], char str2[]) {
    int cost[MAX_LEN][MAX_LEN];

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int i, j;

    // initialize the matrix
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0)
                cost[i][j] = j;
            else if (j == 0)
                cost[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                cost[i][j] = cost[i - 1][j - 1];
            else
                cost[i][j] = 1 + minimum(cost[i - 1][j], cost[i][j - 1], cost[i - 1][j - 1]);
        }
    }

    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d\n", str1, str2, cost[len1][len2]);
}

int minimum(int a, int b, int c) {
    int min = a < b ? a : b;
    min = min < c ? min : c;
    return min;
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("*** Welcome to Levenshtein Distance Calculator!!! ***\n\n");

    printf("Please enter 1st string: ");
    fgets(str1, MAX_LEN, stdin); // Safely reads input with whitespaces

    printf("Please enter 2nd string: ");
    fgets(str2, MAX_LEN, stdin); // Safely reads input with whitespace

    // remove newline characters
    str1[strlen(str1) - 1] = '\0';
    str2[strlen(str2) - 1] = '\0';

    levenshteinDistance(str1, str2);

    printf("\nThank you for using Levenshtein Distance Calculator!\n");

    return 0;
}