//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: realistic
#include <stdio.h>
#include <string.h>

// Function to calculate Levenshtein Distance
int levenshteinDistance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a 2D array to store distance values
    int dist[m+1][n+1];

    // Initialize first row and first column
    for(int i=0; i<=m; i++) {
        dist[i][0] = i;
    }
    for(int j=0; j<=n; j++) {
        dist[0][j] = j;
    }

    // Calculate distance value for each cell
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            } else {
                int minDist = dist[i-1][j];
                if(dist[i][j-1] < minDist) {
                    minDist = dist[i][j-1];
                }
                if(dist[i-1][j-1] < minDist) {
                    minDist = dist[i-1][j-1];
                }
                dist[i][j] = minDist + 1;
            }
        }
    }

    // Return the distance value
    return dist[m][n];
}

int main() {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int dist = levenshteinDistance(s1, s2);

    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, dist);

    return 0;
}