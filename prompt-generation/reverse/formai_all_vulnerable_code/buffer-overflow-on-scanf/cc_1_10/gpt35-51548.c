//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int L[m + 1][n + 1];
    int i, j;
    
    for (i = 0; i <= m; i++) {
        L[i][0] = i;
    }
    for (j = 0; j <= n; j++) {
        L[0][j] = j;
    }
    
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                L[i][j] = L[i - 1][j - 1];
            } else {
                int deletion = L[i - 1][j] + 1;
                int insertion = L[i][j - 1] + 1;
                int substitution = L[i - 1][j - 1] + 1;
                int min = deletion;
                if (insertion < min) {
                    min = insertion;
                }
                if (substitution < min) {
                    min = substitution;
                }
                L[i][j] = min;
            }
        }
    }
    return L[m][n];
}

void main() {
    printf("Welcome to the Levenshtein Distance Calculator!\n\n");
    printf("This program will compare two strings and calculate their Levenshtein Distance.\n\n");
    
    char s1[50], s2[50];
    printf("Enter the first string: ");
    scanf("%s", &s1);
    printf("Enter the second string: ");
    scanf("%s", &s2);
    
    int distance = levenshtein_distance(s1, s2);
    printf("\nThe Levenshtein Distance between \"%s\" and \"%s\" is %d.\n\n", s1, s2, distance);
    printf("Thank you for using the Levenshtein Distance Calculator!\n");
}