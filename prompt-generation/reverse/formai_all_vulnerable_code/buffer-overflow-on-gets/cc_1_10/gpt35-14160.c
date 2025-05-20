//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

//function to calculate Levenshtein Distance
int LevenshteinDistance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[len1+1][len2+1];
    
    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i == 0) {
                matrix[i][j] = j;
            } else if(j == 0) {
                matrix[i][j] = i;
            } else if(s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1]);
            }
        }
    }
    
    return matrix[len1][len2];
}

//function to find minimum among three integers
int min(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    } else if(b < a && b < c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    char s1[100], s2[100];
    printf("Enter string 1: ");
    gets(s1);
    printf("Enter string 2: ");
    gets(s2);
    
    int distance = LevenshteinDistance(s1, s2);
    
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d", s1, s2, distance);
    
    return 0;
}