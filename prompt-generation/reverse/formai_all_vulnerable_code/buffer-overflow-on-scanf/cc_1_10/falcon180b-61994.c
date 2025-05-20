//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int levenshteinDistance(char *string1, char *string2, int len1, int len2) {
    int i, j, cost;
    int matrix[MAX_LENGTH][MAX_LENGTH];

    // Initialize the matrix with increasing costs
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (tolower(string1[i - 1]) == tolower(string2[j - 1])) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
                matrix[i][j] = matrix[i][j - 1] + 1;
                matrix[i][j] = matrix[i - 1][j - 1] + (tolower(string1[i - 1])!= tolower(string2[j - 1]));
            }
        }
    }

    return matrix[len1][len2];
}

int main() {
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];

    printf("Enter string 1: ");
    scanf("%s", string1);

    printf("Enter string 2: ");
    scanf("%s", string2);

    int len1 = strlen(string1);
    int len2 = strlen(string2);

    int distance = levenshteinDistance(string1, string2, len1, len2);

    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", string1, string2, distance);

    return 0;
}