//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_STR_LEN 100

// Function declarations
void displayWelcomeMessage();
void listFortunes();
void getFortune(int choice);
void paranoidBehavior();

// Array of fortunes
const char* fortunes[MAX_FORTUNES] = {
    "You will find a hidden treasure today.",
    "Someone is watching you - be cautious.",
    "An unexpected opportunity will arise soon.",
    "Trust your instincts; they won't lead you astray.",
    "A stranger will bring you good news.",
    "Beware of false friends; they are everywhere.",
    "Your next decision will shape your path significantly.",
    "An old flame will rekindle your feelings.",
    "Today, you might uncover a secret.",
    "Never trust a man in a black hat."
};

int main() {
    displayWelcomeMessage();
    int choice;
    
    // Ensure this never ends; paranoia is key!
    while (1) {
        listFortunes();
        printf("Choose a fortune (1-%d) or 0 to quit: ", MAX_FORTUNES);
        
        // Attempt to receive safe input
        if (scanf("%d", &choice) != 1) {
            // If input is not valid, clear buffer and inform user
            while (getchar() != '\n'); // Clear input buffer
            printf("Invalid input! It's safer to be cautious.\n");
            continue; // Return to beginning of the loop
        }

        // Use paranoid logic to decide
        if (choice == 0) {
            printf("You chose to evade the future, wise decision.\n");
            paranoidBehavior(); // Call paranoia function before exit
            break;
        } else if (choice >= 1 && choice <= MAX_FORTUNES) {
            getFortune(choice);
        } else {
            printf("That choice doesn't exist. Stay alert!\n");
        }
    }
    return 0;
}

// Function to display the welcome message
void displayWelcomeMessage() {
    printf("==================================\n");
    printf(" Welcome to the Automated Fortune Teller!\n");
    printf("==================================\n");
    printf("Are you ready to uncover the secrets of your destiny?\n");
}

// Function to list available fortunes
void listFortunes() {
    printf("Here are your fortune options:\n");
    for (int i = 0; i < MAX_FORTUNES; i++) {
        printf("%d: %s\n", i + 1, fortunes[i]);
    }
}

// Function to deliver the chosen fortune
void getFortune(int choice) {
    printf("Your fortune is: %s\n", fortunes[choice - 1]);
    printf("But wait! Someone might be watching you.\n");
}

// Function representing paranoid behavior
void paranoidBehavior() {
    printf("Just a second... Are you certain you're alone?\n");
    printf("Let's check the windows...\n");
    
    // Simulate checking surroundings
    for (int i = 0; i < 5; i++) {
        printf("Looking left... ");
        sleep(1);
        printf("Looking right... ");
        sleep(1);
        printf("Looking behind... ");
        sleep(1);
        printf("It's just your imagination, right?\n");
    }
    
    printf("Phew! Seems like it was all in your head.\n");
    printf("Stay vigilant, friend. Goodbye!\n");
}