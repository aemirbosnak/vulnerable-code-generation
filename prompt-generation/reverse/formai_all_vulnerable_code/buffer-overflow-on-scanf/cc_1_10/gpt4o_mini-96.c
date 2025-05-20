//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 5
#define NUM_CATEGORIES 3

// Define Fortune Categories
const char *categories[NUM_CATEGORIES] = {
    "Love",
    "Career",
    "Health"
};

// Fortunes for each category
const char *fortunes[NUM_CATEGORIES][MAX_FORTUNES] = {
    {
        "A new romantic interest will come your way.",
        "Love is in the air, embrace it with an open heart.",
        "Trust your instincts in matters of the heart.",
        "You will form a meaningful connection soon.",
        "True love is on the horizon!"
    },
    {
        "A promotion is in your near future.",
        "Your hard work will soon pay off.",
        "An unexpected opportunity will arise.",
        "Success is just around the corner, keep pushing!",
        "Your creativity will lead you to new heights."
    },
    {
        "Now is a great time to focus on wellness.",
        "Positive changes to your health are coming.",
        "Don't forget to take a break and relax.",
        "Your body will thank you for treating it well.",
        "A new exercise routine will bring great benefits."
    }
};

void displayFortune(int category) {
    srand(time(0));
    int randomIndex = rand() % MAX_FORTUNES; // Get a random fortune
    printf("\nYour fortune: %s\n", fortunes[category][randomIndex]);
}

int main() {
    int choice = -1;

    while (1) {
        printf("\nWelcome to the Shape-Shifting Fortune Teller!\n");
        printf("Choose a category to reveal your fortune:\n");
        
        // Display categories
        for (int i = 0; i < NUM_CATEGORIES; i++) {
            printf("%d. %s\n", i + 1, categories[i]);
        }
        printf("%d. Exit\n", NUM_CATEGORIES + 1);
        
        // Get user input
        printf("Enter your choice (1-%d): ", NUM_CATEGORIES + 1);
        scanf("%d", &choice);

        // Exit condition
        if (choice == NUM_CATEGORIES + 1) {
            printf("Thank you for visiting! May your future be bright!\n");
            break;
        } else if (choice < 1 || choice > NUM_CATEGORIES + 1) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        // Display the chosen fortune
        displayFortune(choice - 1); // Adjust for zero-based index
    }

    return 0;
}