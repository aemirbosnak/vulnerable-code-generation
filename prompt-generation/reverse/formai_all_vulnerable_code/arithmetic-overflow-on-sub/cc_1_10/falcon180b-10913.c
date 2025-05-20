//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 100

typedef struct {
    char sentence[MAX_SENTENCE_LENGTH];
    int length;
} Sentence;

void readSentences(Sentence sentences[], int numSentences) {
    char input[MAX_SENTENCE_LENGTH];

    for (int i = 0; i < numSentences; i++) {
        printf("Enter sentence %d: ", i + 1);
        fgets(input, MAX_SENTENCE_LENGTH, stdin);

        strcpy(sentences[i].sentence, input);
        sentences[i].length = strlen(sentences[i].sentence);
    }
}

void sortSentences(Sentence sentences[], int numSentences) {
    for (int i = 0; i < numSentences - 1; i++) {
        for (int j = i + 1; j < numSentences; j++) {
            if (sentences[i].length > sentences[j].length) {
                Sentence temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }
}

void printSentences(Sentence sentences[], int numSentences) {
    for (int i = 0; i < numSentences; i++) {
        printf("%s (%d characters)\n", sentences[i].sentence, sentences[i].length);
    }
}

int main() {
    int numSentences;

    printf("Enter the number of sentences: ");
    scanf("%d", &numSentences);

    if (numSentences > MAX_SENTENCES) {
        printf("Error: Too many sentences.\n");
        return 1;
    }

    Sentence sentences[numSentences];

    readSentences(sentences, numSentences);
    sortSentences(sentences, numSentences);
    printSentences(sentences, numSentences);

    return 0;
}