//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int levenshtein(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 == 0) {
        return len2;
    }
    if (len2 == 0) {
        return len1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];
    int i, j;
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    return matrix[len1][len2];
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s string1 string2\n", argv[0]);
        return 1;
    }

    char* s1 = argv[1];
    char* s2 = argv[2];

    int distance = levenshtein(s1, s2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", s1, s2, distance);

    return 0;
}