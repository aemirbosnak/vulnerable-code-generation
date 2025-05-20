//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void print_matrix(int d[][MAX_LENGTH], int n, int m) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}

int min(int x, int y, int z) {
    return (x < y)? ((x < z)? x : z) : ((y < z)? y : z);
}

int levenshtein_distance(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    int d[MAX_LENGTH][MAX_LENGTH];

    for (int i = 0; i <= n; i++) {
        d[i][0] = i;
    }

    for (int j = 0; j <= m; j++) {
        d[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = 1 + min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]);
            }
        }
    }

    return d[n][m];
}

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];

    printf("Enter string 1: ");
    scanf("%s", s1);

    printf("Enter string 2: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}