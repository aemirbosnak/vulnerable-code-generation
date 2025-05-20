//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) {
        return x;
    }
    else if (y <= x && y <= z) {
        return y;
    }
    else {
        return z;
    }
}

int LevenshteinDistance(char* s1, int len1, char* s2, int len2) {
    int d[len1 + 1][len2 + 1];
    int i, j, subCost;
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                d[i][j] = j;
            }
            else if (j == 0) {
                d[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            }
            else {
                subCost = 1;
                d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + subCost);
            }
        }
    }
    return d[len1][len2];
}

int main() {
    char s1[50], s2[50];
    int len1, len2, distance;
    printf("Enter string 1: ");
    scanf("%s", s1);
    len1 = strlen(s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    len2 = strlen(s2);
    distance = LevenshteinDistance(s1, len1, s2, len2);
    printf("Levenshtein Distance between %s and %s is %d", s1, s2, distance);
    return 0;
}