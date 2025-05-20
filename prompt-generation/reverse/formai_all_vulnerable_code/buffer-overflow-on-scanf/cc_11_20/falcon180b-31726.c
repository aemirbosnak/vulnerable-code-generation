//Falcon-180B DATASET v1.0 Category: Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0, computer_score = 0, choice, result;
    char play_again;

    do {
        printf("Welcome to the peaceful game of Rock, Paper, Scissors!\n");
        printf("Please choose your move: \n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You chose Rock.\n");
                if(rand() % 2 == 0) {
                    printf("Computer chose Scissors.\n");
                    result = 1;
                } else {
                    printf("Computer chose Paper.\n");
                    result = 2;
                }
                break;
            case 2:
                printf("You chose Paper.\n");
                if(rand() % 2 == 0) {
                    printf("Computer chose Rock.\n");
                    result = 2;
                } else {
                    printf("Computer chose Scissors.\n");
                    result = 1;
                }
                break;
            case 3:
                printf("You chose Scissors.\n");
                if(rand() % 2 == 0) {
                    printf("Computer chose Paper.\n");
                    result = 1;
                } else {
                    printf("Computer chose Rock.\n");
                    result = 2;
                }
                break;
            default:
                printf("Invalid move. Please choose again.\n");
                continue;
        }

        if(result == 1) {
            printf("You won!\n");
            player_score++;
        } else if(result == 2) {
            printf("You lost.\n");
            computer_score++;
        } else {
            printf("It's a tie.\n");
        }

        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);

        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &play_again);
    } while(play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing! Final score: You - %d, Computer - %d\n", player_score, computer_score);

    return 0;
}