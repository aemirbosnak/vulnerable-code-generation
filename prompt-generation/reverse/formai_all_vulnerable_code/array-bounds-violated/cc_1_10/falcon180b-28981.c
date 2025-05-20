//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 50
#define MAX_CONSPIRACY_WORDS 10
#define CONSPIRACY_WORD_LIST_SIZE 50

typedef struct {
    char *word;
    int frequency;
} ConspiracyWord;

ConspiracyWord conspiracyWords[CONSPIRACY_WORD_LIST_SIZE] = {
    {"government", 5},
    {"illuminati", 4},
    {"secret", 3},
    {"cover-up", 3},
    {"aliens", 2},
    {"chemtrails", 2},
    {"deep state", 2},
    {"mind control", 2},
    {"new world order", 2},
    {"reptilians", 2},
    {"9/11", 1},
    {"assassination", 1},
    {"big pharma", 1},
    {"covid-19", 1},
    {"false flag", 1},
    {"flat earth", 1},
    {"moon landing", 1},
    {"sandy hook", 1},
    {"vaccines", 1}
};

int compareFrequency(const void *a, const void *b) {
    ConspiracyWord *wordA = (ConspiracyWord *) a;
    ConspiracyWord *wordB = (ConspiracyWord *) b;
    return wordB->frequency - wordA->frequency;
}

void generateConspiracyTheory(char *theory, int length) {
    srand(time(NULL));
    int numWords = rand() % MAX_CONSPIRACY_WORDS + 1;
    ConspiracyWord *words[MAX_CONSPIRACY_WORDS];
    int i;
    for (i = 0; i < CONSPIRACY_WORD_LIST_SIZE; i++) {
        words[i] = &conspiracyWords[i];
    }
    qsort(words, CONSPIRACY_WORD_LIST_SIZE, sizeof(ConspiracyWord *), compareFrequency);
    for (i = 0; i < numWords; i++) {
        strcat(theory, words[i]->word);
        strcat(theory, " ");
    }
    theory[length - 1] = '\0';
}

int main() {
    int length = rand() % MAX_CONSPIRACY_LENGTH + 1;
    char theory[MAX_CONSPIRACY_LENGTH];
    generateConspiracyTheory(theory, length);
    printf("The %s is a lie perpetuated by the %s to control the masses.\n", theory, theory);
    return 0;
}