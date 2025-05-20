//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 10
#define CONSPIRACY_WORD_LIST_SIZE 50

typedef struct {
    char *word;
    int length;
} ConspiracyWord;

ConspiracyWord conspiracyWords[CONSPIRACY_WORD_LIST_SIZE] = {
    {"Illuminati"},
    {"New World Order"},
    {"Area 51"},
    {"Chemtrails"},
    {"Flat Earth"},
    {"Moon Landing Hoax"},
    {"9/11"},
    {"Big Pharma"},
    {"Deep State"},
    {"Lizard People"},
    {"MK Ultra"},
    {"Roswell"},
    {"Sandy Hook"},
    {"Vaccines"},
    {"HAARP"},
    {"Bilderberg Group"},
    {"Black Helicopters"},
    {"Crisis Actors"},
    {"FEMA Camps"},
    {"Fluoridation"},
    {"JFK Assassination"},
    {"NWO"},
    {"One World Government"},
    {"Orwellian"},
    {"Reptilians"},
    {"Trilateral Commission"},
    {"Zionism"}
};

int main() {
    srand(time(NULL));

    ConspiracyWord *words = malloc(MAX_CONSPIRACY_WORDS * sizeof(ConspiracyWord));
    int numWords = 0;

    while (numWords < MAX_CONSPIRACY_WORDS) {
        int index = rand() % CONSPIRACY_WORD_LIST_SIZE;
        ConspiracyWord *word = &conspiracyWords[index];

        if (word->length + numWords * 3 <= MAX_CONSPIRACY_LENGTH) {
            words[numWords] = *word;
            numWords++;
        }
    }

    printf("The %s are controlling us through ", words[0].word);

    for (int i = 1; i < numWords; i++) {
        printf("%s ", words[i].word);
    }

    printf("and we must %s!\n", words[numWords - 1].word);

    free(words);

    return 0;
}