//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISTANCE 100

// Function to calculate the Levenshtein Distance between two strings
int levenshtein_distance(char* s1, char* s2) {
    int i, j, cost;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Initialize the distance matrix
    int distance_matrix[MAX_DISTANCE][MAX_DISTANCE];
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                distance_matrix[i][j] = j;
            } else if (j == 0) {
                distance_matrix[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {
                distance_matrix[i][j] = distance_matrix[i-1][j-1];
            } else {
                cost = 1;
                distance_matrix[i][j] = distance_matrix[i-1][j] + 1;
                if (distance_matrix[i-1][j] > distance_matrix[i][j-1] + 1) {
                    distance_matrix[i][j] = distance_matrix[i-1][j] + 1;
                }
                if (distance_matrix[i][j-1] > distance_matrix[i-1][j] + 1) {
                    distance_matrix[i][j] = distance_matrix[i][j-1] + 1;
                }
                if (distance_matrix[i-1][j-1] > distance_matrix[i-1][j] + cost) {
                    distance_matrix[i][j] = distance_matrix[i-1][j] + cost;
                }
            }
        }
    }

    return distance_matrix[len1][len2];
}

int main() {
    char string1[100], string2[100];

    // Get input strings from user
    printf("Enter first string: ");
    scanf("%s", string1);
    printf("Enter second string: ");
    scanf("%s", string2);

    // Calculate Levenshtein Distance
    int distance = levenshtein_distance(string1, string2);

    // Print the result
    printf("Levenshtein Distance between '%s' and '%s' is %d\n", string1, string2, distance);

    return 0;
}