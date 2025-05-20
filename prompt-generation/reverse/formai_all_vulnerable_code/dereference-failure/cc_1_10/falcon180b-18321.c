//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 100
#define MAX_WORDS 100

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Text;

void init_sentence(Sentence *sentence) {
    sentence->text = NULL;
    sentence->length = 0;
}

void init_text(Text *text) {
    text->sentences = NULL;
    text->num_sentences = 0;
}

void add_sentence(Text *text, char *sentence_text) {
    Sentence *new_sentence = malloc(sizeof(Sentence));
    init_sentence(new_sentence);
    new_sentence->text = strdup(sentence_text);
    new_sentence->length = strlen(sentence_text);
    text->sentences = realloc(text->sentences, sizeof(Sentence) * (text->num_sentences + 1));
    text->sentences[text->num_sentences] = *new_sentence;
    text->num_sentences++;
}

void print_sentence(Sentence sentence) {
    printf("%s\n", sentence.text);
}

void print_text(Text text) {
    for (int i = 0; i < text.num_sentences; i++) {
        print_sentence(text.sentences[i]);
    }
}

void tokenize_sentence(Sentence *sentence) {
    char *token = strtok(sentence->text, ",.?!;:");
    while (token!= NULL) {
        printf("%s ", token);
        token = strtok(NULL, ",.?!;:");
    }
    printf("\n");
}

int main() {
    Text text;
    init_text(&text);

    add_sentence(&text, "The quick brown fox jumps over the lazy dog. The lazy dog is not pleased.");
    add_sentence(&text, "The quick brown fox is very quick and very brown.");

    print_text(text);

    tokenize_sentence(&text.sentences[0]);
    tokenize_sentence(&text.sentences[1]);

    return 0;
}