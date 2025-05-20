//Code Llama-13B DATASET v1.0 Category: Procedurally Generated Maze ; Style: detailed
/*
 * maze.c
 *
 * A procedurally generated maze example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define NUM_ROOMS 5
#define MAX_ROOM_SIZE 4

// Define the maze struct
struct Maze {
    int width;
    int height;
    int num_rooms;
    int max_room_size;
    int** grid;
};

// Initialize the maze
void initMaze(struct Maze* maze) {
    maze->width = WIDTH;
    maze->height = HEIGHT;
    maze->num_rooms = NUM_ROOMS;
    maze->max_room_size = MAX_ROOM_SIZE;
    maze->grid = (int**)malloc(maze->width * sizeof(int*));
    for (int i = 0; i < maze->width; i++) {
        maze->grid[i] = (int*)malloc(maze->height * sizeof(int));
        for (int j = 0; j < maze->height; j++) {
            maze->grid[i][j] = 0;
        }
    }
}

// Generate a random number between min and max (inclusive)
int randomNumber(int min, int max) {
    return min + (int)(rand() * (max - min + 1) / (RAND_MAX + 1.0));
}

// Generate a random room
void generateRoom(struct Maze* maze) {
    int x = randomNumber(0, maze->width - 1);
    int y = randomNumber(0, maze->height - 1);
    int size = randomNumber(1, maze->max_room_size);
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            maze->grid[i][j] = 1;
        }
    }
}

// Generate a random maze
void generateMaze(struct Maze* maze) {
    for (int i = 0; i < maze->num_rooms; i++) {
        generateRoom(maze);
    }
}

// Print the maze
void printMaze(struct Maze* maze) {
    for (int i = 0; i < maze->width; i++) {
        for (int j = 0; j < maze->height; j++) {
            if (maze->grid[i][j] == 1) {
                printf("  ");
            } else {
                printf("##");
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the maze
    struct Maze maze;
    initMaze(&maze);

    // Generate the maze
    generateMaze(&maze);

    // Print the maze
    printMaze(&maze);

    return 0;
}