//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int levenshteinDistance(char* str1, char* str2, int len1, int len2) {
    int d[len1 + 1][len2 + 1]; // Distance matrix

    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = isalpha(str1[i - 1]) && isalpha(str2[j - 1])
                         ? abs(tolower(str1[i - 1]) - tolower(str2[j - 1]))
                         : 1;

            d[i][j] = MIN(MIN(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
        }
    }

    return d[len1][len2];
}

void printResult(int distance, char* str1, char* str2) {
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
}

int main() {
    char str1[100], str2[100];
    int len1, len2;

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    len1 = strlen(str1) - 1; // Remove newline character

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    len2 = strlen(str2) - 1; // Remove newline character

    int distance = levenshteinDistance(str1, str2, len1, len2);
    printResult(distance, str1, str2);

    return 0;
}