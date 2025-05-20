//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int min(int a, int b, int c) {

    if (a <= b && a <= c)
        return a;

    if (b <= a && b <= c)
        return b;

    return c;
}

int levenshtein_distance(char *str1, char *str2, int len1, int len2) {

    int matrix[MAX_LEN][MAX_LEN];

    for (int i = 0; i <= len1; i++)
        matrix[0][i] = i;

    for (int j = 0; j <= len2; j++)
        matrix[j][0] = j;

    for (int j = 1; j <= len2; j++) {

        for (int i = 1; i <= len1; i++) {

            if (str1[i-1] == str2[j-1]) {
                matrix[j][i] = matrix[j-1][i-1];
            } else {
                matrix[j][i] = min(matrix[j-1][i], matrix[j][i-1], matrix[j-1][i-1]) + 1;
            }
        }
    }

    return matrix[len2][len1];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    printf("Levenshtein distance between %s and %s is %d\n", str1, str2, levenshtein_distance(str1, str2, len1, len2));

    return 0;
}