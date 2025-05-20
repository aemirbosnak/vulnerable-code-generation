//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    if(a<b) {
        if(a<c) {
            return a;
        } else {
            return c;
        }
    } else {
        if(b<c) {
            return b;
        } else {
            return c;
        }
    }
}

int getLevenshteinDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int i, j, matrix[MAX_LEN+1][MAX_LEN+1];
    
    for(i=0;i<=len1;i++) {
        for(j=0;j<=len2;j++) {
            if(i==0) {
                matrix[i][j] = j;
            } else if(j==0) {
                matrix[i][j] = i;
            } else if(word1[i-1]==word2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
            }
        }
    }
    
    return matrix[len1][len2];
}

int main(void) {
    char word1[MAX_LEN], word2[MAX_LEN];
    printf("Enter word 1: ");
    scanf("%s", word1);
    printf("Enter word 2: ");
    scanf("%s", word2);
    printf("Levenshtein Distance between %s and %s: %d", word1, word2, getLevenshteinDistance(word1, word2));
    return 0;
}