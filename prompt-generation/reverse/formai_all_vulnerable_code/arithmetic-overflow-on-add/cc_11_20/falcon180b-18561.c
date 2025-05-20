//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, count, max_num = 75;
    int nums[75];
    char bingo[5][5];
    int player_count = 0;
    int winner = -1;
    int value;

    srand(time(0));

    // Initialize the bingo board
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            value = rand() % max_num + 1;
            bingo[i][j] = value;
            nums[player_count] = value;
            player_count++;
        }
    }

    // Print the bingo board
    printf("Bingo Board:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d ", bingo[i][j]);
        }
        printf("\n");
    }

    // Print the player's card
    printf("Your Card:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d ", nums[i * 5 + j]);
        }
        printf("\n");
    }

    // Loop until someone wins
    while(winner == -1) {
        int called_num;

        // Call a random number
        called_num = rand() % max_num + 1;

        // Check if the number is on the player's card
        for(i = 0; i < 25; i++) {
            if(nums[i] == called_num) {
                count++;
            }
        }

        // Check if the player has won
        if(count == 5) {
            winner = 1;
        }

        // Check if the game is a tie
        if(player_count - count == 1) {
            winner = 2;
        }

        // Print the updated bingo board and player's card
        printf("\n");
        printf("Called Number: %d\n", called_num);
        printf("Bingo Board:\n");
        for(i = 0; i < 5; i++) {
            for(j = 0; j < 5; j++) {
                printf("%d ", bingo[i][j]);
            }
            printf("\n");
        }
        printf("Your Card:\n");
        for(i = 0; i < 5; i++) {
            for(j = 0; j < 5; j++) {
                printf("%d ", nums[i * 5 + j]);
            }
            printf("\n");
        }
    }

    // Print the result of the game
    if(winner == 1) {
        printf("\nYou won!");
    } else if(winner == 2) {
        printf("\nTie game!");
    } else {
        printf("\nYou lost!");
    }

    return 0;
}