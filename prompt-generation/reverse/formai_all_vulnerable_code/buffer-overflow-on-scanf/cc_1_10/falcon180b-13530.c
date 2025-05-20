//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {
    ROCK = 0,
    PAPER,
    SCISSORS
};

void init() {
    srand(time(NULL));
}

int get_computer_choice() {
    return rand() % 3;
}

char* get_choice_string(int choice) {
    switch (choice) {
        case ROCK:
            return "rock";
        case PAPER:
            return "paper";
        case SCISSORS:
            return "scissors";
        default:
            return "invalid";
    }
}

int main() {
    init();

    int player_score = 0;
    int computer_score = 0;

    while (1) {
        printf("\n");
        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);
        printf("Enter your choice (0 for rock, 1 for paper, 2 for scissors): ");
        int player_choice;
        scanf("%d", &player_choice);

        if (player_choice < 0 || player_choice > 2) {
            printf("Invalid input. Please enter a number between 0 and 2.\n");
            continue;
        }

        int computer_choice = get_computer_choice();

        char* player_choice_string = get_choice_string(player_choice);
        char* computer_choice_string = get_choice_string(computer_choice);

        printf("\n");
        printf("You chose %s\n", player_choice_string);
        printf("Computer chose %s\n", computer_choice_string);

        if (player_choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((player_choice == ROCK && computer_choice == SCISSORS) ||
                   (player_choice == PAPER && computer_choice == ROCK) ||
                   (player_choice == SCISSORS && computer_choice == PAPER)) {
            printf("You win!\n");
            player_score++;
        } else {
            printf("You lose.\n");
            computer_score++;
        }

        printf("\n");
        printf("Press enter to continue... ");
        getchar();
    }

    return 0;
}