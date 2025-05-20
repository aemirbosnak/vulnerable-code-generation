//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_SUBJECTS 5
#define NUM_ACTIONS 5
#define NUM_RESULTS 5
#define MAX_CONSPIRACY_LENGTH 256

const char *subjects[NUM_SUBJECTS] = {
    "aliens",
    "government agencies",
    "big tech corporations",
    "the Illuminati",
    "the royal family"
};

const char *actions[NUM_ACTIONS] = {
    "are secretly controlling",
    "have developed advanced technology to",
    "are hiding evidence of",
    "are creating false narratives about",
    "use mind control to influence"
};

const char *results[NUM_RESULTS] = {
    "a new world order.",
    "the disappearance of several prominent figures.",
    "the manipulation of global weather patterns.",
    "the secrets of immortality.",
    "the truth behind historical events."
};

void generate_random_conspiracy(char *conspiracy) {
    int subject_index = rand() % NUM_SUBJECTS;
    int action_index = rand() % NUM_ACTIONS;
    int result_index = rand() % NUM_RESULTS;

    snprintf(conspiracy, MAX_CONSPIRACY_LENGTH, "%s %s %s", 
             subjects[subject_index], 
             actions[action_index],
             results[result_index]);
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    char conspiracy[MAX_CONSPIRACY_LENGTH];
    int number_of_conspiracies;

    printf("Enter the number of conspiracy theories to generate: ");
    scanf("%d", &number_of_conspiracies);

    if (number_of_conspiracies < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("\nGenerating %d conspiracy theories...\n\n", number_of_conspiracies);

    for (int i = 0; i < number_of_conspiracies; i++) {
        generate_random_conspiracy(conspiracy);
        printf("Conspiracy Theory %d: %s\n", i + 1, conspiracy);
    }

    printf("\nRemember: The truth is out there... or is it?\n");
    
    return 0;
}