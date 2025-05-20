//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int min(int a, int b) {
    return a < b? a : b;
}

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int lcs[len1 + 1][len2 + 1];
    int lcs_len = 0;

    for (int i = 0; i <= len1; i++) {
        lcs[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        lcs[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1];
            } else {
                lcs[i][j] = min(lcs[i - 1][j], min(lcs[i][j - 1], lcs[i - 1][j - 1])) + 1;
            }

            if (lcs[i][j] == lcs_len) {
                lcs_len++;
            }
        }
    }

    return lcs_len;
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}