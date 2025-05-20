//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORDS_IN_SENTENCE 100
#define MAX_SUMMARY_LENGTH 500

typedef struct {
    char *sentence;
    int frequency;
} Sentence;

int compare_sentences(const void *a, const void *b) {
    Sentence *sentence_a = (Sentence *) a;
    Sentence *sentence_b = (Sentence *) b;

    return sentence_b->frequency - sentence_a->frequency;
}

void generate_summary(char *text, int num_sentences) {
    char *sentences[MAX_SENTENCE_LENGTH];
    int num_sentences_found = 0;
    int sentence_length = 0;
    char *summary = malloc(MAX_SUMMARY_LENGTH * sizeof(char));
    summary[0] = '\0';

    char *token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        if (sentence_length >= MAX_SENTENCE_LENGTH) {
            break;
        }

        if (isalpha(token[0])) {
            strcat(sentences[num_sentences_found], token);
            strcat(sentences[num_sentences_found], " ");
            sentence_length++;
        }

        token = strtok(NULL, ",.?!;:");
    }

    if (sentence_length > 0) {
        sentences[num_sentences_found][sentence_length - 1] = '\0';
        num_sentences_found++;
    }

    qsort(sentences, num_sentences_found, sizeof(char *), compare_sentences);

    for (int i = 0; i < num_sentences && i < num_sentences_found; i++) {
        strcat(summary, sentences[i]);
        strcat(summary, " ");
    }

    if (num_sentences_found < num_sentences) {
        strcat(summary, "...");
    }

    printf("Summary: %s\n", summary);
    free(summary);
}

int main() {
    char text[MAX_SUMMARY_LENGTH];

    printf("Enter the text to be summarized: ");
    fgets(text, MAX_SUMMARY_LENGTH, stdin);

    generate_summary(text, 5);

    return 0;
}