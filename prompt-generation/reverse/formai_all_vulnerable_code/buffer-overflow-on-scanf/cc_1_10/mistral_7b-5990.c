//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

int levenshtein_distance(const char *str1, const char *str2, int length1, int length2) {
    int matrix[length1 + 1][length2 + 1];

    for (int i = 0; i <= length1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= length2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= length1; i++) {
        for (int j = 1; j <= length2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }

    return matrix[length1][length2];
}

int main() {
    char string1[MAX_LENGTH];
    char string2[MAX_LENGTH];

    printf("Enter first string: ");
    scanf("%s", string1);

    printf("Enter second string: ");
    scanf("%s", string2);

    int length1 = strlen(string1);
    int length2 = strlen(string2);

    int distance = levenshtein_distance(string1, string2, length1, length2);

    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}