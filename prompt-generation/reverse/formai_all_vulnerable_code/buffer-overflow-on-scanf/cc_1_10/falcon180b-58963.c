//Falcon-180B DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void play_game(void);
int get_valid_input(char *message);
int roll_dice(void);

int main(void) {
    int choice;
    int player_score = 0;
    int computer_score = 0;

    srand(time(NULL));

    printf("Welcome to the Paranoid Style Game!\n");
    printf("You will play against the computer.\n");
    printf("The goal is to reach a score of 7 before the computer does.\n");
    printf("But be careful! The computer is watching your every move...\n\n");

    while (player_score < 7 && computer_score < 7) {
        printf("Your score: %d\n", player_score);
        printf("Computer's score: %d\n\n", computer_score);

        choice = get_valid_input("Press 1 to roll the dice or 0 to pass your turn: ");

        if (choice == 1) {
            player_score += roll_dice();
            printf("You rolled a %d and your new score is %d!\n\n", roll_dice(), player_score);

            if (player_score >= 7) {
                printf("Congratulations! You won the game!\n");
                break;
            }
        } else {
            computer_score += roll_dice();
            printf("The computer rolled a %d and its new score is %d!\n\n", roll_dice(), computer_score);

            if (computer_score >= 7) {
                printf("Oh no! The computer won the game!\n");
                break;
            }
        }
    }

    return 0;
}

void play_game(void) {
    // Game logic goes here
}

int get_valid_input(char *message) {
    int input;

    while (1) {
        printf("%s", message);
        scanf("%d", &input);

        if (input == 0 || input == 1) {
            return input;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

int roll_dice(void) {
    return rand() % 6 + 1;
}