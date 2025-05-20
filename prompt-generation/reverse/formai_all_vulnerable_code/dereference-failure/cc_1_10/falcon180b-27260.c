//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Document;

Document *create_document() {
    Document *doc = (Document*) malloc(sizeof(Document));
    doc->sentences = (Sentence*) malloc(MAX_SENTENCES * sizeof(Sentence));
    doc->num_sentences = 0;
    return doc;
}

void destroy_document(Document *doc) {
    for (int i = 0; i < doc->num_sentences; i++) {
        free(doc->sentences[i].text);
    }
    free(doc->sentences);
    free(doc);
}

void add_sentence(Document *doc, char *text) {
    if (doc->num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }
    doc->sentences[doc->num_sentences].text = strdup(text);
    doc->sentences[doc->num_sentences].length = strlen(text);
    doc->num_sentences++;
}

int count_words(char *text) {
    int count = 0;
    char *word = strtok(text, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

int main() {
    Document *doc = create_document();
    char input[MAX_SENTENCE_LENGTH];

    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(doc, input);
    }

    int total_words = 0;
    for (int i = 0; i < doc->num_sentences; i++) {
        total_words += count_words(doc->sentences[i].text);
    }

    printf("Total words: %d\n", total_words);

    destroy_document(doc);

    return 0;
}