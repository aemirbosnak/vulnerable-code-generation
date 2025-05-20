//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_DISTANCE 1000

void levenshtein_distance(char* s1, char* s2, int* distance) {
    int i, j, cost, min_cost;
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Initialize the matrix
    int matrix[MAX_DISTANCE][MAX_DISTANCE];
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Compute the matrix
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            cost = s1[i - 1] == s2[j - 1]? 0 : 1;
            min_cost = matrix[i - 1][j] + 1;
            matrix[i][j] = matrix[i - 1][j] < matrix[i][j - 1]? matrix[i - 1][j] + 1 : matrix[i][j - 1] + 1;
            matrix[i][j] = matrix[i][j] < min_cost? matrix[i][j] : min_cost;
        }
    }

    // Store the result
    *distance = matrix[len1][len2];
}

int main() {
    char s1[100], s2[100];
    int distance;

    // Read input strings
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    // Compute Levenshtein distance
    levenshtein_distance(s1, s2, &distance);

    // Print the result
    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", s1, s2, distance);

    return 0;
}