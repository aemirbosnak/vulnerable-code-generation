//FormAI DATASET v1.0 Category: Text Summarizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 10
#define MAX_SENTENCE_LENGTH 100
#define SUMMARY_LENGTH 50

int main() {
    char article[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    char summary[SUMMARY_LENGTH];

    printf("Enter the article:\n");

    // Read in the article
    int sentence_count = 0;
    while (sentence_count < MAX_SENTENCES && fgets(article[sentence_count], MAX_SENTENCE_LENGTH, stdin)) {
        // Remove newline character from the end of the sentence
        article[sentence_count][strlen(article[sentence_count])-1] = '\0';

        sentence_count++;
    }

    // Create the summary
    int summary_length = 0;
    int sentence_index = 0;
    while (summary_length < SUMMARY_LENGTH && sentence_index < sentence_count) {
        char* sentence = article[sentence_index];

        // Remove punctuation marks from the sentence
        int sentence_length = strlen(sentence);
        for (int i = 0; i < sentence_length; i++) {
            if (!isalpha(sentence[i])) {
                sentence[i] = ' ';
            }
        }

        // Count the number of words in the sentence
        int word_count = 0;
        char* token = strtok(sentence, " ");
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " ");
        }

        // Add the sentence to the summary if its word count is below a certain threshold
        if (word_count <= 5) {
            strcat(summary, article[sentence_index]);
            strcat(summary, " ");
            summary_length += sentence_length + 1;
        }

        sentence_index++;
    }

    printf("Summary: %s\n", summary);

    return 0;
}