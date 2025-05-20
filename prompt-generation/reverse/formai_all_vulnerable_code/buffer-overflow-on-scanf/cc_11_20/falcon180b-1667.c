//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int player_score = 0, computer_score = 0;
    char choice;

    printf("Welcome to the Terminal Game! \n");
    printf("You will be playing against the computer. \n");
    printf("Choose your move: R for Rock, P for Paper, S for Scissors \n");

    while(1) {
        scanf("%c", &choice);

        switch(choice) {
            case 'R':
                printf("You chose Rock! \n");
                int computer_choice = rand() % 3;
                if(computer_choice == 0) {
                    printf("Computer chose Rock! \n");
                    printf("It's a tie! \n");
                }
                else if(computer_choice == 1) {
                    printf("Computer chose Paper! \n");
                    printf("Computer wins! \n");
                    computer_score++;
                }
                else {
                    printf("Computer chose Scissors! \n");
                    printf("You win! \n");
                    player_score++;
                }
                break;

            case 'P':
                printf("You chose Paper! \n");
                computer_choice = rand() % 3;
                if(computer_choice == 0) {
                    printf("Computer chose Rock! \n");
                    printf("You win! \n");
                    player_score++;
                }
                else if(computer_choice == 1) {
                    printf("Computer chose Paper! \n");
                    printf("It's a tie! \n");
                }
                else {
                    printf("Computer chose Scissors! \n");
                    printf("Computer wins! \n");
                    computer_score++;
                }
                break;

            case 'S':
                printf("You chose Scissors! \n");
                computer_choice = rand() % 3;
                if(computer_choice == 0) {
                    printf("Computer chose Rock! \n");
                    printf("Computer wins! \n");
                    computer_score++;
                }
                else if(computer_choice == 1) {
                    printf("Computer chose Paper! \n");
                    printf("You win! \n");
                    player_score++;
                }
                else {
                    printf("Computer chose Scissors! \n");
                    printf("It's a tie! \n");
                }
                break;

            default:
                printf("Invalid move! \n");
        }

        printf("Score: You - %d, Computer - %d \n", player_score, computer_score);

        if(player_score == 5 || computer_score == 5) {
            printf("\nGame over! You win! \n");
            break;
        }
    }

    return 0;
}