//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_CONSPIRACY_WORDS 10
#define MAX_CONSPIRACY_THEORIES 100

typedef struct {
    char *name;
    char *description;
} ConspiracyTheory;

ConspiracyTheory theories[MAX_CONSPIRACY_THEORIES];
int numTheories;

void generateRandomConspiracyTheory() {
    int numWords = rand() % MAX_CONSPIRACY_WORDS + 1;
    char *theory = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
    int i;

    for (i = 0; i < numWords; i++) {
        char *word = malloc(10 * sizeof(char));
        sprintf(word, "%d", rand() % 1000);
        strcat(theory, word);
        strcat(theory, " ");
    }

    theories[numTheories].name = malloc(strlen(theory) * sizeof(char));
    strcpy(theories[numTheories].name, theory);
    theories[numTheories].description = malloc(strlen(theory) * sizeof(char));
    strcpy(theories[numTheories].description, theory);

    numTheories++;
}

int main() {
    srand(time(NULL));

    int i;
    for (i = 0; i < MAX_CONSPIRACY_THEORIES; i++) {
        generateRandomConspiracyTheory();
    }

    for (i = 0; i < numTheories; i++) {
        printf("Name: %s\n", theories[i].name);
        printf("Description: %s\n\n", theories[i].description);
    }

    return 0;
}