//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LEN 200
#define SUMMARY_LEN 1000

int main() {
    char input_text[2000], sentence_list[MAX_SENTENCES][MAX_SENTENCE_LEN];
    int sentence_scores[MAX_SENTENCES] = {0}, num_sentences = 0, summary_length = 0, i, j, k;
    printf("Enter the text:\n");
    fgets(input_text, 2000, stdin);

    // Break input text into individual sentences and store in sentence_list
    for (i = 0; i < strlen(input_text); i++) {
        if (input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!') {
            sentence_list[num_sentences][k++] = input_text[i];
            num_sentences++;
            k = 0;
        } else {
            sentence_list[num_sentences][k++] = input_text[i];
        }
    }
    // Calculate score for each sentence
    for (i = 0; i < num_sentences; i++) {
        for (j = 0; j < strlen(sentence_list[i]); j++) {
            if (sentence_list[i][j] == ' ' || sentence_list[i][j] == '\n') {
                continue;
            } else {
                sentence_scores[i]++;
            }
        }
    }
    // Print summary
    printf("\nSummary:\n");
    while (summary_length < SUMMARY_LEN) {
        // Find the sentence with the highest score
        int max_score = 0, max_index = 0;
        for (i = 0; i < num_sentences; i++) {
            if (sentence_scores[i] > max_score) {
                max_score = sentence_scores[i];
                max_index = i;
            }
        }
        // Print the sentence and add its score to the summary_length
        printf("%s ", sentence_list[max_index]);
        summary_length += strlen(sentence_list[max_index]);
        // Set the score for the used sentence to 0 so it doesn't get selected again
        sentence_scores[max_index] = 0;
    }
    return 0;
}