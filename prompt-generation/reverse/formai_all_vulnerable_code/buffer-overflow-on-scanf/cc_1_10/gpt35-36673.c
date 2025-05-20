//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100

int minimum(int a, int b, int c) {
    int min = a;
    if(b < min) {
        min = b;
    }
    if(c < min) {
        min = c;
    }
    return min;
}

int compute_levenshtein_distance(char *string1, char *string2) {
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    // Create a matrix to hold the distances
    int distance[len1 + 1][len2 + 1];

    // Initialize the first row and column
    for(int i = 0; i <= len1; i++) {
        distance[i][0] = i;
    }

    for(int j = 0; j <= len2; j++) {
        distance[0][j] = j;
    }

    // Fill in the rest of the matrix
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            int substitution_cost = 0;
            if(string1[i - 1] != string2[j - 1]) {
                substitution_cost = 1;
            }

            distance[i][j] = minimum(
                distance[i - 1][j] + 1,
                distance[i][j - 1] + 1,
                distance[i - 1][j - 1] + substitution_cost
            );
        }
    }

    return distance[len1][len2];
}

int main() {
    char string1[MAX_LEN], string2[MAX_LEN];
    printf("Enter the first string: ");
    scanf("%s", string1);
    printf("Enter the second string: ");
    scanf("%s", string2);

    int result = compute_levenshtein_distance(string1, string2);
    printf("The Levenshtein distance between %s and %s is %d\n", string1, string2, result);

    return 0;
}