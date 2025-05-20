//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10

// Structure to hold individual fortunes
typedef struct {
    char fortune[256];
} Fortune;

// Function prototypes
void initializeFortunes(Fortune fortunes[]);
void displayWelcomeMessage();
void displayMenu();
int getUserChoice();
void tellFortune(Fortune fortunes[]);

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Array to hold fortunes
    Fortune fortunes[MAX_FORTUNES];
    
    // Initialize fortunes
    initializeFortunes(fortunes);
    
    // Display the welcome message
    displayWelcomeMessage();
    
    int choice;
    do {
        displayMenu();
        choice = getUserChoice();
        
        if (choice == 1) {
            tellFortune(fortunes);
        } else if (choice == 2) {
            printf("Thank you for visiting the Automated Fortune Teller. Goodbye!\n");
        } else {
            printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 2);
    
    return 0;
}

// Function to initialize fortunes
void initializeFortunes(Fortune fortunes[]) {
    strcpy(fortunes[0].fortune, "You will encounter great fortune soon.");
    strcpy(fortunes[1].fortune, "A thrilling adventure is in your future.");
    strcpy(fortunes[2].fortune, "You will meet someone special tomorrow.");
    strcpy(fortunes[3].fortune, "Your hard work will pay off in unexpected ways.");
    strcpy(fortunes[4].fortune, "A surprise awaits you this week.");
    strcpy(fortunes[5].fortune, "You will achieve your goals with perseverance.");
    strcpy(fortunes[6].fortune, "A new opportunity will open up for you.");
    strcpy(fortunes[7].fortune, "Trust your instincts, they will lead you.");
    strcpy(fortunes[8].fortune, "Kindness will bring you unexpected rewards.");
    strcpy(fortunes[9].fortune, "An old friend will reconnect with you soon.");
}

// Function to display the welcome message
void displayWelcomeMessage() {
    printf("===================================\n");
    printf("     Automated Fortune Teller      \n");
    printf("===================================\n\n");
}

// Function to display the menu
void displayMenu() {
    printf("Menu:\n");
    printf("1. Tell my fortune\n");
    printf("2. Exit\n");
    printf("Please enter your choice (1-2): ");
}

// Function to get user choice
int getUserChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to tell a fortune
void tellFortune(Fortune fortunes[]) {
    int randomIndex = rand() % MAX_FORTUNES;
    printf("\nYour fortune: %s\n", fortunes[randomIndex].fortune);
    printf("===================================\n\n");
}