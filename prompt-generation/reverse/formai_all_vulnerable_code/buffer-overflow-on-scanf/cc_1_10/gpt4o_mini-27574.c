//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACIES 10
#define MAX_FACTS 5
#define MAX_CHAR 256

const char *conspiracy_themes[MAX_CONSPIRACIES] = {
    "Intergalactic Banking Cartel",
    "Hollow Earth",
    "Subliminal Messaging in Pop Music",
    "AI Overlords are Controlling Humanity",
    "The Moon Landing was Staged by Hollywood",
    "Lizard People Among Us",
    "Time Travelers in the Shadows",
    "Government Mind Control Programs",
    "Fluoride is a Mind-Control Agent",
    "The Great Reptilian Rebellion"
};

const char *underlying_facts[MAX_FACTS] = {
    "A secret society formed in 1984 to control the world's wealth",
    "Ancient civilizations had advanced technology that was lost",
    "Records show that certain celebrities are actually shape-shifted reptiles",
    "The FDA has approved substances in our food that alter brain functions",
    "Historical documents indicate time portals were discovered in 1967"
};

void generate_conspiracy(char *conspiracy_result) {
    srand(time(NULL));
    int random_theme_index = rand() % MAX_CONSPIRACIES;
    int random_fact_index = rand() % MAX_FACTS;

    snprintf(conspiracy_result, MAX_CHAR, "Conspiracy Theory: %s\nUnderlying Fact: %s\n", 
             conspiracy_themes[random_theme_index], 
             underlying_facts[random_fact_index]);
}

void print_conspiracy(char *conspiracy) {
    printf("*****************************************\n");
    printf("%s", conspiracy);
    printf("*****************************************\n");
}

void user_choice() {
    char choice;
    printf("Would you like to hear another conspiracy theory? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        return;
    } else if (choice == 'n' || choice == 'N') {
        printf("Thank you for exploring the depths of conspiracy with us! Until next time...\n");
        exit(0);
    } else {
        printf("Invalid choice! Please enter 'y' or 'n'.\n");
        user_choice();
    }
}

int main() {
    char conspiracy[MAX_CHAR];

    printf("Welcome to the Mind-Bending Conspiracy Theory Generator!\n");
    
    while (1) {
        generate_conspiracy(conspiracy);
        print_conspiracy(conspiracy);
        user_choice();
    }
    
    return 0;
}