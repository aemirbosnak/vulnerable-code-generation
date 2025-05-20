//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10

typedef struct {
    int x;
    int y;
} Coordinate;

/**
 * Initializes a coordinate with random x and y values within map boundaries.
 */
Coordinate random_coordinate() {
    Coordinate coordinate;
    coordinate.x = rand() % MAP_SIZE;
    coordinate.y = rand() % MAP_SIZE;
    return coordinate;
}

/**
 * Calculates the distance between two coordinates.
 */
int distance(Coordinate c1, Coordinate c2) {
    int dx = c1.x - c2.x;
    int dy = c1.y - c2.y;
    return abs(dx) + abs(dy);
}

int main() {
    srand(time(NULL)); // initialize random seed

    Coordinate destination = random_coordinate();
    Coordinate player1_location = random_coordinate();
    Coordinate player2_location = random_coordinate();

    printf("Destination: (%d, %d)\n", destination.x, destination.y);

    int player1_distance = distance(destination, player1_location);
    int player2_distance = distance(destination, player2_location);

    while (player1_location.x != destination.x || player1_location.y != destination.y ||
           player2_location.x != destination.x || player2_location.y != destination.y) {

        printf("Player 1 current location: (%d, %d), Distance to destination: %d\n", player1_location.x, player1_location.y, player1_distance);
        printf("Player 2 current location: (%d, %d), Distance to destination: %d\n", player2_location.x, player2_location.y, player2_distance);

        // Player 1 turn
        printf("Player 1's turn. Enter direction (U/D/L/R): ");
        char direction;
        scanf(" %c", &direction);
        switch (direction) {
            case 'U':
                if (player1_location.y > 0) {
                    player1_location.y--;
                }
                break;
            case 'D':
                if (player1_location.y < MAP_SIZE - 1) {
                    player1_location.y++;
                }
                break;
            case 'L':
                if (player1_location.x > 0) {
                    player1_location.x--;
                }
                break;
            case 'R':
                if (player1_location.x < MAP_SIZE - 1) {
                    player1_location.x++;
                }
                break;
        }
        player1_distance = distance(destination, player1_location);

        // Player 2 turn
        printf("Player 2's turn. Enter direction (U/D/L/R): ");
        scanf(" %c", &direction);
        switch (direction) {
            case 'U':
                if (player2_location.y > 0) {
                    player2_location.y--;
                }
                break;
            case 'D':
                if (player2_location.y < MAP_SIZE - 1) {
                    player2_location.y++;
                }
                break;
            case 'L':
                if (player2_location.x > 0) {
                    player2_location.x--;
                }
                break;
            case 'R':
                if (player2_location.x < MAP_SIZE - 1) {
                    player2_location.x++;
                }
                break;
        }
        player2_distance = distance(destination, player2_location);
    }

    printf("Destination reached!\n");
    if (player1_distance <= player2_distance) {
        printf("Player 1 wins!\n");
    }
    else {
        printf("Player 2 wins!\n");
    }

    return 0;
}