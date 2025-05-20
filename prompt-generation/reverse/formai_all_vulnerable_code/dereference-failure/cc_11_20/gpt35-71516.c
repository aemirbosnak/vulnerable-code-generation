//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *summarize(char*);

int main() {
    printf("Enter a paragraph to summarize:\n");
    char input[10000];
    fgets(input, 10000, stdin);

    char *summary = summarize(input);

    printf("Summary: %s\n", summary);
    free(summary);

    return 0;
}

char *summarize(char *input) {
    // Count the number of sentences
    int sentence_count = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentence_count += 1;
        }
    }
    
    // Split the input into an array of sentences
    char **sentence_array = malloc(sizeof(char*) * sentence_count);
    int sentence_index = 0;
    int start_index = 0;
    int end_index = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            end_index = i + 1;

            // Allocate space for the sentence and copy it over
            char *sentence = malloc(sizeof(char) * (end_index - start_index + 1));
            strncpy(sentence, input + start_index, end_index - start_index);
            sentence[end_index - start_index] = '\0';

            // Remove leading/trailing whitespace
            while (isspace(sentence[0])) {
                memmove(sentence, sentence + 1, strlen(sentence));
            }
            while (isspace(sentence[strlen(sentence) - 1])) {
                sentence[strlen(sentence) - 1] = '\0';
            }

            sentence_array[sentence_index] = sentence;
            sentence_index++;
            start_index = end_index;
        }
    }

    // Score the sentences based on word frequency
    int *scores = malloc(sizeof(int) * sentence_count);
    memset(scores, 0, sizeof(int) * sentence_count);

    char delims[] = " .,;:!?\n\t\"\'()[]{}<>";
    char *token = strtok(input, delims);
    while (token != NULL) {
        for (int i = 0; i < sentence_count; i++) {
            char *sentence = sentence_array[i];
            char *temp = malloc(sizeof(char) * (strlen(sentence) + 1));
            strcpy(temp, sentence);

            // Convert the sentence to lowercase for case-insensitive comparison
            for (int i = 0; i < strlen(temp); i++) {
                temp[i] = tolower(temp[i]);
            }

            char *match = strstr(temp, token);
            if (match != NULL) {
                scores[i] += 1;
            }

            free(temp);
        }
        token = strtok(NULL, delims);
    }

    // Find the highest-scoring sentence
    int max_index = 0;
    for (int i = 1; i < sentence_count; i++) {
        if (scores[i] > scores[max_index]) {
            max_index = i;
        }
    }

    // Concatenate the high-scoring sentences into the summary
    char *summary = malloc(sizeof(char));
    summary[0] = '\0';
    for (int i = 0; i < sentence_count; i++) {
        if (i == max_index || scores[i] > 0.7 * scores[max_index]) {
            char *sentence = sentence_array[i];
            summary = realloc(summary, sizeof(char) * (strlen(summary) + strlen(sentence) + 3));
            strcat(summary, sentence);
            strcat(summary, ". ");
        }
    }

    // Remove leading/trailing whitespace
    while (isspace(summary[0])) {
        memmove(summary, summary + 1, strlen(summary));
    }
    while (isspace(summary[strlen(summary) - 1])) {
        summary[strlen(summary) - 1] = '\0';
    }

    // Free memory
    for (int i = 0; i < sentence_count; i++) {
        free(sentence_array[i]);
    }
    free(sentence_array);
    free(scores);

    return summary;
}