//Falcon-180B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int levenshtein_distance(char *str1, char *str2, int len1, int len2) {
    int i, j;
    int matrix[MAX_LENGTH][MAX_LENGTH];
    int min_distance = len1;
    int current_distance;

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] = matrix[i - 1][j] + 1;
            }

            current_distance = matrix[i][j];

            if (current_distance < min_distance) {
                min_distance = current_distance;
            }
        }
    }

    return min_distance;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("The Levenshtein distance between the two strings is %d\n", distance);

    return 0;
}