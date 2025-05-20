//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS_PER_SENTENCE 20

struct sentence {
    char words[MAX_SENTENCE_LENGTH];
    int length;
};

struct summary {
    int num_sentences;
    struct sentence sentences[MAX_SENTENCES];
};

void tokenize(char *sentence, char *delimiters, char *tokens[], int max_tokens) {
    char *token = strtok(sentence, delimiters);
    int i = 0;
    while (token!= NULL && i < max_tokens) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, delimiters);
    }
}

int compare_sentences(const void *a, const void *b) {
    struct sentence *sentence_a = (struct sentence *)a;
    struct sentence *sentence_b = (struct sentence *)b;
    return strcmp(sentence_a->words, sentence_b->words);
}

void generate_summary(char *text, struct summary *summary) {
    char *sentence = strtok(text, ".");
    int num_sentences = 0;
    while (sentence!= NULL) {
        if (num_sentences >= MAX_SENTENCES) {
            break;
        }
        struct sentence *new_sentence = (struct sentence *)malloc(sizeof(struct sentence));
        strncpy(new_sentence->words, sentence, MAX_SENTENCE_LENGTH);
        new_sentence->length = strlen(new_sentence->words);
        summary->sentences[num_sentences] = *new_sentence;
        num_sentences++;
        sentence = strtok(NULL, ".");
    }
    qsort(summary->sentences, num_sentences, sizeof(struct sentence), compare_sentences);
}

void print_summary(struct summary *summary) {
    printf("Summary:\n");
    for (int i = 0; i < summary->num_sentences; i++) {
        printf("%s\n", summary->sentences[i].words);
    }
}

int main() {
    char text[10000];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    struct summary summary;
    generate_summary(text, &summary);
    print_summary(&summary);
    return 0;
}