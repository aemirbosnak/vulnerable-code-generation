//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    // Finds the minimum of three integers
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshteinDistance(char* str1, int len1, char* str2, int len2) {
    // Initialize the distance matrix
    int dist[MAX_LEN+1][MAX_LEN+1];
    int i, j;
    for (i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Compute Levenshtein distance using dynamic programming
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
            dist[i][j] = min(dist[i-1][j] + 1, dist[i][j-1] + 1, dist[i-1][j-1] + cost);
        }
    }

    // Return the final result
    return dist[len1][len2];
}

int main() {
    printf("Enter two strings to find the Levenshtein distance between them:\n");

    char str1[MAX_LEN], str2[MAX_LEN];
    printf("String 1: ");
    scanf("%s", str1);
    printf("String 2: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distance = levenshteinDistance(str1, len1, str2, len2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);

    return 0;
}