//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define NUM_THEORIES 5
#define NUM_FACTORS 7
#define NUM_LOCATIONS 5

const char *theories[NUM_THEORIES] = {
    "The Moon landing was faked by Hollywood.",
    "Birds are actually surveillance drones created by the government.",
    "Aliens are controlling our thoughts through remote brainwashing.",
    "The Earth is flat and maintained by a secret society.",
    "Time travel is real, and we are already being visited by future humans."
};

const char *factors[NUM_FACTORS] = {
    "to distract us from economic collapse.",
    "to conceal the truth about extraterrestrial life.",
    "to test our reactions to misinformation.",
    "to control the masses through fear and confusion.",
    "to enable a new world order.",
    "to harvest our emotions as energy.",
    "to manipulate weather patterns."
};

const char *locations[NUM_LOCATIONS] = {
    "Area 51 in Nevada.",
    "The Bermuda Triangle.",
    "A remote island in the Pacific Ocean.",
    "The basement of the Vatican.",
    "The abandoned city of Atlantis."
};

void generate_theory(char *output) {
    int theory_index = rand() % NUM_THEORIES;
    int factor_index = rand() % NUM_FACTORS;
    int location_index = rand() % NUM_LOCATIONS;
    
    snprintf(output, MAX_LENGTH, "Conspiracy Theory: %s %s This takes place at %s.", 
             theories[theory_index], factors[factor_index], locations[location_index]);
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    char theory_output[MAX_LENGTH];
    
    int number_of_theories;
    printf("Enter the number of conspiracy theories to generate: ");
    scanf("%d", &number_of_theories);
    
    if (number_of_theories < 1 || number_of_theories > 10) {
        printf("Please enter a number between 1 and 10.\n");
        return 1;
    }
    
    printf("\nGenerated Conspiracy Theories:\n");
    for (int i = 0; i < number_of_theories; ++i) {
        generate_theory(theory_output);
        printf("%d. %s\n", i + 1, theory_output);
    }
    
    return 0;
}