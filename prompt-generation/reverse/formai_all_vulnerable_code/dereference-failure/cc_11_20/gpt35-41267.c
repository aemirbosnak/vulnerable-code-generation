//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Linus Torvalds
/* The Amazing Text Summarizer */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000

void print_summary(int sentences, char **summary);

int main() {
    char **sentences = malloc(MAX_SENTENCES * sizeof(char *));
    char buffer[1024], *token, *prev_token;
    int i=0, j=0, num_sentences=0, num_words=0;

    /* Read input into an array of sentences */
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (num_sentences >= MAX_SENTENCES) {
            fprintf(stderr, "Error: Maximum number of sentences reached!\n");
            exit(EXIT_FAILURE);
        }
        sentences[num_sentences] = strdup(buffer);
        num_sentences++;
    }

    /* Tokenize each sentence and count the number of words */
    for (i=0; i<num_sentences; i++) {
        token = strtok(sentences[i], " .!?\n");
        while (token != NULL) {
            num_words++;
            prev_token = token;
            token = strtok(NULL, " .!?\n");
        }
        /* Add period to last word if it was missing */
        if (isalpha(prev_token[0]) && strchr(".!?", prev_token[strlen(prev_token)-1]) == NULL) {
            prev_token[strlen(prev_token)] = '.';
            prev_token[strlen(prev_token)+1] = '\0';
        }
    }

    /* Allocate memory for an array of words and copy them from the input array */
    char **words = malloc(num_words * sizeof(char *));
    for (i=0; i<num_sentences; i++) {
        token = strtok(sentences[i], " .!?\n");
        while (token != NULL) {
            words[j] = strdup(token);
            j++;
            token = strtok(NULL, " .!?\n");
        }
    }

    /* Calculate frequency of each word */
    int *freq = calloc(num_words, sizeof(int));
    for (i=0; i<num_words; i++) {
        for (j=0; j<num_words; j++) {
            if (i == j) continue;
            if (strcmp(words[i], words[j]) == 0) freq[i]++;
        }
    }

    /* Create a list of unique words */
    char **uniq_words = malloc(num_words * sizeof(char *));
    int num_uniq_words = 0;
    for (i=0; i<num_words; i++) {
        int is_unique = 1;
        for (j=0; j<num_uniq_words; j++) {
            if (strcmp(words[i], uniq_words[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            uniq_words[num_uniq_words] = strdup(words[i]);
            num_uniq_words++;
        }
    }

    /* Calculate score of each sentence */
    int *score = calloc(num_sentences, sizeof(int));
    for (i=0; i<num_sentences; i++) {
        token = strtok(sentences[i], " .!?\n");
        while (token != NULL) {
            for (j=0; j<num_uniq_words; j++) {
                if (strcmp(token, uniq_words[j]) == 0) {
                    score[i] += freq[j];
                    break;
                }
            }
            token = strtok(NULL, " .!?\n");
        }
    }

    /* Sort sentences by score in descending order */
    int *sorted_indices = calloc(num_sentences, sizeof(int));
    for (i=0; i<num_sentences; i++) {
        sorted_indices[i] = i;
    }
    for (i=0; i<num_sentences-1; i++) {
        for (j=i+1; j<num_sentences; j++) {
            if (score[sorted_indices[i]] < score[sorted_indices[j]]) {
                int temp = sorted_indices[i];
                sorted_indices[i] = sorted_indices[j];
                sorted_indices[j] = temp;
            }
        }
    }

    /* Print summary */
    char **summary = malloc(3 * sizeof(char *));
    int num_summary = 0;
    for (i=0; i<3; i++) {
        if (sorted_indices[i] == -1) break;
        summary[i] = strdup(sentences[sorted_indices[i]]);
        num_summary++;
    }
    print_summary(num_summary, summary);

    /* Cleanup */
    for (i=0; i<num_sentences; i++) free(sentences[i]);
    for (i=0; i<num_words; i++) free(words[i]);
    for (i=0; i<num_uniq_words; i++) free(uniq_words[i]);
    for (i=0; i<num_summary; i++) free(summary[i]);
    free(sentences);
    free(words);
    free(uniq_words);
    free(freq);
    free(score);
    free(sorted_indices);
    free(summary);

    return 0;
}

void print_summary(int num_summary, char **summary) {
    printf("\nSummary:\n");
    for (int i=0; i<num_summary; i++) {
        printf("%s", summary[i]);
    }
}