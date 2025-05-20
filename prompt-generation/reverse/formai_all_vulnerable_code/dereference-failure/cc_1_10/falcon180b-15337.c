//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
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
    int numSentences;
} Document;

char *removePunctuation(char *string) {
    int i, j;
    char *result = malloc(strlen(string) + 1);

    for (i = 0, j = 0; string[i]!= '\0'; i++) {
        if (!isspace(string[i]) &&!ispunct(string[i])) {
            result[j++] = tolower(string[i]);
        }
    }
    result[j] = '\0';

    return result;
}

int compareSentences(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void printSentences(Sentence *sentences, int numSentences) {
    int i;

    for (i = 0; i < numSentences; i++) {
        printf("%s\n", sentences[i].text);
    }
}

int main() {
    char inputText[MAX_SENTENCE_LENGTH];
    char *text = NULL;
    int textLength = 0;
    Sentence sentences[MAX_SENTENCES];
    int numSentences = 0;
    int i;

    printf("Enter the text to summarize:\n");
    fgets(inputText, MAX_SENTENCE_LENGTH, stdin);

    text = removePunctuation(inputText);
    textLength = strlen(text);

    sentences[numSentences++] = (Sentence){text, textLength};

    qsort(sentences, numSentences, sizeof(Sentence), compareSentences);

    printf("Summary:\n");
    for (i = 0; i < numSentences && i < 5; i++) {
        printf("%s\n", sentences[i].text);
    }

    free(text);

    return 0;
}