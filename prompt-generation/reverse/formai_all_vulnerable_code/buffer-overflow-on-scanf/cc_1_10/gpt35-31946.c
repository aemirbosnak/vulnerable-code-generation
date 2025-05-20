//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int min_val = a;
    if (b < min_val) min_val = b;
    if (c < min_val) min_val = c;
    return min_val;
}

// Function to calculate Levenshtein Distance between two strings
int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a 2D array to store the distances
    int** dist = (int**)malloc(sizeof(int*) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int*)malloc(sizeof(int) * (len2 + 1));
    }
    
    // Initialize the first row and column with 0 to len2 and len1 respectively
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Fill in the remaining values
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dist[i][j] = dist[i-1][j-1]; // no operation required
            }
            else {
                dist[i][j] = min(dist[i-1][j], dist[i][j-1], dist[i-1][j-1]) + 1; // insert/delete/replace
            }
        }
    }

    // Store the final answer and free the memory
    int ans = dist[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return ans;
}

// Main function
int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    int dist = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance is %d\n", dist);

    return 0;
}