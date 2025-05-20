//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>

// Function to simulate rolling a six-sided dice
int roll_dice() {
    int result = (rand() % 6) + 1;
    return result;
}

// Function to compare the result of rolling the dice to the user's bet
void compare_dice(int dice, int bet) {
    if (dice == bet) {
        printf("It's a tie!\n");
    } else if (dice > bet) {
        printf("You lose!\n");
    } else {
        printf("You win!\n");
    }
}

// Function to check the user's bet
int check_bet(int bet) {
    int result = (rand() % 2) + 1;
    if (result == 0) {
        return 0; // Even number
    } else {
        return 1; // Odd number
    }
}

// Function to print the outcome of the game to the console
void print_outcome(int result) {
    if (result == 0) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}

// Main function
int main() {
    int dice;
    int bet;
    int outcome;

    // Get the user's bet
    printf("Enter your bet: ");
    scanf("%d", &bet);

    // Roll the dice
    dice = roll_dice();

    // Compare the result of the dice roll to the user's bet
    compare_dice(dice, bet);

    // Check the outcome of the bet
    outcome = check_bet(bet);

    // Print the outcome of the game to the console
    print_outcome(outcome);

    return 0;
}