//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 256
#define MAX_WORD_LENGTH 32
#define MAX_SENTENCES 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

typedef struct {
    int length;
    int numWords;
    char **words;
} Sentence;

Sentence *sentences = NULL;
int numSentences = 0;

void addSentence(char *sentence) {
    if (numSentences >= MAX_SENTENCES) {
        fprintf(stderr, "Error: Too many sentences.\n");
        exit(1);
    }
    int length = strlen(sentence);
    if (length > MAX_SENTENCE_LENGTH) {
        fprintf(stderr, "Error: Sentence is too long.\n");
        exit(1);
    }
    sentences = realloc(sentences, sizeof(Sentence) * ++numSentences);
    sentences[numSentences - 1].length = length;
    sentences[numSentences - 1].numWords = 0;
    sentences[numSentences - 1].words = calloc(MAX_SENTENCE_LENGTH, sizeof(char *));
    int i = 0;
    while (i < length) {
        int j = 0;
        while (i < length && isalnum(sentence[i])) {
            if (j >= MAX_WORD_LENGTH) {
                fprintf(stderr, "Error: Word is too long.\n");
                exit(1);
            }
            sentences[numSentences - 1].words[j++] = &sentence[i];
            i++;
        }
        if (j > 0) {
            sentences[numSentences - 1].numWords++;
        }
    }
}

void printSummary(int numWords) {
    fprintf(stdout, "Summary:\n");
    fprintf(stdout, "Number of sentences: %d\n", numSentences);
    fprintf(stdout, "Total number of words: %d\n", numWords);
    fprintf(stdout, "Average number of words per sentence: %.2f\n", (float)numWords / numSentences);
}

int main() {
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    addSentence("The quick brown fox jumps over the lazy dog. ");
    addSentence("How much wood would a woodchuck chuck if a woodchuck could chuck wood? ");
    printSummary(0);
    return 0;
}