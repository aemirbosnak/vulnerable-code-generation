//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("Welcome to the Bingo Simulator!\n");
    printf("Enter the number of players (1-6): ");
    int num_players;
    scanf("%d", &num_players);

    if(num_players<1 || num_players>6){  // Check invalid number of players
        printf("Invalid number of players! Please enter a number between 1 and 6.\n");
        return 1;
    }

    int players[num_players][25]; // Array for player boards
    int called_numbers[75] = {0};  // Array for called numbers

    srand(time(0)); // Seed random number generator with current time

    // Fill player boards with random numbers
    for(int i=0; i<num_players; i++){
        printf("Player %d's board:\n", i+1);
        for(int j=0; j<25; j++){
            int num = rand()%75 + 1;
            players[i][j] = num;
            printf("%d ", num);
        }
        printf("\n");
    }

    printf("Press ENTER to start the game!");
    getchar(); // Wait for user to press ENTER

    int num_calls = 0; // Counter for number of calls

    // Start calling numbers until someone gets a Bingo
    while(1){
        num_calls++;
        int num = rand()%75 + 1;
        called_numbers[num-1] = 1; // Mark number as called
        printf("Number %d called!\n", num);

        // Check each player's board for the called number
        for(int i=0; i<num_players; i++){
            int count = 0; // Counter for number of matches
            for(int j=0; j<25; j++){
                if(players[i][j] == num){
                    count++;
                }
            }
            if(count >= 5){ // If player has a Bingo
                printf("\nBINGO!\n");
                printf("Player %d wins after %d calls!\n", i+1, num_calls);
                printf("Player %d's board:\n", i+1);
                for(int j=0; j<25; j++){
                    printf("%d ", players[i][j]);
                }
                printf("\n");
                return 0;
            }
        }

        // If all numbers have been called without a Bingo
        if(num_calls == 75){
            printf("No player has a Bingo. The game is a draw!\n");
            return 0;
        }

        // Wait for user to press ENTER before calling next number
        printf("\nPress ENTER for next call...");
        getchar();
    }

    return 0;
}