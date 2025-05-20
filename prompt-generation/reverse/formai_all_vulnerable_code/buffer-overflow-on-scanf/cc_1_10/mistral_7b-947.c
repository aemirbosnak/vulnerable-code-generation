//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
}

int levenshtein_distance(char *str1, char *str2, int length1, int length2) {
    int matrix[length1 + 1][length2 + 1];
    int i, j, cost;

    for (i = 0; i <= length1; i++) {
        for (j = 0; j <= length2; j++) {
            if (i == 0)
                matrix[i][j] = j;
            else if (j == 0)
                matrix[i][j] = i;
            else if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                cost = str1[i - 1] != str2[j - 1] ? 1 : 2; // cost = 1 for substitution, cost = 2 for insertion or deletion
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + cost;
            }
        }
    }

    return matrix[length1][length2];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int length1, length2, distance;

    printf("Enter first string: ");
    scanf("%s", str1);
    length1 = strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    length2 = strlen(str2);

    distance = levenshtein_distance(str1, str2, length1, length2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}