//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == 0) {
        return len2;
    } else if (len2 == 0) {
        return len1;
    }

    int** table = (int**)malloc(sizeof(int*) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        table[i] = (int*)malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j <= len2; j++) {
            table[i][j] = 0;
        }
    }

    for (int i = 0; i <= len1; i++) {
        table[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        table[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            } else {
                table[i][j] = table[i - 1][j] + 1;
                table[i][j] = table[i][j - 1] + 1;
                table[i][j] = table[i - 1][j - 1] + 1;
            }
        }
    }

    int distance = table[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(table[i]);
    }
    free(table);

    return distance;
}

int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}