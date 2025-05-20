//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 1000
#define MAX_THEORY_LENGTH 100

typedef struct {
    char name[MAX_THEORY_LENGTH];
    char description[MAX_THEORY_LENGTH];
} ConspiracyTheory;

ConspiracyTheory theories[MAX_THEORIES];
int numTheories;

void generateTheory(int index) {
    char adjective1[MAX_THEORY_LENGTH];
    char adjective2[MAX_THEORY_LENGTH];
    char noun1[MAX_THEORY_LENGTH];
    char noun2[MAX_THEORY_LENGTH];
    char verb[MAX_THEORY_LENGTH];
    char preposition[MAX_THEORY_LENGTH];
    char article[MAX_THEORY_LENGTH];

    srand(time(NULL));
    int randIndex;

    randIndex = rand() % 10;
    strcpy(adjective1, "secret");
    strcpy(adjective2, " Cover-up");
    strcpy(noun1, "government");
    strcpy(noun2, "aliens");
    strcpy(verb, "is hiding");
    strcpy(preposition, "behind");
    strcpy(article, "the");

    sprintf(theories[index].name, "%s %s %s %s %s %s", adjective1, noun1, preposition, article, noun2, adjective2);
    sprintf(theories[index].description, "%s %s %s %s %s %s %s", article, noun1, verb, preposition, article, noun2, adjective2);
}

void generateRandomTheories(int num) {
    int i;

    for (i = 0; i < num; i++) {
        generateTheory(i);
    }
}

void printTheory(int index) {
    printf("Name: %s\n", theories[index].name);
    printf("Description: %s\n\n", theories[index].description);
}

void printAllTheories() {
    int i;

    for (i = 0; i < numTheories; i++) {
        printTheory(i);
    }
}

int main() {
    int num;

    printf("Enter the number of conspiracy theories to generate: ");
    scanf("%d", &num);

    generateRandomTheories(num);
    printf("\nRandom Conspiracy Theories:\n");
    printAllTheories();

    return 0;
}