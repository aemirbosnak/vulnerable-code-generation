//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 512
#define NUM_THEORIES 10
#define NUM_ELEMENTS 5

const char *agents[] = {
    "The Illuminati",
    "Lizard People",
    "Big Pharma",
    "The Freemasons",
    "Aliens",
    "The Government",
    "Corporate Corporations",
    "Time Travelers",
    "Secret Societies",
    "Artificial Intelligence"
};

const char *events[] = {
    "the moon landing",
    "the assassination of JFK",
    "the COVID-19 pandemic",
    "the stock market crash",
    "the Roswell incident",
    "the construction of the Great Wall of China",
    "the sinking of the Titanic",
    "the invention of the internet",
    "the disappearance of Amelia Earhart",
    "the fall of the Berlin Wall"
};

const char *elements[] = {
    "are orchestrated by",
    "are a cover-up for",
    "are connected to",
    "determine the future of",
    "shape the narrative of",
    "are manipulated by",
    "are evidence of",
    "reveal the truth behind",
    "disguise the intentions of",
    "parallel the rise of"
};

void generate_theory(char *theory) {
    srand(time(0));
    
    // Randomly select components of the theory
    const char *agent = agents[rand() % (sizeof(agents) / sizeof(agents[0]))];
    const char *event = events[rand() % (sizeof(events) / sizeof(events[0]))];
    const char *element = elements[rand() % (sizeof(elements) / sizeof(elements[0]))];
    
    // Formulate the theory
    snprintf(theory, MAX_LENGTH, "\"%s %s %s!\" - A bold statement from the world of conspiracy theories.", event, element, agent);
}

void generate_multiple_theories(int count) {
    char theory[MAX_LENGTH];

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        generate_theory(theory);
        printf("%s\n", theory);
    }
}

int main() {
    int number_of_theories;

    // Get user input
    printf("How many conspiracy theories would you like to generate? ");
    if (scanf("%d", &number_of_theories) != 1 || number_of_theories <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Generate conspiracy theories
    generate_multiple_theories(number_of_theories);

    printf("--------------------------------------------------\n");
    printf("Remember, the truth is out there... or is it?\n");

    return EXIT_SUCCESS;
}