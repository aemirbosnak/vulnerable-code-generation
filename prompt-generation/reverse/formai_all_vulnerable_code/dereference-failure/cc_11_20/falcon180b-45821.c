//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char *input = (char*)malloc(MAX_SIZE * sizeof(char));
    int i = 0, j = 0;
    int len = 0;
    int index = 0;
    int score = 0;

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    len = strlen(input);

    // Remove leading and trailing spaces
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[len - 1])) {
        len--;
    }
    input[len] = '\0';

    // Create a table to store the lengths of common suffixes
    int *suffix_lengths = (int*)malloc((len + 1) * sizeof(int));
    for (i = 0; i <= len; i++) {
        suffix_lengths[i] = 0;
    }

    // Calculate the lengths of common suffixes
    for (i = len - 1; i >= 0; i--) {
        while (j > 0 && input[i]!= input[j - 1]) {
            j = suffix_lengths[j - 1];
        }
        if (input[i] == input[j - 1]) {
            j++;
        }
        suffix_lengths[i] = j;
    }

    // Calculate the score
    for (i = 0; i <= len; i++) {
        if (suffix_lengths[i] > score) {
            index = i;
            score = suffix_lengths[i];
        }
    }

    // Print the longest common suffix
    printf("Longest common suffix: ");
    for (i = len - score; i <= len - 1; i++) {
        printf("%c", input[i]);
    }
    printf("\n");

    free(input);
    free(suffix_lengths);

    return 0;
}