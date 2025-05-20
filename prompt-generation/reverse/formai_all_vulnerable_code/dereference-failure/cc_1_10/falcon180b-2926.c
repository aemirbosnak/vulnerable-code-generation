//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define SENTENCE_DELIMITERS " \t\r\n\a"
#define SUMMARY_LENGTH 50

typedef struct sentence {
    char *text;
    int length;
    struct sentence *next;
} Sentence;

typedef struct summary {
    Sentence *sentences;
    int length;
} Summary;

Summary *generateSummary(char *text);
void printSummary(Summary *summary);

int main() {
    char text[1000];
    printf("Enter text to summarize: ");
    fgets(text, 1000, stdin);
    Summary *summary = generateSummary(text);
    printSummary(summary);
    return 0;
}

Summary *generateSummary(char *text) {
    Sentence *sentences = NULL;
    int length = 0;
    char sentence[MAX_SENTENCE_LENGTH];
    int sentenceLength = 0;
    char *token = strtok(text, SENTENCE_DELIMITERS);
    while (token!= NULL) {
        strcat(sentence, token);
        sentenceLength += strlen(token);
        if (sentenceLength >= MAX_SENTENCE_LENGTH) {
            break;
        }
        token = strtok(NULL, SENTENCE_DELIMITERS);
    }
    if (sentenceLength > 0) {
        Sentence *newSentence = malloc(sizeof(Sentence));
        newSentence->text = strdup(sentence);
        newSentence->length = sentenceLength;
        newSentence->next = NULL;
        if (sentences == NULL) {
            sentences = newSentence;
        } else {
            Sentence *lastSentence = sentences;
            while (lastSentence->next!= NULL) {
                lastSentence = lastSentence->next;
            }
            lastSentence->next = newSentence;
        }
        length++;
    }
    while ((token = strtok(NULL, SENTENCE_DELIMITERS))!= NULL) {
        if (strlen(token) > 0) {
            Sentence *newSentence = malloc(sizeof(Sentence));
            newSentence->text = strdup(token);
            newSentence->length = strlen(token);
            newSentence->next = NULL;
            if (sentences == NULL) {
                sentences = newSentence;
            } else {
                Sentence *lastSentence = sentences;
                while (lastSentence->next!= NULL) {
                    lastSentence = lastSentence->next;
                }
                lastSentence->next = newSentence;
            }
            length++;
        }
    }
    Summary *summary = malloc(sizeof(Summary));
    summary->sentences = sentences;
    summary->length = length;
    return summary;
}

void printSummary(Summary *summary) {
    printf("Summary:\n");
    int i = 0;
    Sentence *sentence = summary->sentences;
    while (i < summary->length && sentence!= NULL) {
        if (sentence->length > SUMMARY_LENGTH) {
            printf("%s...\n", sentence->text);
        } else {
            printf("%s\n", sentence->text);
        }
        i++;
        sentence = sentence->next;
    }
}