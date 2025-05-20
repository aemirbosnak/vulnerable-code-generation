//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    char choice;
    int player_choice, computer_choice;
    int flag = 0;

    printf("Welcome to the game of Love.\n");
    printf("You will be playing against the computer.\n");
    printf("The choices are Rock, Paper and Scissors.\n");
    printf("Rock beats Scissors, Paper beats Rock and Scissors beats Paper.\n");

    while(1){
        srand(time(NULL));
        computer_choice = rand() % 3;

        if(computer_choice == 0){
            printf("Computer chose Rock.\n");
        }
        else if(computer_choice == 1){
            printf("Computer chose Paper.\n");
        }
        else{
            printf("Computer chose Scissors.\n");
        }

        printf("Enter your choice: ");
        scanf("%d", &player_choice);

        if(player_choice == computer_choice){
            printf("It's a tie.\n");
        }
        else if((player_choice == 0 && computer_choice == 1) || (player_choice == 1 && computer_choice == 0)){
            printf("You win this round.\n");
            player_score++;
        }
        else{
            printf("You lose this round.\n");
            computer_score++;
        }

        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);

        if(player_score == 5){
            printf("You have won the game of Love.\n");
            break;
        }
        else if(computer_score == 5){
            printf("You have lost the game of Love.\n");
            break;
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);

        if(choice == 'n'){
            break;
        }
    }

    return 0;
}