//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c);

int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    int **arr = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        arr[i] = (int *)malloc((len2 + 1) * sizeof(int));
        arr[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        arr[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1];
            } else {
                arr[i][j] = 1 + min(arr[i - 1][j - 1], arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    int distance = arr[len1][len2];

    for(int i = 0; i <= len1; i++) {
        free(arr[i]);
    }
    free(arr);

    return distance;
}

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main() {
    char word1[50], word2[50];
    printf("Enter the first word: ");
    scanf("%s", word1);
    printf("Enter the second word: ");
    scanf("%s", word2);
    int distance = levenshtein_distance(word1, word2);
    printf("The Levenshtein distance between %s and %s is %d.\n", word1, word2, distance);
    return 0;
}