//Falcon-180B DATASET v1.0 Category: Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int valid_choice = 0;
    char play_again;

    do {
        valid_choice = 0;
        printf("Choose your move:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 3) {
            valid_choice = 1;
        } else {
            printf("Invalid choice. Please try again.\n");
        }

    } while(!valid_choice);

    switch(choice) {
        case 1:
            printf("You chose rock.\n");
            if(rand() % 2 == 0) {
                printf("Computer chose paper. Computer wins!\n");
                computer_score++;
            } else {
                printf("Computer chose scissors. You win!\n");
                player_score++;
            }
            break;
        case 2:
            printf("You chose paper.\n");
            if(rand() % 2 == 0) {
                printf("Computer chose rock. Computer wins!\n");
                computer_score++;
            } else {
                printf("Computer chose scissors. You win!\n");
                player_score++;
            }
            break;
        case 3:
            printf("You chose scissors.\n");
            if(rand() % 2 == 0) {
                printf("Computer chose rock. Computer wins!\n");
                computer_score++;
            } else {
                printf("Computer chose paper. You win!\n");
                player_score++;
            }
            break;
    }

    printf("Score: You - %d, Computer - %d\n", player_score, computer_score);
    printf("Do you want to play again? (y/n) ");
    scanf(" %c", &play_again);

    if(play_again == 'y' || play_again == 'Y') {
        main();
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}