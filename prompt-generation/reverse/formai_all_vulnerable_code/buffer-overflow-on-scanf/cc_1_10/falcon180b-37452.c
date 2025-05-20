//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int levenshteinDistance(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int distance[MAX_LENGTH][MAX_LENGTH];
    int i, j;

    // Initialize the distance matrix
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                distance[i][j] = j;
            } else if (j == 0) {
                distance[i][j] = i;
            } else if (isalpha(s1[i-1]) && isalpha(s2[j-1])) {
                if (tolower(s1[i-1]) == tolower(s2[j-1])) {
                    distance[i][j] = distance[i-1][j-1];
                } else {
                    distance[i][j] = distance[i-1][j] + 1;
                }
            } else {
                distance[i][j] = distance[i][j-1] + 1;
            }
        }
    }

    return distance[len1][len2];
}

int main() {
    char s1[MAX_LENGTH], s2[MAX_LENGTH];

    // Get input strings from user
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    // Calculate Levenshtein distance
    int distance = levenshteinDistance(s1, s2);

    // Output result
    printf("Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, distance);

    return 0;
}