//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
// Immerse yourself in the labyrinth of code, where time is a precious commodity.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each tick of the clock represents a precious moment.
#define TICK_MS 1

// The battlefield is a perilous grid, where every step holds potential.
#define GRID_SIZE 10

// The path to victory is a treacherous maze of decisions.
typedef enum {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    STAY_PUT
} Direction;

// Your intrepid adventurer, navigating the treacherous grid.
typedef struct {
    int x;
    int y;
    Direction direction;
    int speed;
} Adventurer;

// The grid, a tapestry woven with obstacles and opportunities.
int grid[GRID_SIZE][GRID_SIZE];

// The clock, a relentless reminder of time's swift passage.
clock_t start_time;

// A guiding light, illuminating the path through the labyrinth.
int destination_x;
int destination_y;

// The heart of the adventure, where every tick brings you closer to your destiny.
void adventure() {
    // As the clock strikes, the race begins.
    start_time = clock();

    // Create our intrepid adventurer, poised at the starting line.
    Adventurer adventurer = {0, 0, STAY_PUT, 1};

    // Generate a random destination, the beacon of hope in this treacherous realm.
    destination_x = rand() % GRID_SIZE;
    destination_y = rand() % GRID_SIZE;

    // An endless loop, a dance with time until victory or despair claims us.
    while (1) {
        // Time races on, a constant companion in this relentless pursuit.
        clock_t current_time = clock();
        int elapsed_time = (current_time - start_time) / TICK_MS;

        // Update the adventurer's position, one step closer to their fate.
        switch (adventurer.direction) {
            case MOVE_UP:
                adventurer.y--;
                break;
            case MOVE_DOWN:
                adventurer.y++;
                break;
            case MOVE_LEFT:
                adventurer.x--;
                break;
            case MOVE_RIGHT:
                adventurer.x++;
                break;
            default:
                break;
        }

        // Have we reached our destination, the culmination of our perilous journey?
        if (adventurer.x == destination_x && adventurer.y == destination_y) {
            printf("Victory! You have reached your destination in %d milliseconds.\n", elapsed_time);
            return;
        }

        // Alas, the path is not without its perils. Check for collisions with obstacles.
        if (grid[adventurer.x][adventurer.y] == 1) {
            printf("Oh no! You have hit an obstacle at [%d, %d]. Game over.\n", adventurer.x, adventurer.y);
            return;
        }

        // Time waits for no one. Choose our next move wisely.
        adventurer.direction = rand() % 5;

        // Yield to the relentless march of time.
        usleep(adventurer.speed * TICK_MS);
    }
}

int main() {
    // Scatter obstacles across the grid, creating a tapestry of challenges.
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = (rand() % 10) == 0 ? 1 : 0;
        }
    }

    // Embark on your epic adventure, where time is your most precious ally.
    adventure();

    return 0;
}