//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FORTUNES 10

void printGreetings() {
    printf("******************************************\n");
    printf("*********  Welcome to Fortune Teller  *********\n");
    printf("******************************************\n");
    printf("Get ready to unveil your future...\n");
    printf("******************************************\n");
}

void getFortune(char *fortune) {
    const char *fortunes[MAX_FORTUNES] = {
        "You will have a great day today!",
        "A surprise is waiting for you around the corner!",
        "Don't let fear hold you back, take that leap!",
        "An old friend will contact you soon.",
        "Your hard work will pay off very soon.",
        "You will find clarity in a current dilemma.",
        "Love is in the air, keep your eyes open.",
        "A new opportunity is on its way, be ready!",
        "Trust your instincts today, they won't fail you.",
        "Adventure awaits you in the near future!"
    };
    
    srand(time(0));
    int randomIndex = rand() % MAX_FORTUNES;
    strcpy(fortune, fortunes[randomIndex]);
}

void displayFortune(char *fortune) {
    printf("Your fortune says:\n");
    printf("\"%s\"\n", fortune);
}

int main() {
    char fortune[256]; // Buffer to hold the fortune message

    printGreetings(); // Display the greeting message

    // Loop to get user input for fortune telling
    char continueFortune = 'y';
    while (continueFortune == 'y' || continueFortune == 'Y') {
        getFortune(fortune); // Get a random fortune
        displayFortune(fortune); // Display the fortune
        
        printf("Would you like to see another fortune? (y/n): ");
        scanf(" %c", &continueFortune); // Get user input for continuing
    }

    printf("Thank you for visiting the Fortune Teller! Have a magical day!\n");
    return 0;
}