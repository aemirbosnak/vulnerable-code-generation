//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
//Welcome to the ultimate rock-paper-scissors-lizard-spock game!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //initialize variables
    int player_choice, computer_choice, player_score=0, computer_score=0, rounds=0;
    char replay = 'Y';
    srand(time(0));

    printf("Welcome to Rock-Paper-Scissors-Lizard-Spock! Let's play!\n");

    //game loop
    while (replay == 'Y') {
        printf("Round %d\n", rounds+1);

        //player's turn
        printf("Enter your choice:\n");
        printf("1 -> Rock\n2 -> Paper\n3 -> Scissors\n4 -> Lizard\n5 -> Spock\n");
        scanf("%d", &player_choice);

        //computer's turn
        computer_choice = (rand() % 5) + 1;

        //compare choices
        if (player_choice == computer_choice) {
            printf("Tie!\n");
        }
        else if (player_choice == 1) { //rock
            if (computer_choice == 3 || computer_choice == 4) {
                printf("You win!\n");
                player_score++;
            }
            else {
                printf("You lose!\n");
                computer_score++;
            }
        }
        else if (player_choice == 2) { //paper
            if (computer_choice == 1 || computer_choice == 5) {
                printf("You win!\n");
                player_score++;
            }
            else {
                printf("You lose!\n");
                computer_score++;
            }
        }
        else if (player_choice == 3) { //scissors
            if (computer_choice == 2 || computer_choice == 4) {
                printf("You win!\n");
                player_score++;
            }
            else {
                printf("You lose!\n");
                computer_score++;
            }
        }
        else if (player_choice == 4) { //lizard
            if (computer_choice == 2 || computer_choice == 5) {
                printf("You win!\n");
                player_score++;
            }
            else {
                printf("You lose!\n");
                computer_score++;
            }
        }
        else if (player_choice == 5) { //spock
            if (computer_choice == 1 || computer_choice == 3) {
                printf("You win!\n");
                player_score++;
            }
            else {
                printf("You lose!\n");
                computer_score++;
            }
        }
        else {
            printf("Invalid choice. Please enter a number between 1-5.\n");
            continue; //restart current loop
        }

        //display scores
        printf("Player: %d points\tComputer: %d points\n", player_score, computer_score);
        rounds++;

        //ask to play again
        printf("Do you want to play again? (Y/N)\n");
        scanf(" %c", &replay);
    }

    printf("Thanks for playing! Your final score is %d points in %d rounds.\n", player_score, rounds);

    return 0;
}