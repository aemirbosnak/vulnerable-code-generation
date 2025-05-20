//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i, j, input;
    int player_position = 0, computer_position = 0;
    int board_size = 100;
    int player_last_score = 0, computer_last_score = 0;
    char player_name[20], computer_name[] = "Computer";
    srand(time(NULL));

    printf("Welcome to the C Table Game!\n\n");
    printf("Enter your name: ");
    scanf("%s", player_name);
    printf("\n%s, get ready to compete against the Computer in a game of luck and strategy!\n\n", player_name);
    printf("The board size is %d.\n", board_size);

    while (player_position < board_size && computer_position < board_size) {

        printf("%s's turn:\n", player_name);
        printf("Press enter to roll the dice...");
        getchar();
        getchar();
        input = rand() % 6 + 1;
        player_last_score = input;
        player_position += input;

        if (player_position >= board_size) {
            printf("%s wins!! Congratulations!!!\n", player_name);
            break;
        }

        printf("%s rolled %d.\n", player_name, input);
        printf("%s's current position: %d\n", player_name, player_position);

        printf("\n%s's turn:\n", computer_name);
        printf("Press enter to roll the dice...");
        getchar();
        input = rand() % 6 + 1;
        computer_last_score = input;
        computer_position += input;

        if (computer_position >= board_size) {
            printf("%s wins!! Better luck next time!\n", computer_name);
            break;
        }

        printf("%s rolled %d.\n", computer_name, input);
        printf("%s's current position: %d\n\n", computer_name, computer_position);    

        if (player_position == computer_position) {
            player_position -= player_last_score;
            computer_position -= computer_last_score;
            printf("It's a tie!! %s and %s both moved back one step.\n\n", player_name, computer_name);
        }

        if (player_position > computer_position) {
            player_position -= computer_last_score;
            printf("%s is in the lead, but %s is catching up!\n\n", player_name, computer_name);
        }

        if (computer_position > player_position) {
            computer_position -= player_last_score;
            printf("%s is in the lead, but %s is catching up!\n\n", computer_name, player_name);
        }
    }

    return 0;
}