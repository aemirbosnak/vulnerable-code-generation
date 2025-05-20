//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 100
#define MAX_PROBABILITY 100

// Structure to represent an alien
typedef struct {
    char name[30];
    int probability; // Probability of invasion in percentage
    int has_spaceship; // Whether the alien has a spaceship or not
} Alien;

// Function to simulate an alien invasion
void invade_the_earth(Alien alien) {
    if (alien.has_spaceship) {
        printf("%s the Alien comes in a shiny spaceship and declares: 'We come in peace!' Right before they invade!\n", alien.name);
    } else {
        printf("%s the Alien, without a spaceship, simply walks over asking for directions while invading!\n", alien.name);
    }
}

// Function to calculate total invasion probability
int calculate_invasion_probability(Alien aliens[], int total_aliens) {
    int total_probability = 0;
    
    for (int i = 0; i < total_aliens; ++i) {
        total_probability += aliens[i].probability;
    }
    
    return total_probability / total_aliens;
}

// Display aliens
void display_aliens(Alien aliens[], int total_aliens) {
    printf("\nMeet the Aliens ready to invade:\n");
    for (int i = 0; i < total_aliens; ++i) {
        printf("%s: Invasion Probability - %d%%, Has Spaceship? - %s\n", 
            aliens[i].name, 
            aliens[i].probability, 
            aliens[i].has_spaceship ? "Yes" : "No");
    }
}

// Function to randomly assign probabilities to aliens
void populate_aliens(Alien aliens[], int total_aliens) {
    char *alien_names[] = {
        "Zorg", "Blip", "Flibbertigibbet", "Wobble", "Squee",
        "Zizzle", "Gloop", "Nibble", "Dabble", "Plink"
    };
    
    srand(time(NULL));

    for (int i = 0; i < total_aliens; ++i) {
        aliens[i].probability = rand() % MAX_PROBABILITY + 1; // Random probability from 1% to 100%
        aliens[i].has_spaceship = rand() % 2; // Randomly decide if they have a spaceship
        snprintf(aliens[i].name, sizeof(aliens[i].name), "%s-%d", alien_names[rand() % 10], i + 1);
    }
}

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Where we calculate just how likely it is that you’ll become an alien’s lunch!\n\n");

    int total_aliens = rand() % MAX_ALIENS + 1; // Random number of aliens
    Alien aliens[MAX_ALIENS];
    
    populate_aliens(aliens, total_aliens);
    
    display_aliens(aliens, total_aliens);
    
    int overall_probability = calculate_invasion_probability(aliens, total_aliens);
    
    printf("\nThe overall invasion probability is: %d%%\n", overall_probability);
    
    if (overall_probability > 50) {
        printf("Warning! Looks like it's time to stock up on baked beans and prepare for the worst!\n");
    } else {
        printf("Congratulations! It seems like you'll get to enjoy your snacks in peace... for now!\n");
    }
    
    printf("\nSELECT YOUR FATE:\n");
    printf("1. Run away and scream!\n");
    printf("2. Organize a strategic negotiation with the aliens.\n");
    printf("3. Offer them a slice of pizza (who can resist that?)\n");
    printf("What do you choose? (Enter 1, 2, or 3): ");
    
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("You run away like a chicken!\n");
            break;
        case 2:
            printf("You bravely approach and try to negotiate, but the aliens just look confused.\n");
            break;
        case 3:
            printf("You offer them pizza and they throw a party on your lawn! Alien karaoke ensues!\n");
            break;
        default:
            printf("You decided to just sit there. Great strategy! Now you’re part of the menu!\n");
    }
    
    printf("\nThank you for playing the Alien Invasion Probability Calculator!\n");
    return 0;
}