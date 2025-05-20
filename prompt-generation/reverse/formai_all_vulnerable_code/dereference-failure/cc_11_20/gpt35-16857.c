//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Ada Lovelace
// Ada Lovelace Style Unique C Text Summarizer Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LEN 1000
#define MAX_SUMMARY_LEN 100

int main() {
    char input_string[MAX_STRING_LEN];
    char summary[MAX_SUMMARY_LEN];
    int i, j;

    printf("Enter the input string: ");
    fgets(input_string, MAX_STRING_LEN, stdin);

    // Count number of sentences
    int sentence_count = 0;
    for (i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == '.') {
            sentence_count++;
        }
    }

    // Allocate memory for the sentences
    char *sentences[sentence_count];
    for (i = 0; i < sentence_count; i++) {
        sentences[i] = (char *)malloc(MAX_STRING_LEN);
        memset(sentences[i], 0, MAX_STRING_LEN);
    }

    // Store the sentences
    int sentence_index = 0;
    int start_index = 0;
    for (i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == '.') {
            strncpy(sentences[sentence_index++], input_string + start_index, i - start_index + 1);
            start_index = i + 1;
        }
    }

    // Calculate the score for each sentence
    float sentence_score[sentence_count];
    memset(sentence_score, 0, sentence_count * sizeof(float));
    for (i = 0; i < sentence_count; i++) {
        for (j = 0; j < sentence_count; j++) {
            if (i != j) {
                char *temp_sentence = (char *)malloc(MAX_STRING_LEN);
                strcpy(temp_sentence, sentences[i]);
                char *token = strtok(temp_sentence, " ");
                int common_word_count = 0;
                int total_word_count = 0;
                while (token != NULL) {
                    if (strstr(sentences[j], token) != NULL) {
                        common_word_count++;
                    }
                    total_word_count++;
                    token = strtok(NULL, " ");
                }
                free(temp_sentence);
                sentence_score[i] += (float)common_word_count / (float)total_word_count;
            }
        }
    }

    // Calculate the threshold score
    float threshold_score = 0;
    for (i = 0; i < sentence_count; i++) {
        threshold_score += sentence_score[i];
    }
    threshold_score /= sentence_count;

    // Generate the summary
    int summary_index = 0;
    for (i = 0; i < sentence_count; i++) {
        if (sentence_score[i] >= threshold_score && summary_index + strlen(sentences[i]) <= MAX_SUMMARY_LEN) {
            strncpy(summary + summary_index, sentences[i], strlen(sentences[i]));
            summary_index += strlen(sentences[i]);
        }
    }

    printf("Summary: %s\n", summary);

    // Free the memory
    for (i = 0; i < sentence_count; i++) {
        free(sentences[i]);
    }

    return 0;
}