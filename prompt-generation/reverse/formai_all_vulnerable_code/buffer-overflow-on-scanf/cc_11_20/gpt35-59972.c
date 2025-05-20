//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    // initialize variables to store the player and computer scores and the number of rounds played
    int player_score = 0;
    int computer_score = 0;
    int rounds_played = 0;
    
    // seed random number generator with current time
    srand(time(NULL));

    // display welcome message and game rules
    printf("Welcome to the Rock Paper Scissors game!\n");
    printf("In this game, you will be playing against the computer.\n");
    printf("Rock beats scissors, scissors beats paper, and paper beats rock.\n");
    printf("The first player to reach 3 points wins.\n");

    // keep playing until one player wins 3 rounds
    while (player_score < 3 && computer_score < 3) {
        // increment round counter
        rounds_played++;

        // get player's choice
        printf("Round %d, what do you choose? (1 = rock, 2 = paper, 3 = scissors): ", rounds_played);
        int player_choice;
        scanf("%d", &player_choice);

        // generate computer's choice
        int computer_choice = rand() % 3 + 1;
        printf("The computer chooses %d.\n", computer_choice);

        // compare choices and update scores
        if (player_choice == computer_choice) {
            printf("Round %d is a tie!\n", rounds_played);
        } else if ((player_choice == 1 && computer_choice == 3) ||
                 (player_choice == 2 && computer_choice == 1) ||
                 (player_choice == 3 && computer_choice == 2)) {
            printf("You win round %d!\n", rounds_played);
            player_score++;
        } else {
            printf("The computer wins round %d!\n", rounds_played);
            computer_score++;
        }

        // display current scores
        printf("Current score: Player %d - %d Computer\n\n", player_score, computer_score);
    }

    // determine winner and display message
    if (player_score > computer_score) {
        printf("Congratulations, you win the game!");
    } else {
        printf("Sorry, the computer wins the game. Better luck next time!");
    }

    return 0;
}