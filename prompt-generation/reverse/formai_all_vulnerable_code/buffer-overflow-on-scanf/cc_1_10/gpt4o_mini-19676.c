//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// A collection of fortunes
const char *fortunes[MAX_FORTUNES] = {
    "You will stumble upon a great opportunity today.",
    "Beware of unexpected encounters this week.",
    "Your talents will be recognized very soon.",
    "A pleasant surprise is waiting for you around the corner.",
    "A new friend will come into your life unexpectedly.",
    "Fortune favors the brave. Take a leap of faith.",
    "You're closer to your dreams than you think.",
    "A journey of a thousand miles begins with a single step.",
    "Today is the day to embrace change.",
    "You will discover something profound about yourself."
};

// Function to draw the fortune
void drawFortune() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random index
    int index = rand() % MAX_FORTUNES;

    // Display the fortune
    printf("\n✨✨✨ Your Fortune Awaits! ✨✨✨\n");
    printf("Behold:\n");
    printf("\"%s\"\n", fortunes[index]);
    printf("✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨\n");
}

// Function to display the artistic introduction
void displayIntro() {
    printf("*********************************\n");
    printf("*       Fortune Teller App      *\n");
    printf("*********************************\n");
    printf("*  Gaze into the mystical world  *\n");
    printf("*  of possibilities and hopes!   *\n");
    printf("*********************************\n");
    printf("\n");
}

int main() {
    char input;

    // Display the introduction
    displayIntro();

    do {
        drawFortune();

        // Prompt for another fortune or exit
        printf("Would you like to know your fortune? (y/n): ");
        scanf(" %c", &input);
        
        // Input validation
        while (input != 'y' && input != 'n') {
            printf("Please enter 'y' for yes or 'n' for no: ");
            scanf(" %c", &input);
        }

    } while (input == 'y');

    printf("Thank you for visiting the Fortune Teller. Until next time!\n");
    return 0;
}