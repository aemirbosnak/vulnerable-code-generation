//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_LENGTH 256

const char *subjects[] = {
    "aliens", "the government", "the moon landing", "big corporations",
    "the media", "artificial intelligence", "the vaccine", "climate change",
    "the lizard people", "the flat Earth theory"
};

const char *actions[] = {
    "are controlling", "have hidden", "are secretly funding",
    "are collaborating with", "have brainwashed", "are covering up",
    "are manipulating", "are spying on", "are experimenting on",
    "are distracting us from"
};

const char *goals[] = {
    "a New World Order", "the truth about history", "our minds",
    "the natural order", "the stock market", "global population",
    "our health", "the economy", "technology", "the environment"
};

const char *locations[] = {
    "Area 51", "the Bermuda Triangle", "Antarctica", "the Vatican",
    "Washington D.C.", "Silicon Valley", "Disneyland", "the Amazon rainforest",
    "Roswell", "the underground bases"
};

void generate_conspiracy_theory(char *theory) {
    srand(time(NULL));

    int subject_idx = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int action_idx = rand() % (sizeof(actions) / sizeof(actions[0]));
    int goal_idx = rand() % (sizeof(goals) / sizeof(goals[0]));
    int location_idx = rand() % (sizeof(locations) / sizeof(locations[0]));

    snprintf(theory, MAX_LENGTH, "%s %s %s in %s.",
             subjects[subject_idx], actions[action_idx], 
             goals[goal_idx], locations[location_idx]);
}

void display_conspiracy_theories(int count) {
    for (int i = 0; i < count; i++) {
        char theory[MAX_LENGTH];
        generate_conspiracy_theory(theory);
        printf("Conspiracy Theory %d: %s\n", i + 1, theory);
    }
}

int main() {
    int number_of_theories;

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("How many conspiracy theories would you like to generate? ");
    
    while (1) {
        scanf("%d", &number_of_theories);
        if (number_of_theories > 0 && number_of_theories <= MAX_THEORIES) {
            break;
        } else {
            printf("Please enter a number between 1 and %d: ", MAX_THEORIES);
        }
    }

    display_conspiracy_theories(number_of_theories);

    printf("Stay vigilant!\n");
    return 0;
}