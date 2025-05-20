//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to calculate the minimum of three integers
int min(int a, int b, int c) {
    return (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
}

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);

    // Create a 2D array to store the Levenshtein distances
    int** distance = (int**)malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++) {
        distance[i] = (int*)malloc(sizeof(int) * (n + 1));
    }

    // Initialize the first row and column of the array
    for (int i = 0; i <= m; i++) {
        distance[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        distance[0][j] = j;
    }

    // Fill in the rest of the array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                distance[i][j] = distance[i - 1][j - 1];
            } else {
                distance[i][j] = 1 + min(distance[i - 1][j], distance[i][j - 1], distance[i - 1][j - 1]);
            }
        }
    }

    // Free the memory allocated for the array
    for (int i = 0; i <= m; i++) {
        free(distance[i]);
    }
    free(distance);

    return distance[m][n];
}

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];

    // Get two strings from the user
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    // Calculate and display the Levenshtein distance between the two strings
    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", s1, s2, distance);

    return 0;
}