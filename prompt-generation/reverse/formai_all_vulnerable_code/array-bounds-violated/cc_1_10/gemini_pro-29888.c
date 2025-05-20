//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: puzzling
// Welcome to the enigmatic maze of enigmas!

#include <stdio.h>
#include <stdlib.h>

// A maze of enigmatic twists and turns!
char maze[8][8] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 1, 0, 1, 0, 1},
    {1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1},
    {1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

// The coordinates of our intrepid explorer
typedef struct {
    int x;
    int y;
} coordinates;

// The directions our explorer can venture forth
typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} direction;

// An enigma wrapped in a mystery, shrouded in a puzzle!
int findPath(coordinates current, direction facing) {
    // Mark our presence in this enigma
    maze[current.x][current.y] = 2;

    // The enigma of multiple paths!
    if (current.x == 7 && current.y == 7) {
        return 1;
    }

    // Venture forth into the unknown
    int foundPath = 0;
    switch (facing) {
        case NORTH:
            if (maze[current.x][current.y + 1] == 0) {
                foundPath = findPath((coordinates) {current.x, current.y + 1}, EAST);
            }
            break;
        case EAST:
            if (maze[current.x + 1][current.y] == 0) {
                foundPath = findPath((coordinates) {current.x + 1, current.y}, SOUTH);
            }
            break;
        case SOUTH:
            if (maze[current.x][current.y - 1] == 0) {
                foundPath = findPath((coordinates) {current.x, current.y - 1}, WEST);
            }
            break;
        case WEST:
            if (maze[current.x - 1][current.y] == 0) {
                foundPath = findPath((coordinates) {current.x - 1, current.y}, NORTH);
            }
            break;
    }

    // Retreat, for no path lies ahead
    if (!foundPath) {
        maze[current.x][current.y] = 0;
    }

    return foundPath;
}

// Unravel the enigma of the maze
int main() {
    // Our explorer embarks on their quest
    coordinates explorer = {0, 0};
    direction explorerFacing = EAST;

    // Seek the elusive exit
    int foundPath = findPath(explorer, explorerFacing);

    // Reveal the fate of our intrepid soul
    if (foundPath) {
        printf("Enigma solved! Path found through the enigmatic maze!\n");
    } else {
        printf("Alas, the enigma remains unsolved. No path found through the enigmatic maze.\n");
    }

    return 0;
}