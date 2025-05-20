//Falcon-180B DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    int choice;
    char play_again;

    do {
        printf("Welcome to the Happy Game!\n");
        printf("You will play against the computer.\n");
        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        scanf("%d", &choice);

        if (choice == 1) {
            int computer_choice = rand() % 3;
            if (computer_choice == 0) {
                printf("Computer chose Rock. It's a tie!\n");
            } else if (computer_choice == 1) {
                printf("Computer chose Paper. You lose!\n");
                computer_score++;
            } else {
                printf("Computer chose Scissors. You win!\n");
                player_score++;
            }
        } else if (choice == 2) {
            int computer_choice = rand() % 3;
            if (computer_choice == 0) {
                printf("Computer chose Rock. You lose!\n");
                computer_score++;
            } else if (computer_choice == 1) {
                printf("Computer chose Paper. It's a tie!\n");
            } else {
                printf("Computer chose Scissors. You win!\n");
                player_score++;
            }
        } else if (choice == 3) {
            int computer_choice = rand() % 3;
            if (computer_choice == 0) {
                printf("Computer chose Rock. You win!\n");
                player_score++;
            } else if (computer_choice == 1) {
                printf("Computer chose Paper. You lose!\n");
                computer_score++;
            } else {
                printf("Computer chose Scissors. It's a tie!\n");
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    if (player_score > computer_score) {
        printf("Congratulations! You won the game.\n");
    } else if (computer_score > player_score) {
        printf("Sorry, you lost the game.\n");
    } else {
        printf("It's a tie.\n");
    }

    return 0;
}