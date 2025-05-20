//FormAI DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 200
#define MAX_SUMMARY_LENGTH 1000

void summarize(char *article, char *summary);

int main() {
    char article[MAX_SENTENCES * MAX_SENTENCE_LENGTH];
    char summary[MAX_SUMMARY_LENGTH];

    // Get article input from user
    printf("Enter article:\n");
    fgets(article, sizeof(article), stdin);

    // Summarize article
    summarize(article, summary);

    // Print summary
    printf("\nSummary:\n%s\n", summary);

    return 0;
}

void summarize(char *article, char *summary) {
    int i, j, sentence_count;
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];

    // Divide article into sentences
    char *token = strtok(article, ".");
    while (token != NULL && sentence_count < MAX_SENTENCES) {
        strcpy(sentences[sentence_count++], token);
        token = strtok(NULL, ".");
    }

    // Remove leading/trailing whitespaces from each sentence
    for (i = 0; i < sentence_count; i++) {
        j = 0;
        while (isspace(sentences[i][j])) j++;
        memmove(sentences[i], &sentences[i][j], strlen(sentences[i]) - j + 1);

        j = strlen(sentences[i]) - 1;
        while (isspace(sentences[i][j])) j--;
        sentences[i][j + 1] = '\0';
    }

    // Calculate score of each sentence based on number of keywords present
    int sentence_scores[MAX_SENTENCES] = {0};
    char *keywords[] = {"the", "of", "and", "in", "to", "that", "a", "for", "with", "on", "was", "as", "by", "an", "be", "at", "which", "this", "from", "has", "but", "were", "or", "not", "one"};

    for (i = 0; i < sentence_count; i++) {
        char *word = strtok(sentences[i], " ");
        while (word != NULL) {
            for (j = 0; j < sizeof(keywords) / sizeof(keywords[0]); j++) {
                if (strcasecmp(word, keywords[j]) == 0) {
                    sentence_scores[i]++;
                    break;
                }
            }
            word = strtok(NULL, " ");
        }
    }

    // Select top 3 scoring sentences for summary
    int summary_sentence_indices[3] = {-1, -1, -1};
    for (i = 0; i < 3; i++) {
        int max_score = -1;
        for (j = 0; j < sentence_count; j++) {
            if (sentence_scores[j] > max_score) {
                int k;
                for (k = 0; k < i; k++) {
                    if (summary_sentence_indices[k] == j)
                        break;
                }
                if (k == i) {
                    max_score = sentence_scores[j];
                    summary_sentence_indices[i] = j;
                }
            }
        }
    }

    // Build summary from selected sentences
    summary[0] = '\0';
    for (i = 0; i < 3; i++) {
        if (summary_sentence_indices[i] >= 0)
            strcat(summary, sentences[summary_sentence_indices[i]]);
        if (i < 2)
            strcat(summary, ". ");
    }
}