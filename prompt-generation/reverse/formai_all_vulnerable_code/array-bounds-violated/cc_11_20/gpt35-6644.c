//FormAI DATASET v1.0 Category: Text Summarizer ; Style: visionary
// Visionary C Text Summarizer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000 // Maximum length of input strings
#define MAX_SENTS 100 // Maximum number of sentences in the input

int main()
{
    char str[MAX_STR_LEN]; // Input string
    char sentences[MAX_SENTS][MAX_STR_LEN]; // Array to store extracted sentences
    int sent_count = 0; // Counter for number of sentences extracted
    int i, j; // Loop variables
    int sentence_starts[MAX_SENTS]; // Array to keep track of starting indexes of sentences
    int summary_sentence_indexes[MAX_SENTS]; // Array to hold indexes of important sentences
    int summary_sent_count = 0; // Counter for number of sentences in the summary

    // Get input text
    printf("Enter the text to be summarized:\n");
    fgets(str, MAX_STR_LEN, stdin);

    // Extract sentences from input text
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
            sentences[sent_count][j] = str[i];
            sentence_starts[sent_count] = i;
            sent_count++;
            j = 0;
        } else {
            sentences[sent_count][j] = str[i];
            j++;
        }
    }

    // Calculate scores for each sentence
    float sentence_scores[sent_count];
    for (i = 0; i < sent_count; i++) {
        char *looking_for = "important keyword";
        char *result = strstr(sentences[i], looking_for);
        if (result != NULL) {
            sentence_scores[i] = 1.0;
            summary_sentence_indexes[summary_sent_count] = i;
            summary_sent_count++;
            continue;
        }

        sentence_scores[i] = 0.0; // Initialize score to 0

        // Calculate score based on relevance of words
        char *relevant_words[] = {"relevant", "keywords"};
        int num_relevant_words = sizeof(relevant_words) / sizeof(relevant_words[0]);
        char *word = strtok(sentences[i], " ");
        while (word != NULL) {
            for (j = 0; j < num_relevant_words; j++) {
                if (strcmp(word, relevant_words[j]) == 0) {
                    sentence_scores[i] += 0.5 / num_relevant_words; // Add score for relevant word
                }
            }
            word = strtok(NULL, " ");
        }
    }

    // Bubble sort sentence scores & sentence starts arrays in descending order
    for (i = 0; i < sent_count-1; i++) {
        for (j = 0; j < sent_count-i-1; j++) {
            if (sentence_scores[j] < sentence_scores[j+1]) {
                float temp_score = sentence_scores[j];
                sentence_scores[j] = sentence_scores[j+1];
                sentence_scores[j+1] = temp_score;

                int temp_start = sentence_starts[j];
                sentence_starts[j] = sentence_starts[j+1];
                sentence_starts[j+1] = temp_start;
            }
        }
    }
    
    // Print summary of important sentences
    printf("\nSummary:\n");
    for (i = 0; i < summary_sent_count; i++) {
        printf("%.*s\n", sentence_starts[summary_sentence_indexes[i]+1] - sentence_starts[summary_sentence_indexes[i]] + 1, &str[sentence_starts[summary_sentence_indexes[i]]]);
    }
    for (i = 0; i < sent_count; i++) {
        if (sentence_scores[i] > 0.0 && summary_sent_count < 3) {
            printf("%.*s\n", sentence_starts[i+1] - sentence_starts[i] + 1, &str[sentence_starts[i]]);
            summary_sent_count++;
        }
    }
    
    return 0;
}