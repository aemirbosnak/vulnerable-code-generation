//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 1000
#define MAX_WORDS 10000

typedef struct {
    char *text;
    int length;
} Sentence;

typedef struct {
    Sentence *sentences;
    int numSentences;
} Document;

int compareSentences(const void *a, const void *b) {
    Sentence *sentenceA = *(Sentence **)a;
    Sentence *sentenceB = *(Sentence **)b;

    return strcmp(sentenceA->text, sentenceB->text);
}

void printSentences(Sentence *sentences, int numSentences) {
    for (int i = 0; i < numSentences; i++) {
        printf("%s\n", sentences[i].text);
    }
}

int main() {
    FILE *inputFile;
    char inputText[MAX_SENTENCE_LENGTH];
    int inputLength = 0;
    Sentence *sentences = NULL;
    int numSentences = 0;
    int maxSentenceLength = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fgets(inputText, MAX_SENTENCE_LENGTH, inputFile)!= NULL) {
        inputLength = strlen(inputText);

        if (inputLength > maxSentenceLength) {
            maxSentenceLength = inputLength;
        }

        sentences = realloc(sentences, sizeof(Sentence) * (numSentences + 1));

        sentences[numSentences].text = malloc(inputLength + 1);
        strcpy(sentences[numSentences].text, inputText);
        sentences[numSentences].length = inputLength;

        numSentences++;
    }

    fclose(inputFile);

    qsort(sentences, numSentences, sizeof(Sentence), compareSentences);

    printSentences(sentences, numSentences);

    free(sentences);

    return 0;
}