//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10
#define MAX_CHAR 256

const char *fortunes[NUM_FORTUNES] = {
    "You will find a $20 bill on the ground.",
    "A great opportunity will come your way soon.",
    "You should invest in yourself; education is key.",
    "A friend will offer you unexpected help.",
    "This is a good time to start a new project.",
    "Someone close to you has a secret they want to share.",
    "You will soon have a reunion with a long-lost friend.",
    "Trust your instincts; they will guide you on the right path.",
    "A surprise encounter will lead to happiness.",
    "You will soon be presented with a unique challenge."
};

// Function to display the menu
void displayMenu() {
    printf("Welcome to the C Automated Fortune Teller!\n");
    printf("Please choose an option:\n");
    printf("1. Get a fortune\n");
    printf("2. Learn about fortunes\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
}

// Function to give a random fortune
void tellFortune() {
    srand((unsigned int)time(NULL));
    int index = rand() % NUM_FORTUNES;
    printf("Your fortune: %s\n", fortunes[index]);
}

// Function to display information about fortunes
void displayFortuneInfo() {
    printf("\nFortunes are predictions about the future. They can be:\n");
    printf("- Positive: Indicating luck or good fortune ahead.\n");
    printf("- Cautionary: Advising to be mindful of certain aspects in life.\n");
    printf("- Mysterious: Hinting at future events they can't directly describe.\n");
    printf("\nNo matter what your fortune says, it's always good to remember:\n");
    printf("Your actions influence your future! Create your own luck!\n");
}

// Main function to run the Fortune Teller program
int main() {
    int choice = 0;

    while (choice != 3) {
        displayMenu();

        // Input validation loop
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
            printf("Invalid input. Please enter a number between 1 and 3: ");
            while(getchar() != '\n'); // clear input buffer
        }

        switch (choice) {
            case 1:
                tellFortune();
                break;
            case 2:
                displayFortuneInfo();
                break;
            case 3:
                printf("Thank you for visiting the C Automated Fortune Teller. Goodbye!\n");
                break;
            default:
                // Normally would use a default case, but this shouldn't happen due to checking.
                break;
        }
        printf("\n");
    }

    return 0;
}