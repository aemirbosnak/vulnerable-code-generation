//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LEN 200

void summarize(char *input_text, char **output_summary, int num_sentences);

int main(void) {
    char input_text[1000];
    char *output_summary[MAX_SENTENCES];
    int num_sentences;

    printf("Enter the text to be summarized (max 1000 chars):\n");
    fgets(input_text, 1000, stdin);

    printf("Enter the number of sentences you want in the summary:\n");
    scanf("%d", &num_sentences);

    summarize(input_text, output_summary, num_sentences);

    printf("\nSummary:\n");
    for (int i = 0; i < num_sentences; i++) {
        printf("%s", output_summary[i]);
    }

    return 0;
}

void summarize(char *input_text, char **output_summary, int num_sentences) {
    char *sentences[MAX_SENTENCES];
    char *token, *last_token = NULL;
    int i = 0, sentence_count = 0;

    token = strtok(input_text, ".!?");
    while (token != NULL && i < MAX_SENTENCES) {
        sentences[i++] = token;
        token = strtok(NULL, ".!?");
    }
    sentence_count = i;

    int j = 0, k = 0;
    double sentence_scores[sentence_count];
    for (i = 0; i < sentence_count; i++) {
        token = strtok(sentences[i], " ");
        int word_count = 0, important_word_count = 0;
        while (token != NULL && word_count < MAX_SENTENCE_LEN) {
            int len = strlen(token);
            if (len > 1 && !isdigit(token[0]) && !ispunct(token[len - 1])) {
                important_word_count++;
            }
            word_count++;
            token = strtok(NULL, " ");
        }
        sentence_scores[i] = (double) important_word_count / (double) word_count;
    }

    for (i = 0; i < num_sentences; i++) {
        int max_index = -1;
        double max_score = -1;
        for (j = 0; j < sentence_count; j++) {
            if (sentence_scores[j] > max_score) {
                max_score = sentence_scores[j];
                max_index = j;
            }
        }

        sentence_scores[max_index] = -1;
        output_summary[k++] = sentences[max_index];
    }
}