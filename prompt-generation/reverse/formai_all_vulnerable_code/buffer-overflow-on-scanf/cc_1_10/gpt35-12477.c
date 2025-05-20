//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void levenshtein_distance(char* s1, char* s2, int n, int m, int matrix[n+1][m+1]);

int main() {
    char s1[MAXLEN], s2[MAXLEN];
    int n, m, i, j;

    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    n = strlen(s1);
    m = strlen(s2);

    int matrix[n+1][m+1];

    levenshtein_distance(s1, s2, n, m, matrix);

    printf("\nThe Levenshtein Distance between %s and %s is %d\n\n", s1, s2, matrix[n][m]);

    printf("Levenshtein Distance Matrix:\n\n");

    for(i = 0; i <= n; i++) {
        for(j = 0; j <= m; j++) {
            printf("%d    ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void levenshtein_distance(char* s1, char* s2, int n, int m, int matrix[n+1][m+1]) {
    int i, j;

    for(i = 0; i <= n; i++) {
        matrix[i][0] = i;
    }

    for(j = 0; j <= m; j++) {
        matrix[0][j] = j;
    }

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = 1 + matrix[i-1][j-1];

                if(matrix[i][j-1] + 1 < matrix[i][j]) {
                    matrix[i][j] = matrix[i][j-1] + 1;
                }

                if(matrix[i-1][j] + 1 < matrix[i][j]) {
                    matrix[i][j] = matrix[i-1][j] + 1;
                }
            }
        }
    }
}