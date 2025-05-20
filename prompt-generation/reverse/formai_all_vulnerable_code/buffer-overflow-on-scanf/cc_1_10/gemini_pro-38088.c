//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein_distance(const char *s1, const char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);

    int matrix[s1_len + 1][s2_len + 1];

    for (int i = 0; i <= s1_len; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= s2_len; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            int cost = s1[i - 1] == s2[j - 1] ? 0 : 1;
            matrix[i][j] = min(
                matrix[i - 1][j] + 1,  // Deletion
                matrix[i][j - 1] + 1,  // Insertion
                matrix[i - 1][j - 1] + cost  // Substitution
            );
        }
    }

    return matrix[s1_len][s2_len];
}

int main() {
    char s1[MAX_STR_LEN], s2[MAX_STR_LEN];

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);

    return 0;
}