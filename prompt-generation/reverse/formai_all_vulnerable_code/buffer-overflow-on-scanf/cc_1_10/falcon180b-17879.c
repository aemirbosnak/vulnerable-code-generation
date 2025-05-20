//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int levenshtein_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j, k, cost;
    int **matrix;
    int max_size = (len1 > len2)? len1 : len2;
    int size = (len1 > len2)? len2 : len1;
    int *prev_row = (int *) malloc(sizeof(int) * size);
    int *curr_row = (int *) malloc(sizeof(int) * size);

    matrix = (int **) malloc(sizeof(int *) * max_size);
    for (i = 0; i < max_size; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * max_size);
    }

    for (i = 0; i < size; i++) {
        prev_row[i] = i;
        curr_row[i] = i;
        matrix[i][i] = i;
    }

    for (i = 1; i < max_size; i++) {
        for (j = 0; j < size; j++) {
            cost = (str1[j] == str2[j])? 0 : 1;
            matrix[i][j] = (j > 0)? matrix[i][j - 1] + cost : cost;
            curr_row[j] = (j > 0)? curr_row[j - 1] + cost : cost;
        }
        for (j = 0; j < size; j++) {
            prev_row[j] = curr_row[j];
            curr_row[j] = matrix[i][j];
        }
    }

    free(prev_row);
    free(curr_row);
    for (i = 0; i < max_size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return curr_row[size - 1];
}

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("Levenshtein distance between '%s' and '%s': %d\n", str1, str2, distance);

    return 0;
}