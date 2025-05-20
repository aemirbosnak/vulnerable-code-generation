//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[MAX_LEN][MAX_LEN];

    // Initialize matrix with 0 to MAX_LEN
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = i;
        }
    }

    // Calculate Levenshtein distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = matrix[i-1][j] + 1;
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    // Get input strings
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Print result
    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}