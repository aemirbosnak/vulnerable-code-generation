//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Alan Touring
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 100

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    }
    else if (y < x && y < z) {
        return y;
    }
    else {
        return z;
    }
}

int levenshteinDistance(char* s1, char* s2) {
    int m = strlen(s1) + 1;
    int n = strlen(s2) + 1;
    int distance[m][n];
    int i, j, deletion, insertion, substitution;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                distance[i][j] = i + j;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            }
            else {
                deletion = distance[i - 1][j] + 1;
                insertion = distance[i][j - 1] + 1;
                substitution = distance[i - 1][j - 1] + 1;
                distance[i][j] = min(deletion, insertion, substitution);
            }
        }
    }
    return distance[m - 1][n - 1];
}

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    printf("The Levenshtein distance between the two strings is %d\n", levenshteinDistance(s1, s2));
    return 0;
}