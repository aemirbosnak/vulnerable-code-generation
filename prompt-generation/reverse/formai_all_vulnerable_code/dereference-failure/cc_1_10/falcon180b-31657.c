//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MAX_WORDS 1000

typedef struct sentence {
    char text[MAX_SENTENCE_LENGTH];
    int length;
} sentence;

typedef struct summary {
    sentence sentences[MAX_SENTENCES];
    int num_sentences;
} summary;

void tokenize(char* text, char** tokens) {
    int i = 0;
    char* token = strtok(text, ",.?!;:");
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, ",.?!;:");
    }
}

int compare_sentences(const void* a, const void* b) {
    sentence* sentence_a = (sentence*)a;
    sentence* sentence_b = (sentence*)b;

    return strcmp(sentence_a->text, sentence_b->text);
}

void generate_summary(summary* summary, int num_sentences) {
    qsort(summary->sentences, num_sentences, sizeof(sentence), compare_sentences);

    printf("Summary:\n");
    for (int i = 0; i < num_sentences && i < 3; i++) {
        printf("%s\n", summary->sentences[i].text);
    }
}

int main() {
    char input_text[MAX_SENTENCE_LENGTH];
    printf("Enter some text:\n");
    fgets(input_text, MAX_SENTENCE_LENGTH, stdin);

    char* tokens[MAX_WORDS];
    tokenize(input_text, tokens);

    summary summary = {0};
    int num_sentences = 0;

    for (int i = 0; i < MAX_SENTENCES && num_sentences < 10; i++) {
        if (strlen(tokens[i]) > 0) {
            strcpy(summary.sentences[num_sentences].text, tokens[i]);
            summary.sentences[num_sentences].length = strlen(tokens[i]);
            num_sentences++;
        }
    }

    generate_summary(&summary, num_sentences);

    return 0;
}