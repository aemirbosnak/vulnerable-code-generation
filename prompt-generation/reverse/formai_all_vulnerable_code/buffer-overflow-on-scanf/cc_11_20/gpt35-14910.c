//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int computer_score = 0, player_score = 0;
    srand(time(NULL));

    while (1) {
        int computer_choice = rand() % 3 + 1;
        int player_choice;

        printf("Enter your choice:\n1 for Rock\n2 for Paper\n3 for Scissors\n");
        scanf("%d", &player_choice);

        switch(player_choice) {
            case 1: // Player chooses Rock
                if (computer_choice == 1) {
                    printf("Computer chooses Rock:\nIt's a tie!\n");
                } else if (computer_choice == 2) {
                    printf("Computer chooses Paper:\nComputer wins this round!\n");
                    computer_score++;
                } else {
                    printf("Computer chooses Scissors:\nYou win this round!\n");
                    player_score++;
                }
                break;
            case 2: // Player chooses Paper
                if (computer_choice == 1) {
                    printf("Computer chooses Rock:\nYou win this round!\n");
                    player_score++;
                } else if (computer_choice == 2) {
                    printf("Computer chooses Paper:\nIt's a tie!\n");
                } else {
                    printf("Computer chooses Scissors:\nComputer wins this round!\n");
                    computer_score++;
                }
                break;
            case 3: // Player chooses Scissors
                if (computer_choice == 1) {
                    printf("Computer chooses Rock:\nComputer wins this round!\n");
                    computer_score++;
                } else if (computer_choice == 2) {
                    printf("Computer chooses Paper:\nYou win this round!\n");
                    player_score++;
                } else {
                    printf("Computer chooses Scissors:\nIt's a tie!\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Current score:\nPlayer: %d\nComputer: %d\n", player_score, computer_score);

        if (player_score == 3) {
            printf("\nYou won! Congratulations!\n");
            break;
        } else if (computer_score == 3) {
            printf("\nComputer won! Better luck next time!\n");
            break;
        }
    }

    return 0;
}