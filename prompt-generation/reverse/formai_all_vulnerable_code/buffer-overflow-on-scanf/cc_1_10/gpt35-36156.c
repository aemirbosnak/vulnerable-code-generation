//FormAI DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int rand_num, player_1_score, player_2_score, turn_score, turn_num, player_1_choice, player_2_choice;
    char player_1_name[20], player_2_name[20];
    srand(time(NULL)); // Seed for random number generator

    // Getting player names
    printf("Enter Player 1's name: ");
    scanf("%s", player_1_name);
    printf("Enter Player 2's name: ");
    scanf("%s", player_2_name);

    // Initializing scores
    player_1_score = 0;
    player_2_score = 0;

    // Initializing turn number
    turn_num = 1;

    // Loop to alternate turns between players
    while(player_1_score < 100 && player_2_score < 100) {
        printf("\n\nTurn %d\n\n", turn_num);
        turn_score = 0;

        // Player 1's turn
        printf("%s's turn\n", player_1_name);
        player_1_choice = 0;
        while(player_1_choice != 2) {
            rand_num = rand() % 6 + 1; // Generating random number
            printf("Rolled: %d\n", rand_num);
            turn_score += rand_num; // Adding to turn score
            printf("Turn score: %d\n", turn_score);
            printf("Enter 1 to roll again or 2 to end turn\n");
            scanf("%d", &player_1_choice);
        }
        player_1_score += turn_score; // Adding turn score to player score
        printf("%s's score: %d\n", player_1_name, player_1_score);

        // Checking if player 1 has won
        if(player_1_score >= 100) break;

        // Player 2's turn
        printf("\n%s's turn\n", player_2_name);
        player_2_choice = 0;
        while(player_2_choice != 2) {
            rand_num = rand() % 6 + 1; // Generating random number
            printf("Rolled: %d\n", rand_num);
            turn_score += rand_num; // Adding to turn score
            printf("Turn score: %d\n", turn_score);
            printf("Enter 1 to roll again or 2 to end turn\n");
            scanf("%d", &player_2_choice);
        }
        player_2_score += turn_score; // Adding turn score to player score
        printf("%s's score: %d\n", player_2_name, player_2_score);

        // Incrementing turn number
        turn_num++;
    }

    // Declaring winner
    if(player_1_score >= 100) printf("\n\n%s wins!!!\n\n", player_1_name);
    else if(player_2_score >= 100) printf("\n\n%s wins!!!\n\n", player_2_name);

    return 0;
}