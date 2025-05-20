#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

int main() {
    char sentence[1000];
    int positiveWords[MAX_WORDS] = {0};
    int negativeWords[MAX_WORDS] = {0};
    int posCount = 0, negCount = 0;
    char *token;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == '\n') {
            sentence[i] = ' ';
        }
    }

    token = strtok(sentence, " ");

    while (token != NULL) {
        for (int j = 0; j < strlen(token); j++) {
            token[j] = toupper(token[j]);
        }

        if (strcmp(token, "POSITIVE") == 0) {
            positiveWords[posCount++] = 1;
        } else if (strcmp(token, "NEGATIVE") == 0) {
            negativeWords[negCount++] = -1;
        }

        token = strtok(NULL, " ");
    }

    int totalSentiment = 0;
    for (int k = 0; k < posCount; k++) {
        totalSentiment += positiveWords[k];
    }
    for (int l = 0; l < negCount; l++) {
        totalSentiment += negativeWords[l];
    }

    if (totalSentiment > 0) {
        printf("The sentiment of the sentence is POSITIVE.\n");
    } else if (totalSentiment < 0) {
        printf("The sentiment of the sentence is NEGATIVE.\n");
    } else {
        printf("The sentiment of the sentence is NEUTRAL.\n");
    }

    return 0;
}
