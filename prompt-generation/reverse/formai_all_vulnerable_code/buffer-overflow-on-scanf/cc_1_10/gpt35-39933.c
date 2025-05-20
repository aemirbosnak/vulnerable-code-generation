//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: optimized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void print_header() {
    printf("***************************\n");
    printf("* Random Conspiracy Theory *\n");
    printf("***************************\n\n");
}

void generate_theory() {
    const char* subjects[] = {
        "Government",
        "Aliens",
        "Illuminati",
        "Big Pharma",
        "Social Media",
        "Media",
        "Food Industry",
        "Education System",
        "Technology",
        "Religion",
    };
    const char* actions[] = {
        "is controlling",
        "is manipulating",
        "is hiding",
        "is creating",
        "is funding",
        "is brainwashing",
        "is suppressing",
        "is influencing",
        "is sabotaging",
    };
    const char* consequences[] = {
        "our minds",
        "our society",
        "our health",
        "our environment",
        "our economy",
        "our future",
        "our politics",
        "our freedom",
        "our creativity",
    };

    int subject_index = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int action_index = rand() % (sizeof(actions) / sizeof(actions[0]));
    int consequences_index = rand() % (sizeof(consequences) / sizeof(consequences[0]));

    printf("Did you know that the %s %s %s?\n", subjects[subject_index], actions[action_index], consequences[consequences_index]);
}

int main() {
    srand(time(NULL));
    int num_of_theories;

    print_header();

    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &num_of_theories);

    for (int i = 0; i < num_of_theories; i++) {
        generate_theory();
    }

    return 0;
}