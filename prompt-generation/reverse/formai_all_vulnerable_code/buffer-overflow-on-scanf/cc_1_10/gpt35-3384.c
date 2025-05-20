//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: portable
#include <stdio.h>
#include <string.h>

int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int matrix[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                matrix[i][j] = j;
            } else if (j == 0) {
                matrix[i][j] = i;
            } else if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                int a = matrix[i - 1][j - 1] + 1;
                int b = matrix[i][j - 1] + 1;
                int c = matrix[i - 1][j] + 1;
                matrix[i][j] = minimum(a, b, c);
            }
        }
    }
    return matrix[len1][len2];
}

int main() {
    char str1[256];
    char str2[256];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}