//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1000

int min(int a, int b) {
    return (a < b)? a : b;
}

void levenshtein_distance(char* str1, char* str2, int* distance) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[MAX_STRING_LENGTH][MAX_STRING_LENGTH];

    // initialize matrix
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    // fill matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]) + 1;
            }
        }
    }

    *distance = matrix[len1][len2];
}

int main() {
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];
    int distance;

    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);

    levenshtein_distance(str1, str2, &distance);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}