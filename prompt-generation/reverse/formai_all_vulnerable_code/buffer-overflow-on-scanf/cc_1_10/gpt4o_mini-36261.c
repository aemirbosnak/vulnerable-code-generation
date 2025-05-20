//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

// Function declarations
void displayMenu();
int getUserChoice();
void tellFortune(int choice);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    int userChoice;

    // Display the menu and get user choice
    displayMenu();
    userChoice = getUserChoice();
    
    // Process the user's choice and tell their fortune
    tellFortune(userChoice);

    return 0;
}

void displayMenu() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please choose a number between 1 and %d to reveal your fortune:\n", NUM_FORTUNES);
}

int getUserChoice() {
    int choice;
    
    // Get user input
    while (1) {
        printf("Enter your choice (1-%d): ", NUM_FORTUNES);
        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= NUM_FORTUNES) {
            break; // Valid choice
        } else {
            printf("Invalid choice. Please try again.\n");
            // Clear the input buffer
            while(getchar() != '\n');
        }
    }
    
    return choice;
}

void tellFortune(int choice) {
    const char *fortunes[NUM_FORTUNES] = {
        "You will find great success in your endeavors.",
        "A journey of a thousand miles begins with a single step.",
        "You will soon receive some incredible news.",
        "Fortune favors the bold. Be brave!",
        "Your hard work will soon pay off.",
        "Embrace the unknown; it could lead to wondrous things.",
        "A moment of patience can prevent a great disaster.",
        "Happiness is just around the corner; don't miss it!",
        "You will make an unexpected friend soon.",
        "Change is coming; be ready to embrace it."
    };

    // Randomly select a fortune from the list
    int randomFortuneIndex = rand() % NUM_FORTUNES;

    // Display the fortune based on user choice
    printf("\nYour choice: %d\n", choice);
    printf("Your Fortune: %s\n\n", fortunes[randomFortuneIndex]);
}