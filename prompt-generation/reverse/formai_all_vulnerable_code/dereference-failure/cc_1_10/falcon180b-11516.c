//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1024

typedef struct {
    char *str;
    int len;
} String;

int min(int a, int b) {
    return a < b? a : b;
}

void create_matrix(String *str1, String *str2, int **matrix) {
    int i, j;
    for (i = 0; i <= str1->len; i++) {
        matrix[i][0] = i;
    }
    for (j = 0; j <= str2->len; j++) {
        matrix[0][j] = j;
    }
    for (i = 1; i <= str1->len; i++) {
        for (j = 1; j <= str2->len; j++) {
            if (str1->str[i-1] == str2->str[j-1]) {
                matrix[i][j] = matrix[i-1][j-1];
            } else {
                matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1]) + 1;
            }
        }
    }
}

int get_distance(String *str1, String *str2, int **matrix) {
    return matrix[str1->len][str2->len];
}

void main() {
    char input1[MAX_LENGTH] = {0};
    char input2[MAX_LENGTH] = {0};

    printf("Enter first string: ");
    fgets(input1, MAX_LENGTH, stdin);
    printf("Enter second string: ");
    fgets(input2, MAX_LENGTH, stdin);

    int len1 = strlen(input1);
    int len2 = strlen(input2);

    String str1 = {input1, len1};
    String str2 = {input2, len2};

    int **matrix = malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = malloc(sizeof(int) * (len2 + 1));
    }

    create_matrix(&str1, &str2, matrix);

    int distance = get_distance(&str1, &str2, matrix);

    printf("Levenshtein distance: %d\n", distance);

    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
}