//FormAI DATASET v1.0 Category: Text Summarizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 10000
#define MAX_SUMMARY_SIZE 200

int main() {
    char input[MAX_INPUT_SIZE];
    char summary[MAX_SUMMARY_SIZE];
    int input_length, summary_length, i;

    printf("Enter the text you want to summarize: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove trailing newline from input
    input_length = strlen(input);
    if (input[input_length - 1] == '\n') {
        input[input_length - 1] = '\0';
        input_length--;
    }

    // Convert input to lowercase
    for (i = 0; i < input_length; i++) {
        input[i] = tolower(input[i]);
    }

    // Initialize summary to empty string
    summary[0] = '\0';

    // Split input by whitespace
    char *word = strtok(input, " ");
    while (word != NULL) {
        // Ignore words that are too short or too common
        if (strlen(word) > 3 && strcmp(word, "the") != 0 && strcmp(word, "and") != 0 && strcmp(word, "but") != 0) {
            // Add word to summary
            strcat(summary, word);
            strcat(summary, " ");

            // Exit loop if summary has reached desired length
            summary_length = strlen(summary);
            if (summary_length >= MAX_SUMMARY_SIZE) {
                break;
            }
        }

        // Get next word
        word = strtok(NULL, " ");
    }

    // Print summarized text
    printf("Summary: %s\n", summary);

    return 0;
}