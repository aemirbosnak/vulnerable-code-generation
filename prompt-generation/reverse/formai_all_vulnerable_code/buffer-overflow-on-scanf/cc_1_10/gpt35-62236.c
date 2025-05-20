//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro() {
    printf("Welcome to the Random Conspiracy Theory Generator\n\n");
    printf("This program generates conspiracy theories randomly.\n");
    printf("Use at your own risk.\n\n");
}

void printOutro() {
    printf("\nThank you for using the Random Conspiracy Theory Generator.\n");
    printf("Watch out for the Illuminati and have a nice day!\n");
}

char* generateNoun() {
    char* nouns[] = {"government", "aliens", "Illuminati", "vaccines", "Bilderberg Group", "chemtrails", "Big Pharma", "New World Order", "FEMA camps", "World Health Organization"};
    int index = rand() % 10;
    return nouns[index];
}

char* generateVerb() {
    char* verbs[] = {"control", "manipulate", "brainwash", "spy on", "infiltrate", "poison", "suppress", "take over", "destabilize", "enslave"};
    int index = rand() % 10;
    return verbs[index];
}

char* generateObject() {
    char* objects[] = {"population", "media", "economy", "environment", "food supply", "water supply", "technology", "education system", "political system", "healthcare system"};
    int index = rand() % 10;
    return objects[index];
}

int main() {
    srand(time(0));
    printIntro();

    int numTheories;
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &numTheories);
    printf("\n");

    for (int i = 1; i <= numTheories; i++) {
        char* noun = generateNoun();
        char* verb = generateVerb();
        char* object = generateObject();

        printf("Conspiracy Theory #%d: The %s is trying to %s the %s!\n", i, noun, verb, object);
    }

    printOutro();
    return 0;
}