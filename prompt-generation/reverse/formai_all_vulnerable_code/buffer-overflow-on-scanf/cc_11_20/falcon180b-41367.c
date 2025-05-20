//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int player_score = 0;
    int computer_score = 0;

    char choice;
    int number;

    do {
        printf("Choose rock, paper or scissors: ");
        scanf("%c", &choice);

        if (choice!= 'r' && choice!= 'p' && choice!='s') {
            printf("Invalid choice.\n");
            continue;
        }

        if (choice == 'r' || choice =='s') {
            number = rand() % 2;
        } else {
            number = rand() % 3;
        }

        if (number == 0) {
            printf("You chose %c. Computer chose %c.\n", choice, 'r');
            if (choice == 'r') {
                player_score++;
            } else {
                computer_score++;
            }
        } else if (number == 1) {
            printf("You chose %c. Computer chose %c.\n", choice, 'p');
            if (choice == 'p') {
                player_score++;
            } else {
                computer_score++;
            }
        } else {
            printf("You chose %c. Computer chose %c.\n", choice,'s');
            if (choice =='s') {
                player_score++;
            } else {
                computer_score++;
            }
        }

        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);
    } while (player_score!= 5 && computer_score!= 5);

    if (player_score == 5) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    return 0;
}