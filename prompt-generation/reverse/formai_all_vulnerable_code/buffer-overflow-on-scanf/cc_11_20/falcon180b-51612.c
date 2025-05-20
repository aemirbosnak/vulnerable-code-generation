//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0, computer_score = 0, choice, result;
    char play_again;

    do {
        printf("Welcome to the Rock Paper Scissors game!\n");
        printf("Player score: %d\n", player_score);
        printf("Computer score: %d\n", computer_score);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You chose rock.\n");
                result = rand() % 3;
                if(result == 0) {
                    printf("Computer chose scissors.\n");
                    computer_score++;
                }
                else if(result == 1) {
                    printf("Computer chose paper.\n");
                    player_score++;
                }
                else {
                    printf("Computer chose rock.\n");
                }
                break;
            case 2:
                printf("You chose paper.\n");
                result = rand() % 3;
                if(result == 0) {
                    printf("Computer chose rock.\n");
                    computer_score++;
                }
                else if(result == 1) {
                    printf("Computer chose scissors.\n");
                    player_score++;
                }
                else {
                    printf("Computer chose paper.\n");
                }
                break;
            case 3:
                printf("You chose scissors.\n");
                result = rand() % 3;
                if(result == 0) {
                    printf("Computer chose rock.\n");
                    computer_score++;
                }
                else if(result == 1) {
                    printf("Computer chose paper.\n");
                    player_score++;
                }
                else {
                    printf("Computer chose scissors.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        if(player_score == 5 || computer_score == 5) {
            printf("Game over! Player score: %d - Computer score: %d\n", player_score, computer_score);
        }
        else {
            printf("Do you want to play again? (y/n) ");
            scanf(" %c", &play_again);
        }
    } while(play_again == 'y' || play_again == 'Y');

    return 0;
}