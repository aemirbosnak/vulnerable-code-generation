//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

#define WIN 1
#define LOSE -1
#define DRAW 0

int main() {
    int player_choice, computer_choice;
    int result;

    srand(time(NULL)); // seed the random number generator

    printf("Welcome to Rock-Paper-Scissors! \n");

    do {
        printf("Player, choose your move: (rock, paper, or scissors) ");
        scanf("%d", &player_choice);

        computer_choice = get_computer_move(); // get the computer's move

        result = compare_moves(player_choice, computer_choice);

        if (result == WIN) {
            printf("Player wins! \n");
        } else if (result == LOSE) {
            printf("Computer wins! \n");
        } else {
            printf("It's a draw! \n");
        }
    } while (1);

    return 0;
}

int get_computer_move() {
    int move;
    int random_number = rand() % 3; // generate a random number between 1 and 3

    if (random_number == 1) {
        move = ROCK;
    } else if (random_number == 2) {
        move = PAPER;
    } else {
        move = SCISSORS;
    }

    return move;
}

int compare_moves(int player_move, int computer_move) {
    int result;

    if (player_move == computer_move) {
        result = DRAW;
    } else if (player_move == ROCK && computer_move == SCISSORS) {
        result = WIN; // player wins
    } else if (player_move == PAPER && computer_move == ROCK) {
        result = WIN; // player wins
    } else {
        result = LOSE; // computer wins
    }

    return result;
}