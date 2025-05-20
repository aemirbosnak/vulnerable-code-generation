//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int computer_choice;
    char play_again;

    do {
        printf("Welcome to Rock Paper Scissors!\n");
        printf("Please choose your move: \n1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You chose Rock.\n");
                if(computer_score == 2) {
                    printf("Computer chose Scissors. You win!\n");
                    player_score++;
                } else if(computer_score == 3) {
                    printf("Computer chose Paper. You lose.\n");
                    computer_score++;
                } else {
                    printf("It's a tie!\n");
                }
                break;
            case 2:
                printf("You chose Paper.\n");
                if(computer_score == 1) {
                    printf("Computer chose Rock. You win!\n");
                    player_score++;
                } else if(computer_score == 3) {
                    printf("Computer chose Scissors. You lose.\n");
                    computer_score++;
                } else {
                    printf("It's a tie!\n");
                }
                break;
            case 3:
                printf("You chose Scissors.\n");
                if(computer_score == 1) {
                    printf("Computer chose Rock. You lose.\n");
                    computer_score++;
                } else if(computer_score == 2) {
                    printf("Computer chose Paper. You win!\n");
                    player_score++;
                } else {
                    printf("It's a tie!\n");
                }
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);

        if(player_score == 5 || computer_score == 5) {
            printf("Game over! You won!\n");
        } else if(player_score == -5 || computer_score == -5) {
            printf("Game over! You lost!\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while(play_again == 'y' || play_again == 'Y');

    return 0;
}