//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0, computer_score = 0;
    char choice;

    do {
        printf("Player's turn:\n");
        printf("Enter your choice (r/p/s): ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'r':
                printf("You chose rock.\n");
                if (rand() % 2 == 0) {
                    printf("Computer chose scissors.\n");
                    computer_score++;
                } else {
                    printf("Computer chose paper.\n");
                    player_score++;
                }
                break;
            case 'p':
                printf("You chose paper.\n");
                if (rand() % 2 == 0) {
                    printf("Computer chose rock.\n");
                    computer_score++;
                } else {
                    printf("Computer chose scissors.\n");
                    player_score++;
                }
                break;
            case's':
                printf("You chose scissors.\n");
                if (rand() % 2 == 0) {
                    printf("Computer chose paper.\n");
                    computer_score++;
                } else {
                    printf("Computer chose rock.\n");
                    player_score++;
                }
                break;
            default:
                printf("Invalid input. Try again.\n");
        }
        printf("\nPlayer score: %d\n", player_score);
        printf("Computer score: %d\n\n", computer_score);
    } while (player_score!= 5 && computer_score!= 5);

    if (player_score == 5) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    return 0;
}