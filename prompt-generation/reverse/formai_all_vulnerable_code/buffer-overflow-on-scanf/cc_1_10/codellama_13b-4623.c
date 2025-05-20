//Code Llama-13B DATASET v1.0 Category: Game ; Style: standalone
// A simple game in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

// Function prototypes
void game_intro();
void game_menu();
void game_start();
void game_play();
void game_end();

// Global variables
int player_score = 0;
int computer_score = 0;
int num_of_rounds = 0;

int main() {
    game_intro();
    game_menu();
    game_start();
    game_play();
    game_end();
    return 0;
}

void game_intro() {
    printf("Welcome to the C Game!\n");
    printf("This is a simple game of rock, paper, scissors.\n");
    printf("You will play against the computer.\n");
}

void game_menu() {
    printf("Enter '1' to start a new game.\n");
    printf("Enter '2' to view the rules.\n");
    printf("Enter '3' to quit the game.\n");
    printf("Please enter your choice: ");
}

void game_start() {
    num_of_rounds = 0;
    player_score = 0;
    computer_score = 0;
    printf("A new game has started!\n");
}

void game_play() {
    char player_move[10];
    char computer_move;
    while (num_of_rounds < 5) {
        printf("Enter your move (rock, paper, or scissors): ");
        scanf("%s", player_move);
        computer_move = rand() % 3 + 1;
        if (computer_move == 1) {
            computer_move = 'r';
        } else if (computer_move == 2) {
            computer_move = 'p';
        } else {
            computer_move = 's';
        }
        if (player_move[0] == computer_move) {
            printf("It's a tie!\n");
        } else if ((player_move[0] == 'r' && computer_move == 's') || (player_move[0] == 'p' && computer_move == 'r') || (player_move[0] == 's' && computer_move == 'p')) {
            printf("You win this round!\n");
            player_score++;
        } else {
            printf("You lose this round!\n");
            computer_score++;
        }
        num_of_rounds++;
    }
}

void game_end() {
    printf("Game over!\n");
    printf("Your score: %d\n", player_score);
    printf("Computer score: %d\n", computer_score);
    if (player_score > computer_score) {
        printf("You win the game!\n");
    } else {
        printf("The computer wins the game!\n");
    }
}