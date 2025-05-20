//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 100
#define MAX_NAMES 50
#define MAX_VERBS 50
#define MAX_NOUNS 50

typedef struct {
    char *name;
    char *verb;
    char *noun;
} Conspiracy;

Conspiracy conspiracies[MAX_CONSPIRACY_LENGTH];
char names[MAX_NAMES][20];
char verbs[MAX_VERBS][20];
char nouns[MAX_NOUNS][20];

int main() {
    int i, j, k;
    char input[80];

    // Initialize random seed
    srand(time(NULL));

    // Populate arrays with names, verbs, and nouns
    for (i = 0; i < MAX_NAMES; i++) {
        sprintf(input, "name%d", i);
        scanf("%s", input);
        strcpy(names[i], input);
    }

    for (i = 0; i < MAX_VERBS; i++) {
        sprintf(input, "verb%d", i);
        scanf("%s", input);
        strcpy(verbs[i], input);
    }

    for (i = 0; i < MAX_NOUNS; i++) {
        sprintf(input, "noun%d", i);
        scanf("%s", input);
        strcpy(nouns[i], input);
    }

    // Generate conspiracies
    for (i = 0; i < MAX_CONSPIRACY_LENGTH; i++) {
        sprintf(input, "conspiracy%d", i);
        scanf("%s", input);
        strcpy(conspiracies[i].name, input);

        for (j = 0; j < 3; j++) {
            sprintf(input, "verb%d", rand() % MAX_VERBS);
            strcpy(conspiracies[i].verb, verbs[rand() % MAX_VERBS]);

            sprintf(input, "noun%d", rand() % MAX_NOUNS);
            strcpy(conspiracies[i].noun, nouns[rand() % MAX_NOUNS]);
        }
    }

    // Print conspiracies
    for (i = 0; i < MAX_CONSPIRACY_LENGTH; i++) {
        printf("Conspiracy %d: %s is %s %s to %s.\n", i+1, conspiracies[i].name, conspiracies[i].verb, conspiracies[i].noun, conspiracies[i].verb);
    }

    return 0;
}