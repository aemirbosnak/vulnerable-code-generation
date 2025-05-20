//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int roll_dice();
int calculate_sum(int roll1, int roll2);
int play_game();

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator
    char play_again = 'y';
    int wins = 0, losses = 0;

    while (play_again == 'y') {
        int result = play_game();
        if (result == 1) {
            printf("You win!\n");
            wins++;
        } else {
            printf("You lose!\n");
            losses++;
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);
    }

    printf("Thanks for playing!\n");
    printf("Wins: %d\nLosses: %d\n", wins, losses);

    return 0;
}

// Simulate rolling a 6-sided die
int roll_dice() {
    return rand() % 6 + 1;
}

// Calculate the sum of the two rolls
int calculate_sum(int roll1, int roll2) {
    return roll1 + roll2;
}

// Play one round of the game and return the result (1 for win, 0 for loss)
int play_game() {
    int sum = calculate_sum(roll_dice(), roll_dice());
    printf("You rolled a %d\n", sum);

    switch (sum) {
        case 7:
        case 11:
            return 1;
        case 2:
        case 3:
        case 12:
            return 0;
        default:
            printf("Point is %d\n", sum);
            break;
    }

    int point = sum;
    int new_sum;

    do {
        new_sum = calculate_sum(roll_dice(), roll_dice());
        printf("You rolled a %d\n", new_sum);
        if (new_sum == 7) {
            return 0;
        }
    } while (new_sum != point);

    return 1;
}