//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_message(char* message) {
    printf("%s\n", message);
}

int main() {
    srand(time(NULL));  // Seed random number generator
    char* game_over_message = "Game Over";
    char* player_won_message = "You Won!";
    char* rock = "rock";
    char* paper = "paper";
    char* scissors = "scissors";

    print_message("Rock, Paper, Scissors!");

    int player_choice;
    printf("Enter your choice (rock, paper or scissors): ");
    scanf("%d", &player_choice);

    if (player_choice == 1) {
        player_choice = "rock";
    } else if (player_choice == 2) {
        player_choice = "paper";
    } else if (player_choice == 3) {
        player_choice = "scissors";
    } else {
        print_message("Invalid choice!");
        return 1;
    }

    int computer_choice = rand() % 3;
    if (computer_choice == 0) {
        computer_choice = "rock";
    } else if (computer_choice == 1) {
        computer_choice = "paper";
    } else if (computer_choice == 2) {
        computer_choice = "scissors";
    } else {
        printf("Oops, something went wrong!");
        return 1;
    }

    print_message("Computer chooses: ");
    printf("%s\n", computer_choice);

    if (strcmp(player_choice, computer_choice) == 0) {
        print_message("It's a tie!");
    } else if (strcmp(player_choice, "rock") == 0 && strcmp(computer_choice, "paper") == 0) {
        print_message("You lose!");
    } else if (strcmp(player_choice, "paper") == 0 && strcmp(computer_choice, "scissors") == 0) {
        print_message("You win!");
    } else if (strcmp(player_choice, "scissors") == 0 && strcmp(computer_choice, "rock") == 0) {
        print_message("You win!");
    } else {
        print_message("You lose!");
    }

    return 0;
}