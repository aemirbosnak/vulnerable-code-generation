//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 1000
#define SENTENCE_LENGTH_THRESHOLD 5

typedef struct sentence {
    char words[MAX_WORDS][100];
    int length;
} Sentence;

typedef struct document {
    Sentence sentences[MAX_SENTENCES];
    int num_sentences;
} Document;

void add_sentence(Document *doc) {
    if (doc->num_sentences >= MAX_SENTENCES) {
        printf("Error: Maximum number of sentences reached.\n");
        return;
    }

    Sentence sentence;
    char word[100];
    int length = 0;

    printf("Enter a sentence: ");
    fgets(word, sizeof(word), stdin);

    while (length < SENTENCE_LENGTH_THRESHOLD) {
        printf("Sentence is too short. Please enter a longer sentence: ");
        fgets(word, sizeof(word), stdin);
        length = strlen(word);
    }

    strcpy(sentence.words[0], word);
    sentence.length = length;

    doc->sentences[doc->num_sentences] = sentence;
    doc->num_sentences++;
}

void summarize(Document *doc) {
    if (doc->num_sentences == 0) {
        printf("Error: Document is empty.\n");
        return;
    }

    int max_sentence_length = 0;
    for (int i = 0; i < doc->num_sentences; i++) {
        if (doc->sentences[i].length > max_sentence_length) {
            max_sentence_length = doc->sentences[i].length;
        }
    }

    printf("Summary:\n");
    for (int i = 0; i < doc->num_sentences; i++) {
        if (doc->sentences[i].length >= max_sentence_length / 2) {
            printf("%s\n", doc->sentences[i].words[0]);
        }
    }
}

int main() {
    Document doc;
    doc.num_sentences = 0;

    while (1) {
        printf("1. Add sentence\n2. Summarize\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_sentence(&doc);
            break;
        case 2:
            summarize(&doc);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}