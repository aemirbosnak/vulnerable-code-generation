//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, ai_score = 0;
    int player_choice, ai_choice;
    char again;

    srand(time(NULL));

    do {
        printf("Player's score: %d\nAI's score: %d\n", player_score, ai_score);
        printf("Enter your choice (1, 2 or 3): ");
        scanf("%d", &player_choice);

        if (player_choice == 1) {
            printf("You chose rock.\n");
            if (rand() % 2 == 0) {
                printf("AI chose scissors.\n");
                ai_score++;
            } else {
                printf("AI chose paper.\n");
                player_score++;
            }
        } else if (player_choice == 2) {
            printf("You chose paper.\n");
            if (rand() % 2 == 0) {
                printf("AI chose rock.\n");
                player_score++;
            } else {
                printf("AI chose scissors.\n");
                ai_score++;
            }
        } else if (player_choice == 3) {
            printf("You chose scissors.\n");
            if (rand() % 2 == 0) {
                printf("AI chose rock.\n");
                ai_score++;
            } else {
                printf("AI chose paper.\n");
                player_score++;
            }
        } else {
            printf("Invalid choice.\n");
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    if (player_score > ai_score) {
        printf("Congratulations! You won the game.\n");
    } else if (player_score < ai_score) {
        printf("Sorry, you lost the game.\n");
    } else {
        printf("It's a draw.\n");
    }

    return 0;
}