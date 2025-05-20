//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define SIDES 6

// Function to roll a single die
int roll_die() {
    return rand() % SIDES + 1;
}

// Function to roll multiple dice and return the total
int roll_dice() {
    int total = 0;
    for (int i = 0; i < NUM_DICE; i++) {
        total += roll_die();
    }
    return total;
}

// Function to determine the outcome of a roll based on a threshold
char determine_outcome(int threshold, int roll) {
    if (roll >= threshold) {
        return 'S';
    } else {
        return 'F';
    }
}

// Function to play a game of chance
void game_of_chance() {
    int threshold;
    int player_roll;
    int dealer_roll;
    char outcome;

    printf("Welcome to the Game of Chance!\n");
    printf("Please enter your threshold (1-6): ");
    scanf("%d", &threshold);

    player_roll = roll_dice();
    dealer_roll = roll_dice();

    outcome = determine_outcome(threshold, player_roll);
    if (outcome == 'S') {
        printf("You win!\n");
    } else {
        printf("You lose.\n");
    }

    outcome = determine_outcome(threshold, dealer_roll);
    if (outcome == 'S') {
        printf("Dealer wins.\n");
    } else {
        printf("Dealer loses.\n");
    }
}

int main() {
    srand(time(NULL));

    game_of_chance();

    return 0;
}