#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int levenshtein(char *str1, char *str2) {
    int d[MAX_LEN][MAX_LEN];
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i <= len1; i++) d[i][0] = i;
    for (int j = 0; j <= len2; j++) d[0][j] = j;

    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            d[i][j] = 1 + min(d[i-1][j-1] + (str1[i-1] == str2[j-1] ? 0 : 1),
                              min(d[i-1][j] + 1, d[i][j-1] + 1));

    return d[len1][len2];
}

int min(int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    printf("Levenshtein distance: %d\n", levenshtein(str1, str2));

    return 0;
}
