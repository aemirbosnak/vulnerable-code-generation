//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int min(int a, int b, int c) {
    return (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
}

void print_matrix(int dist[MAX][MAX], int m, int n) {
    int i, j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int levenshtein_distance(char string1[], char string2[]) {
    int m = strlen(string1);
    int n = strlen(string2);
    int dist[MAX][MAX];

    // Initialize the matrix
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dist[i][j] = j;
            else if (j == 0)
                dist[i][j] = i;
            else if (string1[i - 1] == string2[j - 1])
                dist[i][j] = dist[i - 1][j - 1];
            else
                dist[i][j] = 1 + min(dist[i - 1][j], dist[i][j - 1], dist[i - 1][j - 1]);
        }
    }

    // Print the matrix
    printf("Levenshtein Distance Matrix:\n");
    print_matrix(dist, m, n);

    return dist[m][n];
}

int main() {
    char string1[MAX], string2[MAX];
    printf("Enter first string: ");
    scanf("%s", string1);
    printf("Enter second string: ");
    scanf("%s", string2);

    int distance = levenshtein_distance(string1, string2);
    printf("\nLevenshtein Distance: %d\n", distance);

    return 0;
}