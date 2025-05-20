//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// Function to calculate the Levenshtein distance between two strings
int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int **matrix = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                matrix[i][j] = i + j;
            } else if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    int min_distance = matrix[len1][len2];
    free(matrix[len1]);
    free(matrix);

    return min_distance;
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove newline character

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}