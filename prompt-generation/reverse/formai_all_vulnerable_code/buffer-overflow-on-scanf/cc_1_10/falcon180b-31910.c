//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j, cost;
    int matrix[MAX_LENGTH][MAX_LENGTH];

    // Initialize matrix
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Calculate Levenshtein distance
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            cost = (str1[i - 1] == str2[j - 1])? 0 : 1;
            matrix[i][j] = (matrix[i - 1][j] + 1) - (matrix[i][j - 1] + 1) + cost;
        }
    }

    return matrix[len1][len2];
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    // Get input strings from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Convert input strings to lowercase
    for (int i = 0; i < strlen(str1); i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i = 0; i < strlen(str2); i++) {
        str2[i] = tolower(str2[i]);
    }

    // Calculate Levenshtein distance
    int distance = levenshtein_distance(str1, str2);

    // Output result
    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}