//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACIES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char *title;
    char *details;
} ConspiracyTheory;

ConspiracyTheory theories[MAX_CONSPIRACIES];
int theory_count = 0;

void initialize_theories() {
    theories[0].title = "The Moon Landing Was Staged";
    theories[0].details = "The moon landing was filmed in a Hollywood basement by NASA and Stanley Kubrick to win the space race.";
    
    theories[1].title = "Lizard People Run the Government";
    theories[1].details = "A race of lizard-like aliens control Earth and are secretly running world governments.";
    
    theories[2].title = "Birds are Government Drones";
    theories[2].details = "All birds are actually drones created by the government to spy on us.";
    
    theories[3].title = "Flat Earth Society";
    theories[3].details = "The world is flat, and governments are part of an elaborate scheme to hide the truth.";
    
    theories[4].title = "The Titanic was Sunk on Purpose";
    theories[4].details = "The Titanic was intentionally sunk to eliminate powerful individuals opposed to the formation of the Federal Reserve.";

    theory_count = 5; // Set the count to the number of initialized theories
}

void print_random_conspiracy() {
    if (theory_count <= 0) {
        printf("No conspiracy theories loaded.\n");
        return;
    }

    // Seed the random number generator
    srand(time(NULL));
    int index = rand() % theory_count;

    printf("** Conspiracy Theory # %d **\n", index + 1);
    printf("Title: %s\n", theories[index].title);
    printf("Details: %s\n\n", theories[index].details);
}

void add_theory(const char *title, const char *details) {
    if (theory_count < MAX_CONSPIRACIES) {
        theories[theory_count].title = strdup(title);
        theories[theory_count].details = strdup(details);
        theory_count++;
    } else {
        printf("Theory limit reached! Cannot add more theories.\n");
    }
}

void free_theories() {
    for (int i = 0; i < theory_count; i++) {
        free(theories[i].title);
        free(theories[i].details);
    }
}

void print_menu() {
    printf("Conspiracy Theory Generator\n");
    printf("1. Print a random conspiracy theory\n");
    printf("2. Add a new conspiracy theory\n");
    printf("3. Exit\n");
}

int main() {
    initialize_theories();

    int choice;
    char title[MAX_LINE_LENGTH];
    char details[MAX_LINE_LENGTH];

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from input buffer
        
        switch (choice) {
            case 1:
                print_random_conspiracy();
                break;
            case 2:
                printf("Enter title of the conspiracy theory: ");
                fgets(title, MAX_LINE_LENGTH, stdin);
                title[strcspn(title, "\n")] = 0;  // Remove newline character

                printf("Enter details of the conspiracy theory: ");
                fgets(details, MAX_LINE_LENGTH, stdin);
                details[strcspn(details, "\n")] = 0;  // Remove newline character
                
                add_theory(title, details);
                printf("New conspiracy theory added!\n\n");
                break;
            case 3:
                free_theories();
                printf("Exiting the program. Stay curious!\n");
                return 0;
            default:
                printf("Invalid choice. Please select again.\n\n");
                break;
        }
    }
    
    return 0;
}