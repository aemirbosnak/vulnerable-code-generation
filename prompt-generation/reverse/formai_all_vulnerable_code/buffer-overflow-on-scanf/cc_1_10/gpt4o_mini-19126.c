//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// Function prototypes
void displayWelcomeMessage();
void displayFortunes(char fortunes[][255], int count);
int getUserChoice();
void generateRandomFortune(char fortunes[][255], int count);
void cleanup();

int main() {
    srand(time(0)); // Seed for random number generation

    // Array of fortunes
    char fortunes[MAX_FORTUNES][255] = {
        "You will find a great opportunity ahead.",
        "Expect a surprise visit from an old friend.",
        "A new adventure is coming your way.",
        "You will find love in an unexpected place.",
        "Your hard work will soon pay off.",
        "A mysterious figure will bring you good luck.",
        "Travel is in your future.",
        "Maintain a positive attitude to attract positivity.",
        "You will be recognized for your unique talents.",
        "An unexpected financial opportunity will arise."
    };

    // Display welcome message
    displayWelcomeMessage();

    // Main loop
    int userChoice;
    do {
        // Display all fortunes
        displayFortunes(fortunes, MAX_FORTUNES);
        
        // Ask user for their choice
        userChoice = getUserChoice();

        if (userChoice > 0 && userChoice <= MAX_FORTUNES) {
            printf("Your fortune: %s\n\n", fortunes[userChoice - 1]);
        } else if (userChoice == 0) {
            // Generate a random fortune
            generateRandomFortune(fortunes, MAX_FORTUNES);
        } else if (userChoice > MAX_FORTUNES) {
            printf("Please choose a correct option.\n\n");
        }

    } while (userChoice != -1);

    // Cleanup and exit
    cleanup();
    return 0;
}

// Function to display the welcome message
void displayWelcomeMessage() {
    printf("Welcome to the C Automated Fortune Teller!\n");
    printf("Read carefully and choose a fortune.\n");
    printf("Select a number from 1 to %d for a specific fortune,\n", MAX_FORTUNES);
    printf("or press 0 to receive a random fortune.\n");
    printf("Press -1 to exit the program.\n\n");
}

// Function to display available fortunes
void displayFortunes(char fortunes[][255], int count) {
    printf("Available Fortunes:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, fortunes[i]);
    }
    printf("\n");
}

// Function to get user choice
int getUserChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to generate and display a random fortune
void generateRandomFortune(char fortunes[][255], int count) {
    int randomIndex = rand() % count; // Get random index
    printf("Your random fortune: %s\n\n", fortunes[randomIndex]);
}

// Cleanup function to end the program gracefully
void cleanup() {
    printf("Thank you for visiting the Fortune Teller! Goodbye!\n");
}