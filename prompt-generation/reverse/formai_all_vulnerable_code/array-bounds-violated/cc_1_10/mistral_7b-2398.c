//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void initMatrix(int dist[][MAX_LENGTH], int len1, int len2) {
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }
}

void calculateLevenshteinDistance(int dist[][MAX_LENGTH], int len1, int len2, const char *str1, const char *str2) {
    for (int i = 1; str1[i - 1] != '\0'; i++) {
        for (int j = 1; str2[j - 1] != '\0'; j++) {
            if (tolower(str1[i - 1]) == tolower(str2[j - 1])) {
                dist[i][j] = dist[i - 1][j - 1];
            } else {
                dist[i][j] = 1 + min(min(dist[i - 1][j], dist[i][j - 1]), dist[i - 1][j - 1]);
            }
        }
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int len1 = 0, len2 = 0;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    len1 = strlen(str1) - 1;
    str1[len1] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    len2 = strlen(str2) - 1;
    str2[len2] = '\0';

    int dist[MAX_LENGTH][MAX_LENGTH];
    initMatrix(dist, len1 + 1, len2 + 1);
    calculateLevenshteinDistance(dist, len1, len2, str1, str2);

    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", str1, str2, dist[len1][len2]);

    return 0;
}