//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

struct ConspiracyTheory {
    char title[MAX_WORD_LENGTH];
    char details[MAX_WORD_LENGTH * 3];
};

struct ConspiracyTheory generateTheory();
void printTheory(struct ConspiracyTheory theory);

int main() {
    srand(time(NULL));

    int numTheories;
    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &numTheories);

    for (int i = 0; i < numTheories; i++) {
        struct ConspiracyTheory theory = generateTheory();
        printf("\nConspiracy Theory #%d:\n", i + 1);
        printTheory(theory);
        printf("\n");
    }

    return 0;
}

struct ConspiracyTheory generateTheory() {
    struct ConspiracyTheory theory;
    theory.title[0] = '\0';
    theory.details[0] = '\0';

    int numWordsInTitle = rand() % 3 + 2;
    for (int i = 0; i < numWordsInTitle; i++) {
        int wordLength = rand() % MAX_WORD_LENGTH + 1;
        theory.title[i * MAX_WORD_LENGTH] = '\0';
        for (int j = 0; j < wordLength; j++) {
            theory.title[i * MAX_WORD_LENGTH + j] = rand() % 26 + 'a';
        }
    }

    int numWordsInDetails = rand() % 5 + 3;
    for (int i = 0; i < numWordsInDetails; i++) {
        int wordLength = rand() % MAX_WORD_LENGTH + 1;
        theory.details[i * MAX_WORD_LENGTH] = '\0';
        for (int j = 0; j < wordLength; j++) {
            theory.details[i * MAX_WORD_LENGTH + j] = rand() % 26 + 'a';
        }
    }

    return theory;
}

void printTheory(struct ConspiracyTheory theory) {
    printf("Title: %s\n", theory.title);
    printf("Details: %s\n", theory.details);
}