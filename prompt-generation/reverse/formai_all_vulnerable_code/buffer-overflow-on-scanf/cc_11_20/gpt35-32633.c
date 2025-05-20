//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num_players, num_vehicles, num_rounds;
    printf("Welcome to Remote Control Vehicle Simulation!\n");
    printf("How many players will be participating? (2-4): ");
    scanf("%d", &num_players);

    if (num_players < 2 || num_players > 4) {
        printf("Invalid number of players. Exiting program.\n");
        return 0;
    }

    printf("How many vehicles will be in the simulation? (1-10): ");
    scanf("%d", &num_vehicles);

    if (num_vehicles < 1 || num_vehicles > 10) {
        printf("Invalid number of vehicles. Exiting program.\n");
        return 0;
    }

    printf("How many rounds will the simulation be played? (1-10): ");
    scanf("%d", &num_rounds);

    if (num_rounds < 1 || num_rounds > 10) {
        printf("Invalid number of rounds. Exiting program.\n");
        return 0;
    }

    int vehicles[num_vehicles][3]; //2D array to store vehicle information

    //initialize vehicles
    for (int i = 0; i < num_vehicles; i++) {
        vehicles[i][0] = i+1; //vehicle ID
        vehicles[i][1] = rand() % 100; //vehicle position
        vehicles[i][2] = rand() % 5; //vehicle speed
    }

    //game simulation
    for (int i = 0; i < num_rounds; i++) {
        printf("Round %d\n", i+1);
        for (int j = 0; j < num_players; j++) {
            printf("Player %d's turn\n", j+1);
            //player chooses a vehicle to control
            int vehicle_choice;
            printf("Choose a vehicle to control (1-%d): ", num_vehicles);

            scanf("%d", &vehicle_choice);

            if (vehicle_choice < 1 || vehicle_choice > num_vehicles) {
                printf("Invalid vehicle choice. Skipping turn.\n");
                continue;
            }

            //player chooses an action to perform
            int action_choice;
            printf("Choose an action to perform (1: accelerate, 2: decelerate, 3: maintain speed): ");
            scanf("%d", &action_choice);

            if (action_choice < 1 || action_choice > 3) {
                printf("Invalid action choice. Skipping turn.\n");
                continue;
            }

            //update vehicle speed based on player's action
            switch (action_choice) {
                case 1:
                    vehicles[vehicle_choice-1][2] += 1;
                    break;
                case 2:
                    vehicles[vehicle_choice-1][2] -= 1;
                    if (vehicles[vehicle_choice-1][2] < 0) {
                        vehicles[vehicle_choice-1][2] = 0; //vehicle cannot go below zero speed
                    }
                    break;
                default:
                    break;
            }

            //update vehicle position based on new speed
            vehicles[vehicle_choice-1][1] += vehicles[vehicle_choice-1][2];

            //display updated vehicle information
            printf("Vehicle %d: position = %d, speed = %d\n", vehicles[vehicle_choice-1][0], vehicles[vehicle_choice-1][1], vehicles[vehicle_choice-1][2]);
        }
    }

    printf("Simulation complete!\n");

    return 0;
}