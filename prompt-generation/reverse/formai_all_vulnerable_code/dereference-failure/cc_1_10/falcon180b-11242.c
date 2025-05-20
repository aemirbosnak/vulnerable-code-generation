//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_LENGTH 100000

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int min(int a, int b, int c) {
    return (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
}

int get_distance(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **matrix = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (len2 + 1));
        for (int j = 0; j <= len2; j++) {
            matrix[i][j] = 0;
        }
    }
    int distance = 0;
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (tolower(str1[i - 1]) == tolower(str2[j - 1])) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
            distance = matrix[i][j];
        }
    }
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return distance;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    int distance = get_distance(str1, str2);
    printf("Levenshtein distance between \"%s\" and \"%s\": %d\n", str1, str2, distance);
    return 0;
}