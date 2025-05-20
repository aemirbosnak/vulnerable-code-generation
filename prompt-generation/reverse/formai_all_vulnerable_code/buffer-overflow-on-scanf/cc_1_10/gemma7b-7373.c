//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int heartRate;
    int stepsTaken;
    int caloriesBurned;
} Player;

int main() {

    // Initialize the players
    Player players[MAX_Players];

    // Get the players' names
    for (int i = 0; i < MAX_Players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Start the game
    int game = 1;

    // While the game is still on, continue
    while (game) {

        // Get the players' heart rates
        for (int i = 0; i < MAX_Players; i++) {
            printf("%s, enter your heart rate: ", players[i].name);
            scanf("%d", &players[i].heartRate);
        }

        // Calculate the players' steps taken
        for (int i = 0; i < MAX_Players; i++) {
            players[i].stepsTaken = rand() % 1000;
        }

        // Calculate the players' calories burned
        for (int i = 0; i < MAX_Players; i++) {
            players[i].caloriesBurned = players[i].stepsTaken * 2;
        }

        // Print the players' stats
        for (int i = 0; i < MAX_Players; i++) {
            printf("%s, your heart rate is %d, you took %d steps, and you burned %d calories.\n", players[i].name, players[i].heartRate, players[i].stepsTaken, players[i].caloriesBurned);
        }

        // Check if the game is over
        printf("Do you want to continue playing? (y/n): ");
        char answer;
        scanf("%c", &answer);

        // If the answer is not y, end the game
        if (answer != 'y') {
            game = 0;
        }
    }

    // End the game
    printf("Thanks for playing, %s!", players[0].name);

    return 0;
}