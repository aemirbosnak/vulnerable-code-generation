//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 5
#define MAX_CLUES 10

// Structure to store guest information
typedef struct {
    char name[50];
    char description[50];
    int arrived_time;
    int departed_time;
} guest_t;

// Structure to store clue information
typedef struct {
    char description[50];
    int discovered_time;
    int discovered_by;
} clue_t;

// Global variables
guest_t guests[MAX_GUESTS];
clue_t clues[MAX_CLUES];
int num_guests = 0;
int num_clues = 0;
int current_guest = 0;
int current_clue = 0;

// Function to print the game menu
void print_menu() {
    printf("Welcome to the Mystery Game!\n");
    printf("Select a guest to question: ");
    for (int i = 0; i < MAX_GUESTS; i++) {
        printf("%d. %s\n", i + 1, guests[i].name);
    }
    printf("Select a clue to investigate: ");
    for (int i = 0; i < MAX_CLUES; i++) {
        printf("%d. %s\n", i + 1, clues[i].description);
    }
}

// Function to question a guest
void question_guest() {
    int choice;

    printf("You question the guest...\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_guests) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    current_guest = choice - 1;

    // Print the guest's response
    printf("The guest responds: %s\n", guests[current_guest].description);
}

// Function to investigate a clue
void investigate_clue() {
    int choice;

    printf("You investigate the clue...\n");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_clues) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    current_clue = choice - 1;

    // Print the clue's information
    printf("The clue is: %s\n", clues[current_clue].description);
}

int main() {
    srand(time(NULL));

    // Initialize the guest and clue structures
    for (int i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].description[0] = '\0';
        guests[i].arrived_time = rand() % 1000 + 1;
        guests[i].departed_time = guests[i].arrived_time + rand() % 1000 + 1;
    }

    for (int i = 0; i < MAX_CLUES; i++) {
        clues[i].description[0] = '\0';
        clues[i].discovered_time = rand() % 1000 + 1;
        clues[i].discovered_by = -1;
    }

    num_guests = rand() % 5 + 1;
    num_clues = rand() % 10 + 1;

    // Print the game menu
    print_menu();

    while (1) {
        // Question a guest
        question_guest();

        // Investigate a clue
        investigate_clue();

        // Check if the game is over
        if (current_guest == num_guests && current_clue == num_clues) {
            printf("Congratulations, you have solved the mystery!\n");
            break;
        }
    }

    return 0;
}