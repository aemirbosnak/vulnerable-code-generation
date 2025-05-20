//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FACTS 10
#define MAX_PREDICTIONS 10

// Structure to hold fortunes
typedef struct {
    char *fact;
    char *prediction;
} Fortune;

// Array of fortunes
Fortune fortunes[MAX_FACTS];

// Function prototypes
void initializeFortunes();
void displayMenu();
void getRandomFortune();
int getUserChoice();

int main() {
    // Initialize random number generator
    srand(time(NULL));
    // Initialize the fortunes
    initializeFortunes();

    int choice;
    do {
        displayMenu();
        choice = getUserChoice();
        switch (choice) {
            case 1:
                getRandomFortune();
                break;
            case 2:
                printf("Thank you for using the Automated Fortune Teller!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

// Function to initialize fortunes
void initializeFortunes() {
    fortunes[0].fact = "You are a curious learner.";
    fortunes[0].prediction = "Today will bring new knowledge.";
    
    fortunes[1].fact = "A friend will bring you joy.";
    fortunes[1].prediction = "Expect a wonderful surprise soon.";
    
    fortunes[2].fact = "Change is coming your way.";
    fortunes[2].prediction = "Embrace it and grow.";
    
    fortunes[3].fact = "An opportunity will arise.";
    fortunes[3].prediction = "Take a leap of faith.";
    
    fortunes[4].fact = "Your kindness will be rewarded.";
    fortunes[4].prediction = "A gesture of goodwill will come back to you.";
    
    fortunes[5].fact = "You have the power to create.";
    fortunes[5].prediction = "Unleash your creativity today.";
    
    fortunes[6].fact = "It's time to reflect on past decisions.";
    fortunes[6].prediction = "Clarity will emerge from your thoughts.";
    
    fortunes[7].fact = "You have a natural talent.";
    fortunes[7].prediction = "Cultivate it and share with the world.";
    
    fortunes[8].fact = "Trust your intuition.";
    fortunes[8].prediction = "It will guide you today.";
    
    fortunes[9].fact = "The universe is on your side.";
    fortunes[9].prediction = "Expect positive outcomes.";
}

// Function to display the menu
void displayMenu() {
    printf("\nWelcome to the Automated Fortune Teller!\n");
    printf("1. Get a fortune\n");
    printf("2. Exit\n");
    printf("Please choose an option: ");
}

// Function to get user's choice
int getUserChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to get and display a random fortune
void getRandomFortune() {
    int randomIndex = rand() % MAX_FACTS;
    printf("\nHere is your fortune:\n");
    printf("Fact: %s\n", fortunes[randomIndex].fact);
    printf("Prediction: %s\n", fortunes[randomIndex].prediction);
}