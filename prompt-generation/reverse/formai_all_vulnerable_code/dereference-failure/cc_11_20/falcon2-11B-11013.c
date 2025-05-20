//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_WORDS 100

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        fprintf(stderr, "Could not open input file: %s\n", argv[1]);
        return 2;
    }

    // Allocate memory for the word list
    char **word_list = malloc(MAX_NUM_WORDS * sizeof(char *));
    int num_words = 0;

    // Read words from the input file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Tokenize the line into words
        char *word = strtok(line, " ");
        while (word!= NULL) {
            // Allocate memory for each word
            word_list[num_words] = malloc(strlen(word) + 1);
            strcpy(word_list[num_words++], word);
            word = strtok(NULL, " ");
        }
    }

    // Close the input file
    fclose(input);

    // Allocate memory for the word frequency map
    int **frequency_map = malloc(num_words * sizeof(int *));
    for (int i = 0; i < num_words; i++) {
        frequency_map[i] = malloc(MAX_NUM_WORDS * sizeof(int));
        memset(frequency_map[i], 0, MAX_NUM_WORDS * sizeof(int));
    }

    // Count the frequency of each word
    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < num_words; j++) {
            if (strcmp(word_list[i], word_list[j]) == 0) {
                frequency_map[i][j]++;
            }
        }
    }

    // Print the word frequency map
    for (int i = 0; i < num_words; i++) {
        printf("Word %d: ", i + 1);
        for (int j = 0; j < num_words; j++) {
            if (frequency_map[i][j] > 0) {
                printf("%s: %d\n", word_list[j], frequency_map[i][j]);
            }
        }
    }

    // Free memory
    for (int i = 0; i < num_words; i++) {
        free(word_list[i]);
    }
    free(word_list);
    for (int i = 0; i < num_words; i++) {
        free(frequency_map[i]);
    }
    free(frequency_map);

    // Close the input file
    fclose(input);

    return 0;
}