//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define MAX_TEMP 100
#define MIN_TEMP 0
#define MAX_ROUNDS 10

int main() {
    int temp = 50;
    int players[NUM_PLAYERS] = {0};
    int round = 1;
    srand(time(NULL));
    
    printf("WELCOME TO THE TEMPERATURE MONITOR GAME!\n");
    printf("The current temperature is %d degrees Celsius\n\n", temp);
    
    // Game loop
    while (round <= MAX_ROUNDS) {
        printf("ROUND %d\n\n", round);
        // Player input
        for (int i = 0; i < NUM_PLAYERS; i++) {
            printf("Player %d, enter your temperature guess for this round (between %d and %d): ", i+1, MIN_TEMP, MAX_TEMP);
            scanf("%d", &players[i]);
            printf("\n");
            // Error checking
            if (players[i] < MIN_TEMP || players[i] > MAX_TEMP) {
                printf("Invalid input. Temperature must be between %d and %d.\n\n", MIN_TEMP, MAX_TEMP);
                i--;
            }
        }
        // Computer input
        int comp_guess = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        printf("Computer's guess: %d\n", comp_guess);
        // Temperature update
        int closest_guess = players[0];
        for (int i = 1; i < NUM_PLAYERS; i++) {
            if (abs(players[i] - temp) < abs(closest_guess - temp)) {
                closest_guess = players[i];
            }
        }
        if (abs(comp_guess - temp) < abs(closest_guess - temp)) {
            printf("The computer was closest to the temperature and wins this round!\n\n");
        } else {
            printf("Player %d was closest to the temperature and wins this round!\n\n", closest_guess);
        }
        // Temperature change
        temp += rand() % 11 - 5;
        printf("The temperature is now %d degrees Celsius\n\n", temp);
        round++;
    }
    // Game over
    printf("GAME OVER!\n");
    return 0;
}