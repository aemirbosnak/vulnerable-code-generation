//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LEN 1000

int min(int a, int b) {
    return a < b? a : b;
}

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 == 0) {
        return len2;
    } else if (len2 == 0) {
        return len1;
    }

    int d[MAX_LEN][MAX_LEN];
    int i, j;

    for (i = 0; i <= len1; i++) {
        d[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        d[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = min(d[i - 1][j], d[i][j - 1]) + 1;
            }
        }
    }

    return d[len1][len2];
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", s1, s2, distance);

    return 0;
}