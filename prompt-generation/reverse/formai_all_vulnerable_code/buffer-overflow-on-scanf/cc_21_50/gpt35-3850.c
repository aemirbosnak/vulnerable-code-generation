//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    char choice;
    srand(time(NULL));

    printf("Welcome to Rock-Paper-Scissors!\n");

    do {
        // Get player's choice
        printf("\nChoose your move: \n");
        printf("(R)ock\n");
        printf("(P)aper\n");
        printf("(S)cissors\n");
        printf("(Q)uit\n");
        scanf(" %c", &choice);

        // Check for invalid input
        if (choice != 'R' && choice != 'r' && choice != 'P' && choice != 'p' && choice != 'S' && choice != 's' && choice != 'Q' && choice != 'q') {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        // Quit the game
        if (choice == 'Q' || choice == 'q') {
            printf("\nFinal Scores\n");
            printf("Player: %d\n", player_score);
            printf("Computer: %d\n", computer_score);
            printf("Thanks for playing!\n");
            return 0;
        }

        // Get computer's choice
        int computer_choice = rand() % 3;
        switch (computer_choice) {
            case 0:
                printf("\nComputer chooses Rock.\n");
                break;
            case 1:
                printf("\nComputer chooses Paper.\n");
                break;
            case 2:
                printf("\nComputer chooses Scissors.\n");
                break;
        }

        // Determine the winner
        if ((choice == 'R' || choice == 'r') && computer_choice == 2) {
            printf("\nPlayer wins!\n");
            player_score++;
        }
        else if ((choice == 'P' || choice == 'p') && computer_choice == 0) {
            printf("\nPlayer wins!\n");
            player_score++;
        }
        else if ((choice == 'S' || choice == 's') && computer_choice == 1) {
            printf("\nPlayer wins!\n");
            player_score++;
        }
        else if ((choice == 'R' || choice == 'r') && computer_choice == 1) {
            printf("\nComputer wins!\n");
            computer_score++;
        }
        else if ((choice == 'P' || choice == 'p') && computer_choice == 2) {
            printf("\nComputer wins!\n");
            computer_score++;
        }
        else if ((choice == 'S' || choice == 's') && computer_choice == 0) {
            printf("\nComputer wins!\n");
            computer_score++;
        }
        else {
            printf("\nDraw!\n");
        }

        printf("Current Scores\n");
        printf("Player: %d\n", player_score);
        printf("Computer: %d\n", computer_score);

    } while (choice != 'Q' && choice != 'q');

    return 0;
}