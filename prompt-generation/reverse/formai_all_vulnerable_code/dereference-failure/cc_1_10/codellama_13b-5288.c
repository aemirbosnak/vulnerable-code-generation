//Code Llama-13B DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_WORD_LEN 100

struct Sentence {
    char text[MAX_WORD_LEN];
    struct Sentence* next;
};

struct Sentence* create_sentence(char* text) {
    struct Sentence* sentence = malloc(sizeof(struct Sentence));
    strcpy(sentence->text, text);
    sentence->next = NULL;
    return sentence;
}

void add_sentence(struct Sentence* sentence, char* text) {
    struct Sentence* new_sentence = create_sentence(text);
    sentence->next = new_sentence;
}

int get_sentence_count(struct Sentence* sentence) {
    int count = 1;
    while (sentence->next != NULL) {
        sentence = sentence->next;
        count++;
    }
    return count;
}

void summarize(struct Sentence* sentence) {
    int count = get_sentence_count(sentence);
    int i;
    for (i = 0; i < count; i++) {
        printf("%s ", sentence->text);
        sentence = sentence->next;
    }
    printf("\n");
}

int main() {
    struct Sentence* sentence = create_sentence("This is a sample text for testing.");
    add_sentence(sentence, "This is another sentence.");
    add_sentence(sentence, "This is the third sentence.");
    add_sentence(sentence, "This is the fourth sentence.");
    add_sentence(sentence, "This is the fifth sentence.");
    summarize(sentence);
    return 0;
}