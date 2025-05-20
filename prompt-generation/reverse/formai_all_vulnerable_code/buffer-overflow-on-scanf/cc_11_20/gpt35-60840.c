//FormAI DATASET v1.0 Category: Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // setting up random seed
    srand(time(NULL));
    
    // initialize player and computer scores to 0
    int player_score = 0;
    int computer_score = 0;

    // main game loop
    while(1){
        // ask user to choose between rock (0), paper (1) or scissors (2)
        int player_choice;
        printf("Rock (0), Paper (1) or Scissors (2)? ");
        scanf("%d", &player_choice);

        // generate random choice for computer
        int computer_choice = rand() % 3;

        // print out choices
        if(player_choice == 0)
            printf("You chose Rock!\n");
        else if(player_choice == 1)
            printf("You chose Paper!\n");
        else
            printf("You chose Scissors!\n");

        if(computer_choice == 0)
            printf("Computer chose Rock!\n");
        else if(computer_choice == 1)
            printf("Computer chose Paper!\n");
        else
            printf("Computer chose Scissors!\n");

        // determine winner and update scores
        if(player_choice == computer_choice){
            printf("It's a tie!\n");
        }
        else if(player_choice == 0 && computer_choice == 2 ||
                player_choice == 1 && computer_choice == 0 ||
                player_choice == 2 && computer_choice == 1){
            printf("You win!\n");
            player_score++;
        }
        else{
            printf("Computer wins!\n");
            computer_score++;
        }

        // print out current scores
        printf("Score: You %d, Computer %d\n", player_score, computer_score);

        // ask user to play again or exit
        printf("Play again? (y/n) ");
        char play_again;
        scanf(" %c", &play_again);
        if(play_again == 'n')
            break;
    }

    return 0;
}