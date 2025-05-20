//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed
    srand(time(0));

    // Define variables
    int player_points = 0;
    int computer_points = 0;
    int turn_sum = 0;
    char player_choice = '\0';
    char computer_choice = '\0';
    int computer_turn_counter = 0;
    int max_turns = 5;

    // Display welcome message
    printf("Welcome to the Point Race game!\n");
    printf("You will have %d turns to accumulate as many points as possible.\n", max_turns);

    // Game loop
    for (int i = 0; i < max_turns; i++) {
        printf("\n--------------------\n");
        printf("Turn %d\n", i+1);

        // Player's turn
        printf("Player's turn:\n");
        printf("Press 'r' to roll the dice.\n");
        while (player_choice != 'r') {
            scanf(" %c", &player_choice);
        }
        int dice_roll = rand() % 6 + 1;
        printf("You rolled a %d!\n", dice_roll);
        if (dice_roll == 1) {
            printf("You lose all your points for this turn.\n");
            turn_sum = 0;
            player_points -= turn_sum;
            player_choice = '\0';
            continue;
        }
        turn_sum += dice_roll;
        printf("Your turn sum is %d.\n", turn_sum);

        // Computer's turn
        printf("Computer's turn:\n");
        computer_turn_counter = 0;
        while (turn_sum <= 20 && computer_turn_counter < 3) {
            dice_roll = rand() % 6 + 1;
            printf("The computer rolled a %d!\n", dice_roll);
            if (dice_roll == 1) {
                printf("The computer loses all their points for this turn.\n");
                turn_sum = 0;
                computer_points -= turn_sum;
                computer_choice = '\0';
                break;
            }
            turn_sum += dice_roll;
            computer_turn_counter++;
        }

        // Determine winner of turn
        if (turn_sum > 20) {
            printf("Turn sum exceeds 20! No points awarded this turn.\n");
        }
        else {
            printf("Turn sum is %d.\n", turn_sum);
            player_choice = '\0';
            computer_choice = '\0';
            if (turn_sum > 0) {
                player_points += turn_sum;
                printf("Player gains %d points for this turn!\n", turn_sum);
            }
            turn_sum = 0;
        }
    }

    // Display final score
    printf("\n--------------------\n");
    printf("Game over!\n");
    printf("Final scores:\n");
    printf("Player: %d\n", player_points);
    printf("Computer: %d\n", computer_points);

    // Determine winner of game
    if (player_points > computer_points) {
        printf("Player wins!");
    }
    else if (computer_points > player_points) {
        printf("Computer wins!");
    }
    else {
        printf("It's a tie!");
    }

    return 0;
}