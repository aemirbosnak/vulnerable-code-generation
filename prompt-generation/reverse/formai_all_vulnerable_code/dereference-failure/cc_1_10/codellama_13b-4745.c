//Code Llama-13B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
// Levenshtein Distance Calculator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Levenshtein Distance Struct
typedef struct {
    int i;
    int j;
    int cost;
} LevenshteinDist;

// Levenshtein Distance Calculator Function
int levenshteinDist(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    LevenshteinDist* dist = (LevenshteinDist*) malloc(m * n * sizeof(LevenshteinDist));

    // Initialize Distance Matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dist[i * n + j].i = i;
            dist[i * n + j].j = j;
            dist[i * n + j].cost = 0;
        }
    }

    // Calculate Distance Matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int cost = 0;
            if (s1[i] != s2[j]) {
                cost = 1;
            }
            dist[i * n + j].cost = cost;
        }
    }

    // Find Minimum Distance
    int min_dist = dist[0].cost;
    for (int i = 1; i < m * n; i++) {
        if (dist[i].cost < min_dist) {
            min_dist = dist[i].cost;
        }
    }

    // Free Distance Matrix
    free(dist);

    return min_dist;
}

// Test Levenshtein Distance Calculator
int main() {
    char* s1 = "kitten";
    char* s2 = "sitting";
    int dist = levenshteinDist(s1, s2);
    printf("Levenshtein Distance: %d\n", dist);
    return 0;
}