//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000

struct sentence {
    char text[MAX_SENTENCE_LENGTH];
    int length;
};

struct summary {
    int num_sentences;
    struct sentence *sentences;
};

struct summary *create_summary(char *input_text) {
    struct summary *summary = malloc(sizeof(struct summary));
    summary->num_sentences = 0;
    summary->sentences = NULL;

    char *sentence_start = input_text;
    char *sentence_end = strtok(input_text, ".");
    while (sentence_end!= NULL) {
        struct sentence *new_sentence = malloc(sizeof(struct sentence));
        strncpy(new_sentence->text, sentence_start, sentence_end - sentence_start);
        new_sentence->length = sentence_end - sentence_start;
        summary->sentences = realloc(summary->sentences, sizeof(struct sentence) * (summary->num_sentences + 1));
        summary->sentences[summary->num_sentences++] = *new_sentence;

        sentence_start = sentence_end + 1;
        sentence_end = strtok(sentence_start, ".");
    }

    return summary;
}

void print_summary(struct summary *summary) {
    for (int i = 0; i < summary->num_sentences; i++) {
        printf("%s\n", summary->sentences[i].text);
    }
}

int main() {
    char input_text[MAX_SENTENCE_LENGTH];

    printf("Enter a text to summarize: ");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);

    struct summary *summary = create_summary(input_text);
    print_summary(summary);

    free(summary->sentences);
    free(summary);

    return 0;
}