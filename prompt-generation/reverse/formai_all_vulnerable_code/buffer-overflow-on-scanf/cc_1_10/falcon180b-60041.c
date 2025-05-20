//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == 0) {
        return len2;
    } else if (len2 == 0) {
        return len1;
    }

    int **matrix = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }
    }

    int distance = matrix[len1][len2];

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            if (matrix[i][j] + 1 == distance) {
                if (str1[i] == str2[j]) {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
        }
        printf("\n");
    }

    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return distance;
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}