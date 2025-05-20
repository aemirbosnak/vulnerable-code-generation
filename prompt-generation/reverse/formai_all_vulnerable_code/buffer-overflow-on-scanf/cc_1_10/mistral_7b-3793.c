//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void whoa_levenshtein(char *str1, char *str2, int *distance) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 > MAX_LENGTH || len2 > MAX_LENGTH) {
        printf("Whoa! Strings too long for this calculator!\n");
        exit(EXIT_FAILURE);
    }

    int matrix[len1 + 1][len2 + 1];

    // Initialize matrix with distances for empty strings
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
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }

            if (matrix[i][j] > 10 && i != 0 && j != 0) {
                printf("Whoa! Distance between '%s' and '%s' is surprisingly high!\n", str1, str2);
                printf("Distance: %d\n", matrix[i][j]);
                exit(EXIT_FAILURE);
            }
        }
    }

    *distance = matrix[len1][len2];
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    int distance;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    whoa_levenshtein(str1, str2, &distance);

    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    return EXIT_SUCCESS;
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}