//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

int levenshtein_distance(const char *str1, const char *str2, int len1, int len2) {
    int matrix[MAX_LENGTH + 1][MAX_LENGTH + 1];

    bool is_first_string = true;

    for (int i = 0; i <= len1; ++i) {
        matrix[i][0] = i;
    }

    for (int j = 0; j <= len2; ++j) {
        matrix[0][j] = j;
    }

    for (int i = 1; i <= len1; ++i) {
        int *current_row = matrix[i];
        char current_char1 = str1[i - 1];
        for (int j = 1; j <= len2; ++j) {
            char current_char2 = str2[j - 1];
            int cost = (current_char1 == current_char2) ? 0 : 1;

            int replacement_cost = current_row[j] + cost;
            int delete_cost = current_row[j] + 1;
            int insert_cost = current_row[j - 1] + 1;

            current_row[j] = fmin(fmin(replacement_cost, delete_cost), insert_cost);
        }
    }

    return matrix[len1][len2];
}

int main() {
    char str1[MAX_LENGTH] = "kitten";
    char str2[MAX_LENGTH] = "sitting";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein Distance: %d\n", distance);

    return EXIT_SUCCESS;
}