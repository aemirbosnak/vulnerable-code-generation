//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 10
#define MAX_LENGTH 200

// Structure to hold parts of conspiracy theories
typedef struct {
    const char *subject;
    const char *action;
    const char *entity;
    const char *motive;
} Conspiracy;

// Predefined conspiracy parts
Conspiracy theories[MAX_THEORIES] = {
    {"Aliens", "are manipulating", "governments", "to control human evolution."},
    {"5G technology", "is a front for", "big corporations", "to monitor our thoughts."},
    {"pigeons", "are actually", "surveillance drones", "created by the NSA."},
    {"moon landings", "were staged by", "NASA", "to distract from Cold War tensions."},
    {"chemtrails", "are used by", "the elite", "for population control."},
    {"the earth", "is flat", "to hide", "the truth about space travel."},
    {"vaccines", "are a tactic", "from pharmaceutical companies", "to generate lifelong profits."},
    {"time travel", "exists but is kept secret by", "the government", "to prevent alternate realities."},
    {"celebrities", "are placed in our lives by", "media moguls", "to steer public opinion."},
    {"the moon", "is a base for", "extraterrestrial beings", "planning an invasion."}
};

// Function to generate a random conspiracy theory
void generate_conspiracy() {
    // Randomize seed
    srand(time(NULL));
    
    // Select random indices
    int index = rand() % MAX_THEORIES;

    // Construct the theory string
    char theory[MAX_LENGTH];
    snprintf(theory, sizeof(theory), "%s %s %s %s", 
             theories[index].subject,
             theories[index].action,
             theories[index].entity,
             theories[index].motive);
    
    // Output the conspiracy theory
    printf("Conspiracy Theory: \"%s\"\n", theory);
}

// Function to display the menu
void display_menu() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("1. Generate a new conspiracy theory\n");
    printf("2. Exit\n");
    printf("Please select an option: ");
}

// Main function
int main() {
    int choice;
    
    // Loop for menu options
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                generate_conspiracy();
                break;
            case 2:
                printf("Exiting the program. Stay curious!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}