//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int levenshtein_distance(char *str1, char *str2, int length1, int length2) {
    int matrix[length1 + 1][length2 + 1];
    int i, j, cost, min;

    for (i = 0; i <= length1; i++) {
        for (j = 0; j <= length2; j++) {
            if (i == 0)
                matrix[i][j] = j;

            if (j == 0)
                matrix[i][j] = i;

            if (str1[i - 1] == str2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                cost = 1;
                if (str1[i - 1] == str2[j])
                    cost = 0;

                min = matrix[i - 1][j] < matrix[i][j - 1] ? matrix[i - 1][j] : matrix[i][j - 1];
                matrix[i][j] = min + cost;
            }
        }
    }

    return matrix[length1][length2];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    int length1, length2;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    length1 = strlen(str1);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';
    length2 = strlen(str2);

    printf("Levenshtein Distance: %d\n", levenshtein_distance(str1, str2, length1, length2));

    return 0;
}