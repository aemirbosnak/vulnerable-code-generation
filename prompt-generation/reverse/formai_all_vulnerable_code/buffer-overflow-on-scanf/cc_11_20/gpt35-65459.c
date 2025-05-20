//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_choice;
    int computer_choice;
    int user_wins = 0;
    int computer_wins = 0;
    int ties = 0;

    printf("Welcome to the Rock, Paper, Scissors game!\n");

    while (1) {
        printf("\nWhat would you like to throw?\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n4. Exit game\n");

        scanf("%d", &user_choice);

        if (user_choice == 4) {
            break;
        } else if (user_choice < 1 || user_choice > 3) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        srand(time(NULL));
        computer_choice = rand() % 3 + 1;

        if (user_choice == computer_choice) {
            printf("It's a tie!\n");
            ties++;
        } else if (user_choice == 1 && computer_choice == 2) {
            printf("You lose! Paper covers Rock\n");
            computer_wins++;
        } else if (user_choice == 2 && computer_choice == 3) {
            printf("You lose! Scissors cut Paper\n");
            computer_wins++;
        } else if (user_choice == 3 && computer_choice == 1) {
            printf("You lose! Rock smashes Scissors\n");
            computer_wins++;
        } else {
            printf("You win!\n");

            switch (user_choice) {
                case 1:
                    printf("Rock smashes Scissors\n");
                    break;
                case 2:
                    printf("Paper covers Rock\n");
                    break;
                case 3:
                    printf("Scissors cut Paper\n");
                    break;
            }

            user_wins++;
        }

        printf("\nScore: You %d - %d Computer\n", user_wins, computer_wins);
    }

    printf("\nGame over. Results: You %d - %d Computer with %d tie(s).\n", user_wins, computer_wins, ties);

    return 0;
}