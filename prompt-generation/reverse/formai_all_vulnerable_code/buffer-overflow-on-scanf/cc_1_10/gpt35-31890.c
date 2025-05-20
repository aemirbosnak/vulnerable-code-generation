//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: sophisticated
// Levenshtein Distance Calculator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find minimum of three values
int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

// Function to calculate Levenshtein Distance
int levenshteinDistance(char *s, char *t, int slen, int tlen) {
    int **distanceMatrix;
    int i, j, cost;

    // Create distance matrix
    distanceMatrix = (int **)malloc(sizeof(int *) * (slen + 1));
    for (i = 0; i <= slen; i++) {
        distanceMatrix[i] = (int *)malloc(sizeof(int) * (tlen + 1));
        distanceMatrix[i][0] = i;
    }
    for (j = 0; j <= tlen; j++) {
        distanceMatrix[0][j] = j;
    }

    // Calculate Levenshtein Distance
    for (j = 1; j <= tlen; j++) {
        for (i = 1; i <= slen; i++) {
            cost = (s[i-1] == t[j-1]) ? 0 : 1;
            distanceMatrix[i][j] = minimum(distanceMatrix[i-1][j] + 1, distanceMatrix[i][j-1] + 1, distanceMatrix[i-1][j-1] + cost);
        }
    }

    // Return Levenshtein Distance
    int result = distanceMatrix[slen][tlen];

    // Free distance matrix memory
    for (i = 0; i <= slen; i++) {
        free(distanceMatrix[i]);
    }
    free(distanceMatrix);

    return result;
}

int main() {
    char s[100], t[100];
    int slen, tlen, distance;

    // Read input strings
    printf("Enter string s: ");
    scanf("%s", s);
    slen = strlen(s);

    printf("Enter string t: ");
    scanf("%s", t);
    tlen = strlen(t);

    // Calculate Levenshtein Distance
    distance = levenshteinDistance(s, t, slen, tlen);

    // Output Levenshtein Distance
    printf("Levenshtein Distance between %s and %s is %d\n", s, t, distance);

    return 0;
}