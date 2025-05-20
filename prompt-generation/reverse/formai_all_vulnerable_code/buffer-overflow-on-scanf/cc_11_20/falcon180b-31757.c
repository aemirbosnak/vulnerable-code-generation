//Falcon-180B DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0, computer_score = 0;
    char choice;
    int number_of_rounds = 0;

    while (1) {
        printf("Round %d\n", ++number_of_rounds);
        printf("Choose rock, paper or scissors: ");
        scanf("%c", &choice);

        int computer_choice = rand() % 3;

        if (computer_choice == 0) {
            printf("Computer chose rock.\n");
        } else if (computer_choice == 1) {
            printf("Computer chose paper.\n");
        } else {
            printf("Computer chose scissors.\n");
        }

        if ((choice == 'r' && computer_choice == 2) ||
            (choice == 'p' && computer_choice == 0) ||
            (choice =='s' && computer_choice == 1)) {
            printf("You win this round!\n");
            player_score++;
        } else if ((choice == 'r' && computer_choice == 0) ||
                   (choice == 'p' && computer_choice == 2) ||
                   (choice =='s' && computer_choice == 1)) {
            printf("Computer wins this round.\n");
            computer_score++;
        } else {
            printf("It's a tie!\n");
        }

        if (player_score == 5 || computer_score == 5) {
            printf("\nGame over! You win!\n");
            break;
        } else if (number_of_rounds == 10) {
            printf("\nGame over! It's a tie.\n");
            break;
        }
    }

    return 0;
}