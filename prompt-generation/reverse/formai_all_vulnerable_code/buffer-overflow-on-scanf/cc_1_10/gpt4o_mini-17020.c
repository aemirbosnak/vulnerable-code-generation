//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 10
#define BUFFER_SIZE 256

const char *actors[] = {
    "lizard people", "aliens", "Illuminati", "the government", 
    "big tech companies", "secret societies", "the media", 
    "time travelers", "psychic octopuses", "AI overlords"
};

const char *actions[] = {
    "control", "manipulate", "monitor", "watch over", 
    "infiltrate", "brainwash", "sabotage", "steal", 
    "erase", "shape the thoughts of"
};

const char *subjects[] = {
    "the weather", "the global financial system", "mankind's consciousness", 
    "our dreams", "the pyramids", "the election results", 
    "the internet", "healthcare", "food supplies", "our children"
};

const char *endings[] = {
    "to establish a new world order.", 
    "in preparation for an upcoming invasion.",
    "to prevent humanity from discovering the truth.",
    "to gain ultimate control over our minds.",
    "because they fear our potential.",
    "to keep us distracted from reality.",
    "to harness the power of the human spirit.",
    "to rewrite history in their favor.",
    "to obscure a hidden agenda.",
    "to maintain their power over the masses."
};

// Function to generate a random conspiracy theory
void generate_theory() {
    srand(time(NULL)); // Seed the random number generator
    int actor_idx = rand() % (sizeof(actors) / sizeof(actors[0]));
    int action_idx = rand() % (sizeof(actions) / sizeof(actions[0]));
    int subject_idx = rand() % (sizeof(subjects) / sizeof(subjects[0]));
    int ending_idx = rand() % (sizeof(endings) / sizeof(endings[0]));

    // Print the theory
    printf("Theory #%d: The %s %s %s %s\n",
           rand() % 1000, 
           actors[actor_idx], 
           actions[action_idx], 
           subjects[subject_idx], 
           endings[ending_idx]);
}

// Main function to run the conspiracy theory generator
int main() {
    int num_theories = 0;

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("How many theories do you want to generate? ");
    scanf("%d", &num_theories);
    
    if (num_theories <= 0 || num_theories > MAX_THEORIES) {
        printf("Please enter a number between 1 and %d.\n", MAX_THEORIES);
        return 1;
    }

    printf("\nGenerating your theories...\n\n");

    for (int i = 0; i < num_theories; i++) {
        generate_theory();
    }

    printf("\nRemember: Not everything is as it seems!\n");
    return 0;
}