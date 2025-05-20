//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

void levenshteinDistance(char *str1, char *str2, int len1, int len2) {
    int table[MAX_LEN][MAX_LEN];
    int i, j, cost;

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0)
                table[i][j] = j;
            else if (j == 0)
                table[i][j] = i;
            else if (str1[i-1] == str2[j-1])
                table[i][j] = table[i-1][j-1];
            else {
                cost = 1;
                table[i][j] = min(table[i-1][j] + 1,             // deletion
                                  table[i][j-1] + 1,             // insertion
                                  table[i-1][j-1] + cost);       // substitution
            }
        }
    }

    printf("\nLevenshtein Distance: %d\n", table[len1][len2]);
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    int len1 = 0, len2 = 0;

    printf("Enter string 1: ");
    fgets(str1, MAX_LEN, stdin);
    len1 = strlen(str1)-1;
    str1[len1] = '\0';

    printf("Enter string 2: ");
    fgets(str2, MAX_LEN, stdin);
    len2 = strlen(str2)-1;
    str2[len2] = '\0';

    levenshteinDistance(str1, str2, len1, len2);

    return 0;
}