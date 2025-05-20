//Falcon-180B DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0, computer_score = 0;
    char choice;

    do {
        printf("Welcome to the energetic game!\n");
        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        scanf("%c", &choice);

        int computer_choice = rand() % 3;

        if (computer_choice == 0) {
            printf("Computer chose rock.\n");
        } else if (computer_choice == 1) {
            printf("Computer chose paper.\n");
        } else {
            printf("Computer chose scissors.\n");
        }

        if (choice == '1' && computer_choice!= 0) {
            printf("You win! Rock beats scissors.\n");
            player_score++;
        } else if (choice == '2' && computer_choice!= 1) {
            printf("You win! Paper beats rock.\n");
            player_score++;
        } else if (choice == '3' && computer_choice!= 2) {
            printf("You win! Scissors beats paper.\n");
            player_score++;
        } else if (computer_choice == 0 && choice!= '1') {
            printf("You lose! Rock beats %c.\n", choice);
            computer_score++;
        } else if (computer_choice == 1 && choice!= '2') {
            printf("You lose! Paper beats %c.\n", choice);
            computer_score++;
        } else if (computer_choice == 2 && choice!= '3') {
            printf("You lose! Scissors beats %c.\n", choice);
            computer_score++;
        } else {
            printf("It's a tie!\n");
        }

        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}