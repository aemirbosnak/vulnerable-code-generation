//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number for the fortune
int generateFortuneNumber() {
    srand(time(NULL));
    return rand() % 10;
}

int main() {
    // array of fortunes
    char* fortunes[10] = {
        "You will find a new friend in the future",
        "Your hard work will pay off soon",
        "The stars are aligned in your favor",
        "Opportunities will present themselves to you",
        "A surprise is in store for you",
        "Your future is bright",
        "Good things will come your way",
        "You will meet a mysterious stranger",
        "You will find success in your endeavors",
        "Expect the unexpected"
    };

    // generate random number and display corresponding fortune
    int fortuneNumber = generateFortuneNumber();
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Your fortune for today is: %s\n", fortunes[fortuneNumber]);

    // ask user if they want another fortune
    char choice;
    printf("Would you like another fortune? (Y/N)\n");
    scanf(" %c", &choice);

    // loop until user enters a valid choice
    while (choice != 'Y' && choice != 'N') {
        printf("Please enter a valid choice (Y/N)\n");
        scanf(" %c", &choice);
    }

    // provide another fortune or exit program
    if (choice == 'Y') {
        fortuneNumber = generateFortuneNumber();
        printf("\nYour new fortune is: %s\n", fortunes[fortuneNumber]);
    } else {
        printf("\nThank you for using the Automated Fortune Teller! Goodbye!\n");
    }

    return 0;
}