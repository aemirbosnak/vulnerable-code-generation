//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 10
#define MAX_LENGTH 256

const char* subjects[] = {
    "The moon landing",
    "Climate change",
    "Bigfoot",
    "Aliens",
    "Vaccines",
    "The Illuminati",
    "Reptilian overlords",
    "The Bermuda Triangle",
    "5G technology",
    "The Flat Earth Society"
};

const char* actions[] = {
    "was staged by",
    "is a hoax created by",
    "has been covered up by",
    "is actually",
    "is a distraction orchestrated by",
    "is caused by",
    "was designed to hide",
    "is an experiment by"
};

const char* organizations[] = {
    "NASA",
    "the government",
    "the lizard people",
    "scientists",
    "the media",
    "a secret society",
    "big corporations",
    "global elites",
    "the UN",
    "time travelers"
};

const char* alternate_explanations[] = {
    "to control the populace.",
    "to hide the truth about time travel.",
    "for profit and power.",
    "to manipulate reality.",
    "to test mind control technology.",
    "because they know we can handle the truth.",
    "to distract us from the real issues.",
    "to prepare us for extraterrestrial contact.",
    "to rewrite history.",
    "to prevent us from discovering our true potential."
};

void generate_theory(char* theory) {
    int sub_index = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int act_index = rand() % (sizeof(actions) / sizeof(actions[0]));
    int org_index = rand() % (sizeof(organizations) / sizeof(organizations[0]));
    int alt_index = rand() % (sizeof(alternate_explanations) / sizeof(alternate_explanations[0]));

    // Creating a theory string
    snprintf(theory, MAX_LENGTH, "%s %s %s %s", subjects[sub_index], actions[act_index], organizations[org_index], alternate_explanations[alt_index]);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    char theory[MAX_LENGTH];
    int number_of_theories;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("How many theories would you like to generate? ");
    scanf("%d", &number_of_theories);

    if (number_of_theories > MAX_THEORIES) {
        number_of_theories = MAX_THEORIES; // Limit to a maximum number of theories
    }

    printf("\nGenerating %d conspiracy theories...\n\n", number_of_theories);

    for (int i = 0; i < number_of_theories; i++) {
        generate_theory(theory);
        printf("Theory %d: %s\n", i + 1, theory);
    }

    printf("\nRemember, the truth is out there!\n");
    return 0;
}