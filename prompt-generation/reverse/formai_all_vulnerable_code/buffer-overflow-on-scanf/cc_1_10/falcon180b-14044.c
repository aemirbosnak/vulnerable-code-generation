//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int min(int a, int b, int c) {
    return a < b? (a < c? a : c) : (b < c? b : c);
}

void levenshtein_distance(char* str1, char* str2, int* distance) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == 0) {
        *distance = len2;
        return;
    }

    if (len2 == 0) {
        *distance = len1;
        return;
    }

    int matrix[MAX_LEN][MAX_LEN];

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    *distance = matrix[len1][len2];
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance;
    levenshtein_distance(str1, str2, &distance);

    printf("Levenshtein distance: %d\n", distance);

    return 0;
}