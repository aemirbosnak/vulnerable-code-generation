//FormAI DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declare global variables
int player_score = 0;
int computer_score = 0;

//function to generate random choice for the computer
int generate_random_choice() {
    srand(time(NULL));
    int num = rand() % 3;
    return num;
}

//function to get player's choice
int get_player_choice() {
    int choice;
    printf("Enter 1 for Rock, 2 for Paper, 3 for Scissors\n");
    scanf("%d", &choice);
    return choice;
}

//function to compare choices and determine the winner
void compare_choices(int player_choice, int computer_choice) {
    if (player_choice == computer_choice) {
        printf("It's a tie!");
    }
    else if (player_choice == 1 && computer_choice == 2) {
        printf("You lose! Paper beats Rock.");
        computer_score++;
    }
    else if (player_choice == 1 && computer_choice == 3) {
        printf("You win! Rock beats Scissors.");
        player_score++;
    }
    else if (player_choice == 2 && computer_choice == 1) {
        printf("You win! Paper beats Rock.");
        player_score++;
    }
    else if (player_choice == 2 && computer_choice == 3) {
        printf("You lose! Scissors beats Paper.");
        computer_score++;
    }
    else if (player_choice == 3 && computer_choice == 1) {
        printf("You lose! Rock beats Scissors.");
        computer_score++;
    }
    else if (player_choice == 3 && computer_choice == 2) {
        printf("You win! Scissors beats Paper.");
        player_score++;
    }
}

//function to display score
void display_score() {
    printf("\nPlayer score: %d | Computer score: %d\n\n", player_score, computer_score);
}

//main function
int main() {
    int player_choice;
    int computer_choice;
    char play_again = 'y';

    printf("Welcome to Rock-Paper-Scissors!\n");

    while (play_again == 'y') {
        player_choice = get_player_choice();
        computer_choice = generate_random_choice();
        compare_choices(player_choice, computer_choice);
        display_score();
        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &play_again);
    }

    return 0;
}