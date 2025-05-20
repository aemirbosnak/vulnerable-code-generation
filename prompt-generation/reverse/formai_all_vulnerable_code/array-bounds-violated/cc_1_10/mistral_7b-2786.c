//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void levenshtein_distance(char *str1, char *str2, int *dist) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0)
                matrix[i][j] = j;
            if (j == 0)
                matrix[i][j] = i;

            if (str1[i - 1] == str2[j - 1])
                matrix[i][j] = matrix[i - 1][j - 1];
            else
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
        }
    }

    *dist = matrix[len1][len2];
}

int main() {
    char word1[MAX_LENGTH], word2[MAX_LENGTH];
    int distance;

    printf("Enter the first word: ");
    scanf("%s", word1);

    printf("Enter the second word: ");
    scanf("%s", word2);

    levenshtein_distance(word1, word2, &distance);

    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", word1, word2, distance);

    return 0;
}

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}