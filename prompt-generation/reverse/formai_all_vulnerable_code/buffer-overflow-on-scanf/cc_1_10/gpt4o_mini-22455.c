//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

// Structure to hold the fortune
typedef struct {
    char *fortuneText;
} Fortune;

// Function prototypes
void initializeFortunes(Fortune *fortunes);
void tellFortune(Fortune *fortunes);
void displayGoodbye();

int main() {
    Fortune fortunes[NUM_FORTUNES];
    srand(time(NULL)); // Seed random number generator
    
    initializeFortunes(fortunes);
    tellFortune(fortunes);
    displayGoodbye();
    
    return 0;
}

// Function to initialize the fortunes
void initializeFortunes(Fortune *fortunes) {
    fortunes[0].fortuneText = "You will find great success in your endeavors.";
    fortunes[1].fortuneText = "A mysterious stranger will soon enter your life.";
    fortunes[2].fortuneText = "Today is a great day to start something new.";
    fortunes[3].fortuneText = "You will receive unexpected news that will delight you.";
    fortunes[4].fortuneText = "Patience is a virtue; your hard work will pay off soon.";
    fortunes[5].fortuneText = "Adventure awaits you; seize the opportunity.";
    fortunes[6].fortuneText = "You will encounter a challenge, but you will overcome it.";
    fortunes[7].fortuneText = "Love is around the corner; keep your heart open.";
    fortunes[8].fortuneText = "Your creativity will shine brightly in the coming days.";
    fortunes[9].fortuneText = "Good fortune is on its way to you; keep your spirits high.";
}

// Function to tell a fortune
void tellFortune(Fortune *fortunes) {
    int choice;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Press 1 to receive your fortune, or 0 to exit: ");
    
    while (1) {
        scanf("%d", &choice);
        
        if (choice == 1) {
            int randomIndex = rand() % NUM_FORTUNES; // Generate random index
            printf("Your fortune is: %s\n", fortunes[randomIndex].fortuneText);
            printf("Would you like to receive another fortune? (1 for yes, 0 for no): ");
        } else if (choice == 0) {
            printf("Thank you for visiting the Automated Fortune Teller. Goodbye!\n");
            break; // Exit the loop and end the program
        } else {
            printf("Invalid choice. Please press 1 to receive a fortune, or 0 to exit: ");
        }
    }
}

// Function to display a goodbye message
void displayGoodbye() {
    printf("Life is full of surprises; embrace them with open arms!\n");
}