#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) matrix[i][0] = i;
    for (int j = 0; j <= len2; j++) matrix[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) matrix[i][j] = matrix[i - 1][j - 1];
            else matrix[i][j] = 1 + min(matrix[i - 1][j], min(matrix[i][j - 1], matrix[i - 1][j - 1]));
        }
    }

    return matrix[len1][len2];
}

int main() {
    char input1[10];
    char input2[10];

    printf("Enter first string: ");
    gets(input1);
    printf("Enter second string: ");
    gets(input2);

    printf("Levenshtein distance: %d\n", levenshtein_distance(input1, input2));

    return 0;
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}
