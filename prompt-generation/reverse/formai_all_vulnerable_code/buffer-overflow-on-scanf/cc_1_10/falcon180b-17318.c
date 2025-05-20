//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

int levenshtein_distance(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    int** matrix = (int**)malloc(sizeof(int*) * (m+1));
    for(int i=0; i<=m; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * (n+1));
        memset(matrix[i], 0, sizeof(int) * (n+1));
    }
    for(int i=0; i<=m; i++) {
        matrix[i][0] = i;
    }
    for(int j=0; j<=n; j++) {
        matrix[0][j] = j;
    }
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1;
            }
        }
    }
    int distance = matrix[m][n];
    for(int i=0; i<=m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);
    return 0;
}