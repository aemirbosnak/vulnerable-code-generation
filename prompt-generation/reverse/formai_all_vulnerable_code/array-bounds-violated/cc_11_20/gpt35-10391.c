//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multiplayer
// This is a multiplayer temperature monitor program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL)); // initialize random number generator
    float temperature[4]; // array to store temperatures of each player
    char names[4][20] = { "Player 1", "Player 2", "Player 3", "Player 4" }; // names of each player
    int i, j;
    char input[20];

    while (1) {
        // update temperature of each player
        for (i = 0; i < 4; i++) {
            temperature[i] = ((float)rand()/(float)(RAND_MAX)) * 100; // generate random temperature between 0 and 100
        }

        printf("\nTemperatures of all players:\n");
        // print table of temperatures
        printf("+----------------------+-------------------+\n");
        printf("|       Player         |      Temperature  |\n");
        printf("+----------------------+-------------------+\n");
        for (i = 0; i < 4; i++) {
            printf("| %-20s| %-18.2f|\n", names[i], temperature[i]);
            printf("+----------------------+-------------------+\n");
        }

        // find highest and lowest temperatures
        float highest = temperature[0];
        float lowest = temperature[0];
        for (i = 1; i < 4; i++) {
            if (temperature[i] > highest) {
                highest = temperature[i];
            }
            if (temperature[i] < lowest) {
                lowest = temperature[i];
            }
        }

        printf("\nHighest temperature: %.2f\n", highest);
        printf("Lowest temperature: %.2f\n", lowest);

        // prompt user to enter player name to find temperature of
        printf("\nEnter name of player to find temperature: ");
        fgets(input, 20, stdin);
        input[strlen(input)-1] = '\0';

        // find temperature of player
        float playerTemp = -1;
        for (i = 0; i < 4; i++) {
            if (strcmp(names[i], input) == 0) {
                playerTemp = temperature[i];
            }
        }

        // print temperature of player
        if (playerTemp != -1) {
            printf("\nTemperature of %s: %.2f\n", input, playerTemp);
        } else {
            printf("\nPlayer %s not found\n", input);
        }

        // prompt user to play again or quit
        printf("\nPlay again? (y/n): ");
        fgets(input, 20, stdin);
        input[strlen(input)-1] = '\0';

        if (strcmp(input, "n") == 0) {
            break;
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}