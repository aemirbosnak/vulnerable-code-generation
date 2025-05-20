//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int levenshtein_distance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int matrix[MAX_LENGTH][MAX_LENGTH];
    int i, j;

    // Initialize matrix
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Fill in matrix
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];

    // Get input strings
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);

    // Convert strings to lowercase
    for (int i = 0; i < strlen(s1); i++) {
        s1[i] = tolower(s1[i]);
    }
    for (int i = 0; i < strlen(s2); i++) {
        s2[i] = tolower(s2[i]);
    }

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(s1, s2);

    // Print result
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}