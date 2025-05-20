//Falcon-180B DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int player_score = 0;
    int computer_score = 0;
    int choice;
    char play_again;

    do {
        printf("Player's turn:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Player chooses Rock.\n");
                if(rand()%3 == 0) {
                    printf("Computer chooses Rock.\n");
                    computer_score++;
                } else if(rand()%3 == 1) {
                    printf("Computer chooses Paper.\n");
                    player_score++;
                } else {
                    printf("Computer chooses Scissors.\n");
                }
                break;
            case 2:
                printf("Player chooses Paper.\n");
                if(rand()%3 == 0) {
                    printf("Computer chooses Rock.\n");
                    player_score++;
                } else if(rand()%3 == 1) {
                    printf("Computer chooses Paper.\n");
                } else {
                    printf("Computer chooses Scissors.\n");
                    computer_score++;
                }
                break;
            case 3:
                printf("Player chooses Scissors.\n");
                if(rand()%3 == 0) {
                    printf("Computer chooses Rock.\n");
                    computer_score++;
                } else if(rand()%3 == 1) {
                    printf("Computer chooses Paper.\n");
                    player_score++;
                } else {
                    printf("Computer chooses Scissors.\n");
                }
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }

        printf("Player's score: %d\n", player_score);
        printf("Computer's score: %d\n", computer_score);

        if(player_score == 5 || computer_score == 5) {
            printf("Game over! Player wins!\n");
        } else if(player_score == 0 || computer_score == 0) {
            printf("Game over! Computer wins!\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while(play_again == 'y' || play_again == 'Y');

    return 0;
}