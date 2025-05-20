//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LENGTH 1024
#define MAX_WORDS 1024

typedef struct {
    char *word;
    int count;
} word_t;

typedef struct {
    word_t words[MAX_WORDS];
    int word_count;
} doc_t;

void add_word(doc_t *doc, char *word) {
    int i;

    for (i = 0; i < doc->word_count; i++) {
        if (strcmp(doc->words[i].word, word) == 0) {
            doc->words[i].count++;
            return;
        }
    }

    if (doc->word_count == MAX_WORDS) {
        printf("Warning: exceeded maximum number of words\n");
        return;
    }

    doc->words[doc->word_count].word = word;
    doc->words[doc->word_count].count = 1;
    doc->word_count++;
}

void print_doc(doc_t *doc) {
    int i;

    for (i = 0; i < doc->word_count; i++) {
        if (doc->words[i].count > 0) {
            printf("%s: %d\n", doc->words[i].word, doc->words[i].count);
        }
    }
}

int main() {
    doc_t *doc = malloc(sizeof(doc_t));
    int i;

    for (i = 0; i < MAX_LENGTH; i++) {
        char c = getchar();

        if (c == '\n') {
            add_word(doc, "");
        } else {
            add_word(doc, &c);
        }
    }

    print_doc(doc);

    return 0;
}