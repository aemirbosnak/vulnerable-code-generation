//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLOORS 10
#define MAX_PLAYERS 4

int floors[MAX_FLOORS];
int player_count = 0;

void elevator_move(int floor);
void add_player(int floor);
void remove_player(int floor);

int main() {
    printf("Welcome to the Elevator Simulation!\n");
    printf("Please enter the number of floors (between 1 and 10): ");
    scanf("%d", &floors[0]);
    for (int i = 1; i < MAX_FLOORS; i++) {
        printf("Please enter the number of floors (between 1 and 10): ");
        scanf("%d", &floors[i]);
    }

    printf("Please enter the number of players (between 1 and 4): ");
    scanf("%d", &player_count);

    elevator_move(0);

    while (player_count > 0) {
        int floor;
        printf("Player %d, please enter your floor number (between 1 and %d): ", 1 + player_count, MAX_FLOORS - 1);
        scanf("%d", &floor);

        elevator_move(floor);

        if (player_count == 1) {
            printf("Player %d, would you like to leave the elevator? (Y/N): ", 1 + player_count);
            char answer;
            scanf(" %c", &answer);
            if (answer == 'Y' || answer == 'y') {
                player_count--;
                remove_player(floor);
            }
        }

        if (player_count == 2) {
            printf("Player %d, would you like to leave the elevator? (Y/N): ", 1 + player_count);
            char answer;
            scanf(" %c", &answer);
            if (answer == 'Y' || answer == 'y') {
                player_count--;
                remove_player(floor);
            }
        }

        if (player_count == 3) {
            printf("Player %d, would you like to leave the elevator? (Y/N): ", 1 + player_count);
            char answer;
            scanf(" %c", &answer);
            if (answer == 'Y' || answer == 'y') {
                player_count--;
                remove_player(floor);
            }
        }

        if (player_count == 4) {
            printf("Player %d, would you like to leave the elevator? (Y/N): ", 1 + player_count);
            char answer;
            scanf(" %c", &answer);
            if (answer == 'Y' || answer == 'y') {
                player_count--;
                remove_player(floor);
            }
        }

        printf("\n");
    }

    printf("Game over! Thanks for playing!\n");

    return 0;
}

void elevator_move(int floor) {
    printf("The elevator is moving to floor %d...\n", floor);

    if (floor >= 0 && floor < player_count) {
        printf("Player %d is getting off at floor %d...\n", floor + 1, floor);
        printf("Player %d is getting on at floor %d...\n", (floor + 1) + 1, floor);
    }

    for (int i = 0; i < player_count; i++) {
        if (floors[i] == floor) {
            printf("Player %d is on floor %d...\n", i + 1, floor);
        }
    }
}

void add_player(int floor) {
    printf("Player %d is getting on at floor %d...\n", player_count + 1, floor);
    floors[player_count] = floor;
    player_count++;
}

void remove_player(int floor) {
    printf("Player %d is getting off at floor %d...\n", player_count + 1, floor);
    player_count--;
}