//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    int choice;
    char play_again;

    do {
        printf("Welcome to the Terminal Based Game!\n");
        printf("You will be playing against the computer.\n");
        printf("Choose an option:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You chose rock.\n");
                if(rand() % 2 == 0) {
                    printf("Computer chose scissors.\n");
                    computer_score++;
                } else {
                    printf("Computer chose paper.\n");
                    player_score++;
                }
                break;
            case 2:
                printf("You chose paper.\n");
                if(rand() % 2 == 0) {
                    printf("Computer chose rock.\n");
                    computer_score++;
                } else {
                    printf("Computer chose scissors.\n");
                    player_score++;
                }
                break;
            case 3:
                printf("You chose scissors.\n");
                if(rand() % 2 == 0) {
                    printf("Computer chose paper.\n");
                    computer_score++;
                } else {
                    printf("Computer chose rock.\n");
                    player_score++;
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Score:\nYou: %d\nComputer: %d\n", player_score, computer_score);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while(play_again == 'y' || play_again == 'Y');

    return 0;
}