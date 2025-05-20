//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 100
#define WORD_FILE "words.txt"

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES];

void loadWords() {
    FILE *fp = fopen(WORD_FILE, "r");
    char word[MAX_WORDS];
    int i = 0;

    if (fp == NULL) {
        printf("Error opening file %s\n", WORD_FILE);
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        conspiracies[i].name = strdup(word);
        conspiracies[i].description = NULL;
        i++;
    }

    fclose(fp);
}

void generateTheory() {
    srand(time(NULL));
    int i = rand() % MAX_CONSPIRACIES;

    if (conspiracies[i].description == NULL) {
        char *words[MAX_WORDS];
        int numWords = 0;

        while (numWords < 3) {
            int j = rand() % MAX_WORDS;

            if (j == 0 || strcmp(conspiracies[i].name, words[j])!= 0) {
                words[numWords++] = conspiracies[i].name;
            }
        }

        char theory[1000];
        sprintf(theory, "The %s conspiracy involves %s, %s, and %s.",
                conspiracies[i].name, words[0], words[1], words[2]);
        conspiracies[i].description = strdup(theory);
    }

    printf("%s\n", conspiracies[i].description);
}

int main() {
    loadWords();

    while (1) {
        generateTheory();
    }

    return 0;
}