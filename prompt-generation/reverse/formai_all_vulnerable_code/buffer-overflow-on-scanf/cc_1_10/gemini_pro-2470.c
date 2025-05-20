//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct {
    int cost;
    int prev_i;
    int prev_j;
} cell_t;

int min3(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshtein_distance(const char *s1, const char *s2) {
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);

    // Create the matrix to store the Levenshtein distance
    cell_t *matrix = malloc(sizeof(cell_t) * (s1_len + 1) * (s2_len + 1));
    if (matrix == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for the Levenshtein distance matrix.\n");
        return -1;
    }

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= s1_len; i++) {
        matrix[i * (s2_len + 1)].cost = i;
        matrix[i * (s2_len + 1)].prev_i = -1;
        matrix[i * (s2_len + 1)].prev_j = -1;
    }
    for (int j = 0; j <= s2_len; j++) {
        matrix[j].cost = j;
        matrix[j].prev_i = -1;
        matrix[j].prev_j = -1;
    }

    // Populate the rest of the matrix
    for (int i = 1; i <= s1_len; i++) {
        for (int j = 1; j <= s2_len; j++) {
            int cost_deletion = matrix[(i - 1) * (s2_len + 1) + j].cost + 1;
            int cost_insertion = matrix[i * (s2_len + 1) + (j - 1)].cost + 1;
            int cost_substitution = matrix[(i - 1) * (s2_len + 1) + (j - 1)].cost + (s1[i - 1] != s2[j - 1]);
            int cost = min3(cost_deletion, cost_insertion, cost_substitution);
            matrix[i * (s2_len + 1) + j].cost = cost;
            matrix[i * (s2_len + 1) + j].prev_i = s1[i - 1] != s2[j - 1] ? i - 1 : matrix[(i - 1) * (s2_len + 1) + (j - 1)].prev_i;
            matrix[i * (s2_len + 1) + j].prev_j = s1[i - 1] != s2[j - 1] ? j - 1 : matrix[(i - 1) * (s2_len + 1) + (j - 1)].prev_j;
        }
    }

    // Return the Levenshtein distance
    int distance = matrix[s1_len * (s2_len + 1) + s2_len].cost;

    // Free the memory allocated for the matrix
    free(matrix);

    return distance;
}

int main() {
    char s1[MAX_STR_LEN];
    char s2[MAX_STR_LEN];

    printf("Enter the first string: ");
    scanf("%s", s1);

    printf("Enter the second string: ");
    scanf("%s", s2);

    int distance = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);

    return 0;
}