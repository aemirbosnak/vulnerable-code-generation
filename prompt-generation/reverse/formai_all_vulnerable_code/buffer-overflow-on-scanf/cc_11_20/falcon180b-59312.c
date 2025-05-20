//Falcon-180B DATASET v1.0 Category: Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, computer_choice;
    char again;
    int score = 0;
    int computer_score = 0;

    do {
        printf("\n\nWelcome to Rock Paper Scissors\n");
        printf("------------------------------------\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("You chose: ");
        if (choice == 1) {
            printf("Rock\n");
        } else if (choice == 2) {
            printf("Paper\n");
        } else if (choice == 3) {
            printf("Scissors\n");
        }

        srand(time(NULL));
        computer_choice = rand() % 3 + 1;

        if (computer_choice == 1) {
            printf("Computer chose: Rock\n");
        } else if (computer_choice == 2) {
            printf("Computer chose: Paper\n");
        } else if (computer_choice == 3) {
            printf("Computer chose: Scissors\n");
        }

        if (choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((choice == 1 && computer_choice == 3) ||
                   (choice == 2 && computer_choice == 1) ||
                   (choice == 3 && computer_choice == 2)) {
            printf("You win!\n");
            score++;
        } else {
            printf("You lose!\n");
            computer_score++;
        }

        printf("Score: You - %d, Computer - %d\n", score, computer_score);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    return 0;
}