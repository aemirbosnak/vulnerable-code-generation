//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    }
    if (y < z) {
        return y;
    } 
    return z;
}

int levenshtein_distance(char* s, char* t, int m, int n) {
    int distance[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        distance[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        distance[0][j] = j;
    }

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (s[i-1] == t[j-1]) {
                distance[i][j] = distance[i-1][j-1];
            } else {
                distance[i][j] = min(distance[i-1][j], distance[i][j-1], distance[i-1][j-1]) + 1;
            }
        }
    }

    return distance[m][n];
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];

    printf("Enter string 1: ");
    fgets(str1, MAX_SIZE, stdin);

    printf("Enter string 2: ");
    fgets(str2, MAX_SIZE, stdin);

    int len1 = strlen(str1) - 1;
    int len2 = strlen(str2) - 1;

    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, levenshtein_distance(str1, str2, len1, len2));

    return 0;
}