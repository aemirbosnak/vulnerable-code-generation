//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to calculate Levenshtein distance between two strings
int levenshtein_distance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[MAX_LEN][MAX_LEN];
    int i, j, cost;

    // Initialize the matrix with the cost of deleting or inserting characters
    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // Fill in the rest of the matrix
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                cost = 1;
                matrix[i][j] = matrix[i - 1][j] + 1;
                if (matrix[i - 1][j - 1] > matrix[i][j - 1] + 1) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                }
                if (matrix[i - 1][j] > matrix[i][j - 1] + 1) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }
    }

    return matrix[len1][len2];
}

int main()
{
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    // Get input strings from user
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Calculate and print Levenshtein distance
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}