//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// List of fortunes
const char* fortunes[MAX_FORTUNES] = {
    "You will have a great day!",
    "Today is your lucky day!",
    "A surprise awaits you around the corner.",
    "You will find a new friend.",
    "Happiness is headed your way.",
    "Good fortune is coming your way.",
    "An unexpected event will change your life.",
    "You will encounter a challenge but will overcome it.",
    "A small act of kindness will bring you joy.",
    "You are on the right path to your dreams."
};

// Function to get a random fortune
const char* get_random_fortune() {
    int index = rand() % MAX_FORTUNES; // Generate random index
    return fortunes[index]; // Return fortune at chosen index
}

// Function to display menu
void display_menu() {
    printf("Welcome to the C Automated Fortune Teller!\n");
    printf("1. Get a fortune\n");
    printf("2. Exit\n");
}

// Function to get user input
int get_user_choice() {
    int choice;
    printf("Choose an option (1-2): ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice;

    while (1) {
        display_menu(); // Show menu options
        choice = get_user_choice(); // Get user choice

        if (choice == 1) {
            const char* fortune = get_random_fortune(); // Get random fortune
            printf("Your fortune: %s\n\n", fortune); // Display fortune
        } else if (choice == 2) {
            printf("Thank you for using the Fortune Teller! Goodbye!\n");
            break; // Exit the loop
        } else {
            printf("Invalid choice! Please try again.\n\n"); // Handle invalid input
        }
    }

    return 0; // Exit the program successfully
}