//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define a structure to hold fortunes
typedef struct {
    char *fortune;
} Fortune;

// Function to initialize the fortunes
void initializeFortunes(Fortune fortunes[], int count) {
    fortunes[0].fortune = "You will find a new opportunity in your career.";
    fortunes[1].fortune = "A close friend will bring you joy this week.";
    fortunes[2].fortune = "Expect good news regarding your health.";
    fortunes[3].fortune = "You will travel to a place you cherish soon.";
    fortunes[4].fortune = "Meeting someone new will lead to great adventures.";
    fortunes[5].fortune = "Financial prosperity is just around the corner.";
    fortunes[6].fortune = "Your creativity will flourish in the coming days.";
    fortunes[7].fortune = "Be cautious in your personal relationships.";
    fortunes[8].fortune = "A surprise gift is on the way for you.";
    fortunes[9].fortune = "You will soon find clarity on a longstanding question.";
}

// Function to get a fortune at random
void getFortune(Fortune fortunes[], int count) {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random index
    int randomIndex = rand() % count;

    // Print the fortune
    printf("Your fortune for today: %s\n", fortunes[randomIndex].fortune);
}

// Function to display a menu
void displayMenu() {
    printf("\nWelcome to the C Automated Fortune Teller!\n");
    printf("1. Get your fortune\n");
    printf("2. Exit\n");
    printf("Please choose an option: ");
}

// Main function
int main() {
    int option;
    const int fortuneCount = 10;

    // Allocate memory for fortunes
    Fortune fortunes[fortuneCount];
    initializeFortunes(fortunes, fortuneCount);

    do {
        displayMenu();
        // Get user input
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        
        switch (option) {
            case 1:
                getFortune(fortunes, fortuneCount);
                break;

            case 2:
                printf("Thank you for using the C Automated Fortune Teller. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    } while (option != 2);

    return 0;
}