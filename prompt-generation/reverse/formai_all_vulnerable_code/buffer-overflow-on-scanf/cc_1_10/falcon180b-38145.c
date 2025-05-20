//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int min(int a, int b, int c) {
    if (a < b)
        return a;
    else if (b < c)
        return b;
    else
        return c;
}

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int d[MAX_SIZE][MAX_SIZE];
    int i, j;

    for (i = 0; i <= len1; i++) {
        d[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
            }
        }
    }

    return d[len1][len2];
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}