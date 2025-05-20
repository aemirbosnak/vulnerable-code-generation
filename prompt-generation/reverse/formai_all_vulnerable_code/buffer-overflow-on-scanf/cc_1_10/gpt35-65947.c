//FormAI DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random integer between a specified range
int getRandomNumber(int min, int max) 
{
    srand(time(NULL)); // Seed the random number generator
    return (rand() % (max - min + 1)) + min; // Generate a random number 
}

void game(int num_players)
{
    int rounds = 5;
    int scores[num_players];
    int round_scores[num_players];
    int ans[num_players];
    int i, j, k;

    // Set all scores initially to zero
    for(i=0;i<num_players;i++) {
        scores[i] = 0;
    }

    // Play game for 5 rounds
    for(k=0;k<rounds;k++) {
        printf("\n\nRound %d\n\n", k+1);

        // Generate two random numbers
        int a = getRandomNumber(0, 10);
        int b = getRandomNumber(0, 10);

        // Ask each player to solve the arithmetic expression
        for(i=0;i<num_players;i++) {
            printf("Player %d Enter the solution to %d + %d: ", i+1, a, b);
            scanf("%d", &ans[i]);

            // Check if answer is correct and update score
            if(ans[i] == (a + b)) {
                printf("Correct answer!\n");
                round_scores[i] = 10;
            } else {
                printf("Wrong answer!\n");
                round_scores[i] = 0;
            }
        }

        // Display the results of the round
        printf("\nRound Results:\n\n");
        for(i=0;i<num_players;i++) {
            printf("Player %d score: %d\n", i+1, round_scores[i]);
            scores[i] += round_scores[i];
        }
    }

    // Display final scores
    printf("\nFinal Scores:\n\n");
    for(i=0;i<num_players;i++) {
        printf("Player %d score: %d\n", i+1, scores[i]);
    }
}

int main()
{
    int num_players;

    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    game(num_players);

    return 0;
}