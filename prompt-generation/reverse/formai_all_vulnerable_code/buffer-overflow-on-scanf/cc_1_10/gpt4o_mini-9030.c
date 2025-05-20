//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_THEORIES 10
#define MAX_FACTORS 5
#define MAX_NAMES 20
#define MAX_TYPES 10
#define BUFFER_SIZE 256

char *agents[MAX_NAMES] = {
    "Illuminati", "lizard people", "aliens", "big corporations", 
    "government officials", "media", "scientists", "your neighbor", 
    "time travelers", "clowns"
};

char *events[MAX_THEORIES] = {
    "the moon landing", "the assassination of JFK", 
    "the COVID-19 pandemic", "climate change", 
    "the disappearance of Amelia Earhart", "Area 51", 
    "9/11", "the sinking of the Titanic", 
    "the 2020 elections", "Roswell incident"
};

char *outcomes[MAX_THEORIES] = {
    "was staged.", "was a cover-up.", 
    "is caused by mind control.", "was orchestrated to distract us.",
    "is part of an alien conspiracy.", "is a social experiment.",
    "was engineered by corporations.", "was a false flag operation.",
    "is a government plot to control the population.", 
    "is connected to secret technologies."
};

char *methods[MAX_THEORIES] = {
    "using advanced technology.", "via subliminal messaging.", 
    "through social media propaganda.", "by altering historical facts.", 
    "through brainwashing the public.", "with fake news.",
    "by manipulating the economy.", "using psychological tactics.",
    "via international collusion.", "through cultural manipulation."
};

char *factors[MAX_FACTORS] = {
    "money", "power", "fear", "knowledge", "control"
};

char *types[MAX_TYPES] = {
    "Political", "Social", "Historical", "Technological", "Environmental"
};

// Function to create a random conspiracy theory
void generate_conspiracy_theory() {
    srand(time(NULL)); // Seed random number generator

    // Randomly select elements from the arrays
    int agent_index = rand() % MAX_NAMES;
    int event_index = rand() % MAX_THEORIES;
    int outcome_index = rand() % MAX_THEORIES;
    int method_index = rand() % MAX_THEORIES;

    // Build the theory string
    char theory[BUFFER_SIZE];
    snprintf(theory, sizeof(theory), 
             "The %s has a hidden truth: it %s Involving the %s. "
             "This is typically achieved %s. What they don’t want you to know is that it revolves around %s.",
             events[event_index], 
             outcomes[outcome_index], 
             agents[agent_index], 
             methods[method_index], 
             factors[rand() % MAX_FACTORS]);

    // Display the theory
    printf("\n[Conspiracy Theory]:\n%s\n", theory);
}

// Function to list categories of conspiracy theories
void list_categories() {
    printf("\n[Conspiracy Theory Categories]:\n");
    for (int i = 0; i < MAX_TYPES; i++) {
        printf("%d. %s\n", i + 1, types[i]);
    }
}

// Function to display the main menu
void display_menu() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("1. Generate a new conspiracy theory\n");
    printf("2. List conspiracy theory categories\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                generate_conspiracy_theory();
                break;
            case 2:
                list_categories();
                break;
            case 3:
                printf("Thank you for using the Random Conspiracy Theory Generator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}