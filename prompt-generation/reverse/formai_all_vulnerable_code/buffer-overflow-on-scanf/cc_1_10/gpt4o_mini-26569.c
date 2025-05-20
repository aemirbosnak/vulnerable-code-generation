//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10
#define MAX_INPUT 256

void displayIntroduction() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Enter your name, and let the stars reveal your fortune!\n");
}

void getUserName(char *userName) {
    printf("Please enter your name: ");
    fgets(userName, MAX_INPUT, stdin);
    
    // Remove newline character if present
    userName[strcspn(userName, "\n")] = 0;
}

void displayFortune(const char *userName, const char *fortunes[], int fortuneIndex) {
    printf("%s, here is your fortune: %s\n", userName, fortunes[fortuneIndex]);
}

int main() {
    const char *fortunes[MAX_FORTUNES] = {
        "You will find great happiness very soon.",
        "A new opportunity will arise in your life!",
        "You will meet someone special this week.",
        "Your hard work will be rewarded with a big surprise.",
        "An old friend will contact you, bringing good news.",
        "Trust your instincts; they will lead you to success.",
        "You will encounter a challenge, but you will overcome it!",
        "A journey awaits you that will change your perspective.",
        "Unexpected good fortune is headed your way!",
        "You will discover a new talent that brings you joy."
    };

    char userName[MAX_INPUT];
    srand(time(NULL)); // Seed the random number generator

    displayIntroduction();
    getUserName(userName);
    
    // Get a random fortune
    int fortuneIndex = rand() % MAX_FORTUNES;
    displayFortune(userName, fortunes, fortuneIndex);
    
    // Offer to provide another fortune
    char choice;
    do {
        printf("Would you like to know your fortune again? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y') {
            fortuneIndex = rand() % MAX_FORTUNES;
            displayFortune(userName, fortunes, fortuneIndex);
        } else if (choice != 'n' && choice != 'N') {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
        
    } while (choice != 'n' && choice != 'N');

    printf("Thank you for visiting the Automated Fortune Teller, %s! Have a great day!\n", userName);
    return 0;
}