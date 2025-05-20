//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_DOCUMENT_LENGTH 100000
#define MAX_SENTENCES_PER_DOCUMENT 1000

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int num_sentences;
} Document;

Document *create_document(int num_sentences) {
    Document *doc = (Document *) malloc(sizeof(Document));
    doc->sentences = (Sentence *) malloc(num_sentences * sizeof(Sentence));
    doc->num_sentences = num_sentences;
    for (int i = 0; i < num_sentences; i++) {
        doc->sentences[i].text = NULL;
        doc->sentences[i].length = 0;
    }
    return doc;
}

void destroy_document(Document *doc) {
    for (int i = 0; i < doc->num_sentences; i++) {
        if (doc->sentences[i].text!= NULL) {
            free(doc->sentences[i].text);
        }
    }
    free(doc->sentences);
    free(doc);
}

void add_sentence(Document *doc, char *text) {
    int length = strlen(text);
    if (length > MAX_SENTENCE_LENGTH) {
        printf("Error: sentence is too long.\n");
        return;
    }
    if (doc->num_sentences >= MAX_SENTENCES_PER_DOCUMENT) {
        printf("Error: document has too many sentences.\n");
        return;
    }
    doc->sentences[doc->num_sentences].text = strdup(text);
    doc->sentences[doc->num_sentences].length = length;
    doc->num_sentences++;
}

int main() {
    Document *doc = create_document(0);
    char input[MAX_SENTENCE_LENGTH];
    while (fgets(input, MAX_SENTENCE_LENGTH, stdin)!= NULL) {
        add_sentence(doc, input);
    }
    destroy_document(doc);
    return 0;
}