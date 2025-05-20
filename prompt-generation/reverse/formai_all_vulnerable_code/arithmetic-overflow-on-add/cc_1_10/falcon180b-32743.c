//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 100
#define MAX_WORDS 1000

struct sentence {
    char words[MAX_SENTENCE_LENGTH];
    int length;
};

struct text {
    int num_sentences;
    struct sentence sentences[MAX_SENTENCES];
};

void read_text(struct text *text) {
    char ch;
    int i = 0, j = 0;

    printf("Enter the text: ");
    while ((ch = getchar())!= '\n') {
        if (i >= MAX_SENTENCE_LENGTH) {
            printf("Sentence too long.\n");
            exit(1);
        }
        text->sentences[j].words[i++] = ch;
    }
    text->sentences[j].length = i;
    text->num_sentences++;
}

void tokenize_text(struct text *text) {
    int i, j, k;
    char *word;

    for (i = 0; i < text->num_sentences; i++) {
        word = strtok(text->sentences[i].words, ",.?!;");
        while (word!= NULL) {
            if (j >= MAX_WORDS) {
                printf("Too many words.\n");
                exit(1);
            }
            strcpy(text->sentences[i].words + k, word);
            k += strlen(word) + 1;
            word = strtok(NULL, ",.?!;");
            j++;
        }
        text->sentences[i].length = k;
    }
}

void summarize_text(struct text *text, int num_sentences) {
    int i, j;
    float freq[MAX_WORDS];

    for (i = 0; i < num_sentences; i++) {
        for (j = 0; j < text->sentences[i].length; j++) {
            freq[j]++;
        }
    }

    for (i = 0; i < num_sentences; i++) {
        for (j = 0; j < text->sentences[i].length; j++) {
            if (freq[j] > 0.1) {
                printf("%s ", text->sentences[i].words + j);
            }
        }
        printf("\n");
    }
}

int main() {
    struct text text;

    read_text(&text);
    tokenize_text(&text);

    int num_sentences = 3;
    summarize_text(&text, num_sentences);

    return 0;
}