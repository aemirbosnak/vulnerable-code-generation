//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const char *subjects[] = {
    "aliens", "the government", "the Illuminati", 
    "big pharmaceuticals", "the media", "tech corporations", 
    "time travelers", "advanced AI", "secret societies", 
    "the moon landing", "9/11", "global warming"
};

const char *actions[] = {
    "control", "monitor", "manipulate", 
    "infiltrate", "disinform", "experiment", 
    "silence", "distract", "influence" 
};

const char *tools[] = {
    "satellites", "social media", "vaccines", 
    "AI algorithms", "genetic modification", "chemtrails", 
    "advanced surveillance", "psychological warfare", 
    "nanotechnology", "artificial food sources"
};

const char *locations[] = {
    "Area 51", "the Bermuda Triangle", "underground bases", 
    "the Vatican", "Silicon Valley", "the Arctic", 
    "the bottom of the ocean", "Mars", "a secret island", 
    "deep space", "a bunker", "the internet"
};

const char *endings[] = {
    "to achieve total control over humanity.", 
    "to manipulate our very reality.",
    "to influence our thoughts and actions unconsciously.",
    "to ensure only their version of truth persists.",
    "to create a world where freedom is an illusion.",
    "to exploit us for their own dark purposes."
};

void generate_theory() {
    int sub_idx = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int act_idx = rand() % (sizeof(actions) / sizeof(actions[0]));
    int tool_idx = rand() % (sizeof(tools) / sizeof(tools[0]));
    int loc_idx = rand() % (sizeof(locations) / sizeof(locations[0]));
    int end_idx = rand() % (sizeof(endings) / sizeof(endings[0]));

    printf("Conspiracy Theory: "
           "The %s use %s to %s the %s in %s %s\n", 
           subjects[sub_idx], tools[tool_idx], actions[act_idx], 
           subjects[sub_idx], locations[loc_idx], endings[end_idx]);
}

int main() {
    srand(time(NULL));
    int num_theories;

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &num_theories);

    if (num_theories <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    for (int i = 0; i < num_theories; i++) {
        generate_theory();
    }

    printf("Thank you for using the Conspiracy Theory Generator!\n");
    return 0;
}