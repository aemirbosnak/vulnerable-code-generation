//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 100
#define SUMMARY_LENGTH 50

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} Text;

void add_sentence(Text *text, const char *sentence) {
    if (text->num_sentences >= MAX_SENTENCES) {
        printf("Error: too many sentences.\n");
        exit(1);
    }
    strncpy(text->sentences[text->num_sentences].sentence, sentence, MAX_SENTENCE_LENGTH);
    text->sentences[text->num_sentences].length = strlen(sentence);
    text->num_sentences++;
}

int sentence_compare(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void summarize(Text *text, char *summary, int max_length) {
    qsort(text->sentences, text->num_sentences, sizeof(Sentence), sentence_compare);
    int summary_length = 0;
    bool first_sentence = true;
    for (int i = 0; i < text->num_sentences; i++) {
        if (summary_length >= max_length ||!text->sentences[i].length) {
            break;
        }
        if (first_sentence) {
            strcpy(summary, text->sentences[i].sentence);
            first_sentence = false;
        } else {
            strcat(summary, " ");
            strcat(summary, text->sentences[i].sentence);
        }
        summary_length += strlen(text->sentences[i].sentence) + 1;
    }
    summary[summary_length - 1] = '\0';
}

int main() {
    Text text;
    char input[MAX_SENTENCE_LENGTH];
    printf("Enter text to summarize:\n");
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)) {
        input[strcspn(input, "\n")] = '\0';
        add_sentence(&text, input);
    }
    char summary[SUMMARY_LENGTH];
    summarize(&text, summary, SUMMARY_LENGTH);
    printf("Summary:\n%s\n", summary);
    return 0;
}