//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) { // helper function for finding minimum value among three integers
    if(a <= b && a <= c) {
        return a;
    }
    else if(b <= a && b <= c) {
        return b;
    }
    else {
        return c;
    }
}

int levenshteinDistance(char* s1, char* s2) { // function to calculate Levenshtein distance between two strings
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1 + 1][len2 + 1];

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                matrix[i][j] = j;
            }
            else if(j == 0) {
                matrix[i][j] = i;
            }
            else if(s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else {
                matrix[i][j] = 1 + min(matrix[i][j - 1], matrix[i - 1][j], matrix[i - 1][j - 1]);
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char word1[100], word2[100];
    printf("Enter first word: ");
    scanf("%s", word1);
    printf("Enter second word: ");
    scanf("%s", word2);
    int distance = levenshteinDistance(word1, word2);
    printf("The Levenshtein distance between %s and %s is %d.\n", word1, word2, distance);
    return 0;
}