//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

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

int LevenshteinDistance(char *s, int len_s, char *t, int len_t) {
    int d[len_s+1][len_t+1];
    int i, j, cost;

    for (i = 0; i <= len_s; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= len_t; j++) {
        d[0][j] = j;
    }

    for (j = 1; j <= len_t; j++) {
        for (i = 1; i <= len_s; i++) {
            if (s[i-1] == t[j-1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+cost);    
        }
    }

    return d[len_s][len_t];
}

int main() {
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];
    int len_str1, len_str2;

    printf("Enter first string: ");
    fgets(str1, MAX_STRING_LENGTH, stdin);
    len_str1 = strlen(str1) - 1; // -1 to remove newline character

    printf("Enter second string: ");
    fgets(str2, MAX_STRING_LENGTH, stdin);
    len_str2 = strlen(str2) - 1; // -1 to remove newline character

    printf("Levenshtein Distance between %s and %s: %d", str1, str2, LevenshteinDistance(str1, len_str1, str2, len_str2));

    return 0;
}