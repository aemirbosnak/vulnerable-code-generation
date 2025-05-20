//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Let's start the fun! Get ready to roll those dice! 🎲
    srand(time(NULL)); // Initialize the random number generator

    // Let's set the stage. How many dice do you want to roll?
    int num_dice;
    printf("Hey there, thrill-seeker! How many dice do you want to roll today? (Enter a number between 1 and 10): ");
    scanf("%d", &num_dice);

    // What kind of dice do you fancy?
    int dice_type;
    printf("Now, let's spice things up! What kind of dice are we playing with? Enter 6 for a classic six-sided die, or 20 for a daring twenty-sided die: ");
    scanf("%d", &dice_type);

    // Time to shake the dice! Let's find out what the dice gods have in store for you...
    int rolls[num_dice]; // Let's store the results of each roll in this nifty array
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = rand() % dice_type + 1; // Roll the dice and save the results
    }

    // Reveal the results! Drumroll please... 🥁
    printf("Ta-da! Here are the results of your epic dice roll:\n");
    for (int i = 0; i < num_dice; i++) {
        printf("Die %d: %d\n", i + 1, rolls[i]); // Display the results of each die
    }

    // Let's add some extra fun! Calculate the total score
    int total = 0;
    for (int i = 0; i < num_dice; i++) {
        total += rolls[i]; // Sum up all the rolls
    }

    // Announce the grand total with a flourish! 🎺
    printf("And the grand total is... *drumroll* %d!\n", total);

    // Feeling lucky? Roll again or quit like a champ!
    char choice;
    printf("Feeling the thrill? Roll again (y/n): ");
    scanf(" %c", &choice); // Capture the user's choice

    if (choice == 'y' || choice == 'Y') {
        // Let's keep the party going!
        main(); // Recursively call the main function to start a new round
    } else {
        // Thank you for playing!
        printf("Thanks for rolling with us! See you next time, dice master!");
    }

    return 0; // Exit the program with style
}