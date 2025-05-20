//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int user_input;
    int computer_input;
    int is_game_continued = 1;
    int score_user = 0;
    int score_computer = 0;

    srand(time(NULL));

    printf("Welcome to the C Table Game!\n\n");
    printf("In this game, you and the computer will take turns choosing a number between 1 and 10.\n");
    printf("The goal is to choose a number that adds up to 21.\n");
    printf("If you go over 21, you lose the round and the other player gets a point. The first player to 5 points wins.\n\n");

    while(is_game_continued){
        printf("Your turn. Choose a number between 1 and 10: ");
        scanf("%d", &user_input);
        
        if(user_input < 1 || user_input > 10){
            printf("Invalid input. Please choose a number between 1 and 10.\n");
            continue;
        }

        computer_input = rand() % 10 + 1;
        printf("The computer chose %d.\n", computer_input);

        if(user_input + computer_input > 21){
            printf("You have gone over 21. Computer wins this round!\n");
            score_computer++;
        }
        else{
            int remaining = 21 - user_input - computer_input;
            printf("The remaining score is %d.\n", remaining);
            int computer_total = rand() % remaining + 1;
            printf("The computer chose %d and the total is %d.\n", computer_total, user_input + computer_input + computer_total);

            if(user_input + computer_input + computer_total > 21){
                printf("Computer wins this round!\n");
                score_computer++;
            }
            else{
                printf("You win this round!\n");
                score_user++;
            }
        }

        printf("Current Score\nUser: %d\tComputer: %d\n", score_user, score_computer);

        if(score_user == 5){
            printf("You win the game!\n");
            is_game_continued = 0;
        }
        else if(score_computer == 5){
            printf("Computer wins the game!\n");
            is_game_continued = 0;
        }
    }

    printf("\nThank you for playing the C Table Game!\n");
    return 0;
}