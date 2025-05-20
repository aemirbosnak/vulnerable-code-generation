//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STR_LEN 1024

int min(int a, int b, int c) {
    int min1 = a;
    if (b < min1) min1 = b;
    if (c < min1) min1 = c;
    return min1;
}

int levenshtein_distance(char *str1, char *str2) {
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    int matrix[str1_len + 1][str2_len + 1];

    for (int i = 0; i <= str1_len; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= str2_len; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= str1_len; i++) {
        for (int j = 1; j <= str2_len; j++) {
            int cost = str1[i - 1] == str2[j - 1] ? 0 : 1;
            matrix[i][j] = min(
                matrix[i - 1][j] + 1,  // Deletion
                matrix[i][j - 1] + 1,  // Insertion
                matrix[i - 1][j - 1] + cost  // Substitution
            );
        }
    }

    return matrix[str1_len][str2_len];
}

int main() {
    char str1[MAX_STR_LEN], str2[MAX_STR_LEN];

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}