//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    char *text;
    int length;
    int frequency;
} Word;

Sentence sentences[MAX_SENTENCES];
Word words[MAX_WORDS];

int num_sentences = 0;
int num_words = 0;

void add_sentence(char *text) {
    if (num_sentences >= MAX_SENTENCES) {
        printf("Error: maximum number of sentences reached.\n");
        return;
    }

    sentences[num_sentences].text = strdup(text);
    sentences[num_sentences].length = strlen(text);

    num_sentences++;
}

void add_word(char *text) {
    if (num_words >= MAX_WORDS) {
        printf("Error: maximum number of words reached.\n");
        return;
    }

    Word *word = &words[num_words];
    word->text = strdup(text);
    word->length = strlen(text);
    word->frequency = 1;

    num_words++;
}

void print_sentences() {
    for (int i = 0; i < num_sentences; i++) {
        printf("%s\n", sentences[i].text);
    }
}

void print_words() {
    for (int i = 0; i < num_words; i++) {
        printf("%s (%d)\n", words[i].text, words[i].frequency);
    }
}

int main() {
    char text[MAX_SENTENCE_LENGTH];
    char word[MAX_WORD_LENGTH];

    printf("Enter text to summarize:\n");
    fgets(text, MAX_SENTENCE_LENGTH, stdin);

    char *p = strtok(text, " ");
    while (p!= NULL) {
        add_word(p);
        p = strtok(NULL, " ");
    }

    printf("Original text:\n");
    print_sentences();

    printf("Summary:\n");
    for (int i = 0; i < num_words; i++) {
        if (words[i].frequency > 1) {
            printf("%s (%d)\n", words[i].text, words[i].frequency);
        }
    }

    return 0;
}