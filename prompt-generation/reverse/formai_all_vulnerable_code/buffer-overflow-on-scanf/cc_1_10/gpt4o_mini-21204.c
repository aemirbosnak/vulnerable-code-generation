//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACIES 10
#define MAX_LENGTH 256

const char *conspiracyTheories[MAX_CONSPIRACIES] = {
    "Aliens are hiding inside Mount Rushmore, controlling the minds of tourists.",
    "Birds are just government surveillance drones that recharge on power lines.",
    "The moon landing was faked by a secret society of lizards.",
    "Time travel exists, and the government is manipulating history.",
    "Carrots were genetically engineered to make you believe in false nutrition.",
    "All major hurricanes are created by a top-secret weather modification program.",
    "Dinosaurs never existed; they were simply a cover for government experiments.",
    "The internet is a tool for aliens to gather data about human behavior.",
    "There's a secret underground city run by sentient AI controlling our decisions.",
    "The Great Wall of China is actually a giant radar system for detecting invaders."
};

const char *locations[] = {
    "Area 51", "the Bermuda Triangle", "the Vatican", "Antarctica", 
    "the Amazon rainforest", "the Sahara desert", "the lost city of Atlantis",
    "Stonehenge", "Mount Everest", "the hollow Earth"
};

const char *secretOrganizations[] = {
    "the Illuminati", "the Freemasons", "Lizard People", 
    "the Trilateral Commission", "the Skull and Bones",
    "Rothschild family", "the Knights Templar"
};

const char *timeouts[] = {
    "soon", "by 2025", "before the next election", 
    "within the next year", "on the next full moon",
    "before the end of the decade", "any day now", "this month"
};

char *generate_conspiracy() {
    char *conspiracy = malloc(MAX_LENGTH);
    if (conspiracy == NULL) {
        return NULL; // malloc failed
    }

    snprintf(conspiracy, MAX_LENGTH, 
             "%s In %s, %s will happen. Be prepared!",
             conspiracyTheories[rand() % MAX_CONSPIRACIES], 
             locations[rand() % (sizeof(locations) / sizeof(locations[0]))],
             timeouts[rand() % (sizeof(timeouts) / sizeof(timeouts[0]))]);

    return conspiracy;
}

int main() {
    srand(time(NULL));
    int conspiracy_count;
    
    printf("Enter the number of conspiracy theories to generate (1-%d): ", MAX_CONSPIRACIES);
    scanf("%d", &conspiracy_count);
    
    if (conspiracy_count < 1 || conspiracy_count > MAX_CONSPIRACIES) {
        printf("Please enter a valid number between 1 and %d.\n", MAX_CONSPIRACIES);
        return 1;
    }

    printf("\nGenerating %d Random Conspiracy Theories:\n", conspiracy_count);
    for (int i = 0; i < conspiracy_count; i++) {
        char *conspiracy = generate_conspiracy();
        if (conspiracy) {
            printf("Theory %d: %s\n", i + 1, conspiracy);
            free(conspiracy);
        } else {
            printf("Failed to generate conspiracy theory #%d\n", i + 1);
        }
    }

    return 0;
}