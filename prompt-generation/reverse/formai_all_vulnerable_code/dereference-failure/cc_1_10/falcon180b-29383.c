//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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
    sentence->text = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
    sentence->length = 0;
}

void add_word(Sentence *sentence, char *word) {
    strcat(sentence->text, word);
    sentence->length += strlen(word);
    if (sentence->length >= MAX_SENTENCE_LENGTH) {
        sentence->text[sentence->length - 1] = '\0';
    }
}

void init_text(Text *text) {
    text->sentences = malloc(MAX_SENTENCES * sizeof(Sentence));
    text->num_sentences = 0;
}

void add_sentence(Text *text, char *sentence) {
    if (text->num_sentences >= MAX_SENTENCES) {
        printf("Error: maximum number of sentences reached.\n");
        return;
    }

    Sentence *new_sentence = &text->sentences[text->num_sentences];
    init_sentence(new_sentence);

    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        add_word(new_sentence, word);
        word = strtok(NULL, " ");
    }

    text->num_sentences++;
}

void print_sentence(Sentence *sentence) {
    printf("%s\n", sentence->text);
}

void print_text(Text *text) {
    for (int i = 0; i < text->num_sentences; i++) {
        print_sentence(&text->sentences[i]);
    }
}

int main() {
    Text text;
    init_text(&text);

    char input[MAX_SENTENCE_LENGTH];
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(&text, input);
    }

    print_text(&text);

    for (int i = 0; i < text.num_sentences; i++) {
        free(text.sentences[i].text);
    }
    free(text.sentences);

    return 0;
}