//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_THEORIES 10
#define MAX_LENGTH 256

const char *suspects[] = {
    "aliens", "the government", "the Illuminati", "killer robots", 
    "big corporations", "the lizard people", "time travelers", 
    "flat earthers", "secret societies", "the media"
};

const char *events[] = {
    "the moon landing", "the COVID-19 pandemic", 
    "climate change", "9/11", "the assassination of JFK", 
    "the sinking of Titanic", "the Roswell incident",
    "the Y2K bug", "the rise of social media", "the Great Depression"
};

const char *locations[] = {
    "Area 51", "the Bermuda Triangle", "the North Pole", 
    "the Vatican", "the White House", "Hollywood", 
    "the ancient pyramids", "the bottom of the ocean", 
    "the Amazon rainforest", "the dark side of the moon"
};

const char *methods[] = {
    "using mind control", "through subliminal messaging", 
    "with advanced technology", "by manipulating the weather", 
    "via secret codes", "through financial manipulation", 
    "by using paid actors", "with hidden cameras", 
    "through time loops", "by spreading misinformation"
};

void generate_conspiracy_theory(char *theory) {
    char *suspect = suspects[rand() % (sizeof(suspects) / sizeof(suspects[0]))];
    char *event = events[rand() % (sizeof(events) / sizeof(events[0]))];
    char *location = locations[rand() % (sizeof(locations) / sizeof(locations[0]))];
    char *method = methods[rand() % (sizeof(methods) / sizeof(methods[0]))];

    snprintf(theory, MAX_LENGTH, 
        "Theory: %s is covering up %s through %s at %s.",
        suspect, event, method, location);
}

int main() {
    char theory[MAX_LENGTH];
    int number_of_theories;

    srand(time(NULL)); // Seed the random number generator

    printf("Enter the number of conspiracy theories to generate (1 - %d): ", NUM_THEORIES);
    scanf("%d", &number_of_theories);

    if (number_of_theories < 1 || number_of_theories > NUM_THEORIES) {
        printf("Please enter a valid number between 1 and %d.\n", NUM_THEORIES);
        return 1;
    }

    printf("\nGenerating %d conspiracy theories...\n\n", number_of_theories);

    for (int i = 0; i < number_of_theories; i++) {
        generate_conspiracy_theory(theory);
        printf("%d. %s\n", i + 1, theory);
    }

    printf("\nRemember: The truth is out there, but so are the lies!\n");
    return 0;
}