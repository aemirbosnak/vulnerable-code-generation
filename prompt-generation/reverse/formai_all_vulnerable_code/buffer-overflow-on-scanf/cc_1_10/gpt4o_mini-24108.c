//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 256
#define NUM_THEORIES 10
#define NUM_ELEMENTS 5

const char *elements[NUM_ELEMENTS] = {
    "aliens", 
    "big corporations", 
    "the government", 
    "the illuminati", 
    "social media"
};

const char *actions[NUM_THEORIES] = {
    "control", 
    "monitor", 
    "manipulate", 
    "brainwash", 
    "infiltrate", 
    "distract", 
    "influence", 
    "destroy", 
    "analyze", 
    "create"
};

const char *adjectives[NUM_THEORIES] = {
    "secret", 
    "hidden", 
    "mysterious", 
    "sophisticated", 
    "dangerous", 
    "ancient", 
    "divine", 
    "terrifying", 
    "unseen", 
    "ultimate"
};

// Function to generate a random conspiracy theory
void generate_conspiracy_theory(char *buffer) {
    int element_index = rand() % NUM_ELEMENTS;
    int action_index = rand() % NUM_THEORIES;
    int adjective_index = rand() % NUM_THEORIES;

    snprintf(buffer, MAX_LENGTH, 
             "Conspiracy Theory: The %s %s %s with %s to control us all.", 
             elements[element_index], 
             actions[action_index], 
             adjectives[adjective_index],
             elements[rand() % NUM_ELEMENTS]);
}

int main() {
    char theory[MAX_LENGTH];
    int theory_count;

    srand(time(NULL));

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("How many conspiracy theories do you want to generate? ");
    scanf("%d", &theory_count);

    if(theory_count <= 0) {
        printf("You must generate at least one conspiracy theory!\n");
        return 1;
    }

    printf("\nGenerating %d Conspiracy Theories...\n", theory_count);

    for(int i = 0; i < theory_count; i++) {
        generate_conspiracy_theory(theory);
        printf("%d: %s\n", i + 1, theory);
    }

    printf("\nRemember, this is all just a simulation! Stay curious.\n");
    return 0;
}