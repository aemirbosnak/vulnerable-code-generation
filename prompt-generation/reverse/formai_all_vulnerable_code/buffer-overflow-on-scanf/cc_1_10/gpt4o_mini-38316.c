//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 10
#define MAX_PHRASES 10
#define MAX_KEYWORDS 10
#define RANDOMIZE_LIMIT 5

const char *subjects[MAX_THEORIES] = {
    "the moon landing", "global warming", "bigfoot", "aliens", 
    "the Bermuda Triangle", "vaccines", "the assassination of JFK", 
    "the Illuminati", "Area 51", "the hollow Earth theory"
};

const char *verbs[MAX_PHRASES] = {
    "is staged", "is a hoax", "is being covered up", 
    "is connected to", "is a distraction from", 
    "is actually about", "is controlled by", "hides the truth of", 
    "is influenced by", "causes"
};

const char *objects[MAX_KEYWORDS] = {
    "government secrets", "advanced aliens", "secret societies", 
    "powerful corporations", "ancient artifacts", 
    "mind control programs", "the deep state", 
    "hidden technology", "global elites", 
    "the weather control system"
};

void generateTheory() {
    int subjectIndex = rand() % MAX_THEORIES;
    int verbIndex = rand() % MAX_PHRASES;
    int objectIndex = rand() % MAX_KEYWORDS;

    printf("The theory goes: %s %s %s.\n", 
        subjects[subjectIndex], 
        verbs[verbIndex], 
        objects[objectIndex]);
}

void waitForInput() {
    printf("Press Enter to generate another theory...\n");
    while (getchar() != '\n');
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char continueGenerating = 'y';

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    while (continueGenerating == 'y') {
        generateTheory();
        waitForInput();

        printf("Would you like to generate another theory? (y/n): ");
        scanf(" %c", &continueGenerating);
        // Clear the stdin buffer before the next getchar
        while (getchar() != '\n');
    }

    printf("Thank you for using the Random Conspiracy Theory Generator! Stay curious!\n");
    return 0;
}