//FormAI DATASET v1.0 Category: Table Game ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int roll_dice(void);

int main(void)
{
    int n, player_score, computer_score;
    srand((unsigned) time(NULL)); //seeding the random generator

    printf("\nWelcome to the Dice Game!\n");
    printf("--------------------------\n");

    do {
        printf("\nEnter number of rounds to play: ");
        scanf("%d", &n);
    } while (n <= 0); //accepting a positive integer only

    printf("\n-----------------------------------------------------------\n");
    printf("| Round No. | Player's Score | Computer's Score |  Result  |\n");
    printf("-----------------------------------------------------------\n");

    player_score = computer_score = 0; //initializing the scores

    for (int i = 1; i <= n; i++) {

        int player_roll = roll_dice();
        int computer_roll = roll_dice();

        printf("|    %2d     |       %2d       |        %2d        |", i, player_roll, computer_roll);

        if (player_roll > computer_roll) {
            player_score++;
            printf("    You Win!    |");
        } else if (player_roll < computer_roll) {
            computer_score++;
            printf("   Computer Wins! |");
        } else {
            printf("      Tie!      |");
        }
        printf("\n-----------------------------------------------------------\n");
    }

    printf("\nFinal Scores:");
    printf("\nPlayer: %d", player_score);
    printf("\nComputer: %d\n", computer_score);

    if (player_score > computer_score) {
        printf("\nCongratulations! You won!\n");
    } else if (player_score < computer_score) {
        printf("\nSorry, Computer won this time!\n");
    } else {
        printf("\nIt's a Tie!\n");
    }

    return 0;
}

int roll_dice(void)
{
    return rand() % 6 + 1; //returning a random number between 1 and 6
}