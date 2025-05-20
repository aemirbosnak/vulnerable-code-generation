//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

typedef struct {
    char name[MAX_WORD_LENGTH];
    char description[MAX_WORD_LENGTH];
} ConspiracyTheory;

ConspiracyTheory conspiracies[MAX_CONSPIRACIES];

void generateRandomConspiracy(int index) {
    char noun1[MAX_WORD_LENGTH];
    char noun2[MAX_WORD_LENGTH];
    char verb[MAX_WORD_LENGTH];
    char preposition[MAX_WORD_LENGTH];
    char article[MAX_WORD_LENGTH];

    srand(time(NULL));
    int randomIndex = rand() % MAX_WORDS;
    strcpy(noun1, "government");
    strcpy(noun2, "aliens");
    strcpy(verb, "control");
    strcpy(preposition, "by");
    strcpy(article, "the");

    char* theoryName = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    char* theoryDesc = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));

    sprintf(theoryName, "%s %s %s %s %s", article, noun1, preposition, noun2, verb);
    sprintf(theoryDesc, "It is believed that %s %s %s %s %s. This theory has gained traction among certain groups, despite lack of evidence.", article, noun1, preposition, noun2, verb);

    strcpy(conspiracies[index].name, theoryName);
    strcpy(conspiracies[index].description, theoryDesc);
}

int main() {
    int numTheories;

    printf("How many random conspiracy theories would you like to generate? ");
    scanf("%d", &numTheories);

    for (int i = 0; i < numTheories; i++) {
        generateRandomConspiracy(i);
        printf("\n%s: %s\n", conspiracies[i].name, conspiracies[i].description);
    }

    return 0;
}