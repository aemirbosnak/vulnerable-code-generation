//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_LENGTH 256

const char* subjects[] = {
    "aliens", 
    "the government", 
    "big tech", 
    "the moon landing", 
    "the vaccine", 
    "the Illuminati", 
    "5G towers", 
    "the Freemasons", 
    "the lizard people", 
    "the flat Earth society"
};

const char* actions[] = {
    "are monitoring", 
    "are controlling", 
    "supporting", 
    "created a fake narrative about", 
    "are hiding the truth about", 
    "are collaborating to manipulate", 
    "want to distract us from", 
    "are planning to eradicate", 
    "have infiltrated", 
    "are using to track"
};

const char* ideas[] = {
    "for their own gain", 
    "to prevent us from discovering the truth", 
    "to instill fear among the populace", 
    "to distract us from the real issues", 
    "to control our minds", 
    "to prepare for the impending takeover", 
    "to suppress our freedom", 
    "to maintain their power", 
    "to manipulate our thoughts", 
    "to keep us in the dark"
};

const char* outcomes[] = {
    "and nobody is talking about it.", 
    "and we are blissfully unaware.", 
    "and it's time we wake up!", 
    "and you must spread the word!", 
    "and the truth must come out!", 
    "and history will judge them harshly.", 
    "while they laugh in our faces.", 
    "and the evidence is all around us.", 
    "or we will all be lost!", 
    "if we don’t take action now."
};

void generateTheory() {
    int subjectIndex = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int actionIndex = rand() % (sizeof(actions) / sizeof(actions[0]));
    int ideaIndex = rand() % (sizeof(ideas) / sizeof(ideas[0]));
    int outcomeIndex = rand() % (sizeof(outcomes) / sizeof(outcomes[0]));

    printf("Paranoid Theory: %s %s %s %s\n", 
           subjects[subjectIndex], 
           actions[actionIndex], 
           ideas[ideaIndex], 
           outcomes[outcomeIndex]);
}

void showInstructions() {
    printf("Welcome to the C Random Conspiracy Theory Generator!\n");
    printf("This program will generate unique paranoid conspiracy theories.\n");
    printf("Enter the number of theories you want to generate (up to %d): ", MAX_THEORIES);
}

int main() {
    srand(time(NULL));
    int numberOfTheories;

    showInstructions();
    scanf("%d", &numberOfTheories);

    if (numberOfTheories < 1 || numberOfTheories > MAX_THEORIES) {
        printf("Invalid number. Please enter a value between 1 and %d.\n", MAX_THEORIES);
        return EXIT_FAILURE;
    }

    printf("\nGenerating %d Paranoid Conspiracy Theories...\n", numberOfTheories);
    for (int i = 0; i < numberOfTheories; i++) {
        generateTheory();
    }

    printf("Stay aware, stay vigilant!\n");
    return EXIT_SUCCESS;
}