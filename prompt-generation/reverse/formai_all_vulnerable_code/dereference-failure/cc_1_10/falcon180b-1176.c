//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 100
#define MAX_WORDS_PER_SENTENCE 50

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} Document;

void add_sentence(Document *doc) {
    if (doc->num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }

    Sentence new_sentence;
    new_sentence.text = malloc(MAX_SENTENCE_LENGTH * sizeof(char));
    new_sentence.length = 0;

    printf("Enter a sentence:\n");
    fgets(new_sentence.text, MAX_SENTENCE_LENGTH, stdin);
    new_sentence.length = strlen(new_sentence.text);

    doc->sentences[doc->num_sentences] = new_sentence;
    doc->num_sentences++;
}

void summarize_document(Document *doc, int num_words) {
    if (doc->num_sentences == 0) {
        printf("Error: Document is empty.\n");
        return;
    }

    int total_words = 0;
    for (int i = 0; i < doc->num_sentences; i++) {
        total_words += doc->sentences[i].length;
    }

    if (num_words > total_words) {
        printf("Error: Requested number of words is greater than total number of words in document.\n");
        return;
    }

    char *summary = malloc(num_words * sizeof(char));
    summary[0] = '\0';
    int current_word_count = 0;

    for (int i = 0; i < doc->num_sentences; i++) {
        int sentence_length = doc->sentences[i].length;
        if (sentence_length > num_words - current_word_count) {
            sentence_length = num_words - current_word_count;
        }

        char *sentence_text = doc->sentences[i].text;
        int j;
        for (j = 0; j < sentence_length && isalnum(sentence_text[j]); j++) {
            summary[current_word_count] = tolower(sentence_text[j]);
            current_word_count++;
        }

        if (current_word_count >= num_words) {
            break;
        }
    }

    printf("Summary: %s\n", summary);
}

int main() {
    Document doc;
    doc.num_sentences = 0;

    int num_sentences = 0;
    while (true) {
        add_sentence(&doc);
        num_sentences++;

        if (num_sentences >= MAX_SENTENCES) {
            break;
        }
    }

    int num_words;
    printf("Enter the desired number of words in the summary:\n");
    scanf("%d", &num_words);

    summarize_document(&doc, num_words);

    for (int i = 0; i < doc.num_sentences; i++) {
        free(doc.sentences[i].text);
    }

    return 0;
}