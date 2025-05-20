//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0, choice, result;
    char play_again;
    
    srand(time(0));
    
    do {
        printf("Welcome to the Terminal Based Game!\n\n");
        printf("You will be playing against the computer.\n");
        printf("The game is simple. You and the computer will take turns choosing between rock, paper, or scissors.\n");
        printf("Rock beats scissors, scissors beats paper, and paper beats rock.\n");
        printf("The first one to reach 5 points wins the game.\n\n");
        
        while(1) {
            printf("Your score: %d\nComputer score: %d\n", player_score, computer_score);
            printf("Do you want to play? (y/n): ");
            scanf("%c", &play_again);
            
            if(play_again == 'n') {
                break;
            }
            
            printf("Choose your move (r/p/s): ");
            scanf("%c", &choice);
            
            result = rand() % 3;
            
            if(result == 0) {
                printf("Computer chooses rock.\n");
            }
            else if(result == 1) {
                printf("Computer chooses paper.\n");
            }
            else {
                printf("Computer chooses scissors.\n");
            }
            
            if(choice == 'r' && result!= 1) {
                player_score++;
            }
            else if(choice == 'p' && result!= 0) {
                player_score++;
            }
            else if(choice =='s' && result!= 2) {
                player_score++;
            }
            else {
                computer_score++;
            }
            
            printf("\n");
        }
        
        if(player_score == 5) {
            printf("You win the game!\n");
        }
        else if(computer_score == 5) {
            printf("You lose the game.\n");
        }
        else {
            printf("It's a draw.\n");
        }
        
        printf("Do you want to play again? (y/n): ");
        scanf("%c", &play_again);
    } while(play_again == 'y');
    
    return 0;
}