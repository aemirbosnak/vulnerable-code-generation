//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int x, int y, int z) {
    int min = x;
    if (y < min) {
        min = y;
    }
    if (z < min) {
        min = z;
    }
    return min;
}

int LevenshteinDistance(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);
    int d[n + 1][m + 1];
   
    for(int i = 0; i<=n; i++) {
        d[i][0] = i;
    }

    for(int j=0; j<=m; j++) {
        d[0][j] = j;
    }
    
    int substitution_cost = 0;
    for(int j=1; j<=m; j++) {
        for(int i=1; i<=n; i++) {
            if(s[i-1] == t[j-1]) {
                substitution_cost = 0;
            }
            else {
                substitution_cost = 1;
            }
            d[i][j] = minimum(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+substitution_cost);
        }
    }
    return d[n][m];
}

int main() {

    printf("Welcome to the Levenshtein Distance calculator! \n");

    char word1[100];
    char word2[100];
    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);

    int distance = LevenshteinDistance(word1, word2);

    printf("The Levenshtein Distance between %s and %s is %d.", word1, word2, distance);

    return 0;
}