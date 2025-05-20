//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare function to generate random number between min and max (inclusive)
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // declare and initialize array with possible fortunes
    char fortunes[10][100] = {
        "You will receive good news soon.",
        "The best is yet to come.",
        "Don't worry, be happy.",
        "Your dreams will come true.",
        "You will be successful in all your endeavors.",
        "An opportunity will arise that you should take.",
        "You are capable of achieving greatness.",
        "A new chapter in your life will begin soon.",
        "Keep your head high and everything will fall into place.",
        "Strength will be your biggest asset in the coming days."
    };

    // get user's name
    printf("Welcome to the Automated Fortune Teller! What is your name?\n");
    char name[20];
    scanf("%s", name);

    // generate random fortune for user
    int fortuneIndex = randomNumber(0, 9);
    char fortune[100];
    sprintf(fortune, "%s, your fortune today is: %s", name, fortunes[fortuneIndex]);
    printf("%s\n", fortune);

    // prompt user to play again
    printf("Would you like to play again? (y/n)\n");
    char playAgain[2];
    scanf("%s", playAgain);

    // continue playing until user says no
    while (playAgain[0] == 'y') {
        // generate new fortune for user
        fortuneIndex = randomNumber(0, 9);
        sprintf(fortune, "%s, your fortune today is: %s", name, fortunes[fortuneIndex]);
        printf("%s\n", fortune);

        // prompt user to play again
        printf("Would you like to play again? (y/n)\n");
        scanf("%s", playAgain);
    }

    return 0;
}