//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 10000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char *text;
    int length;
} Sentence;

Sentence sentences[MAX_SENTENCES];
int num_sentences = 0;

void add_sentence(char *text) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }

    int length = strlen(text);
    if (length < MIN_SENTENCE_LENGTH) {
        printf("Warning: Sentence is too short (%d characters).\n", length);
        return;
    }

    sentences[num_sentences].text = malloc(length + 1);
    strcpy(sentences[num_sentences].text, text);
    sentences[num_sentences].length = length;

    num_sentences++;
}

void print_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        printf("%s (%d characters)\n", sentences[i].text, sentences[i].length);
    }
}

void free_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i].text);
    }
}

int main() {
    char input[MAX_SENTENCE_LENGTH];

    printf("Enter sentences (type 'done' when finished):\n");

    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)) {
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "done") == 0) {
            break;
        }

        add_sentence(input);
    }

    print_sentences();

    free_sentences();

    return 0;
}