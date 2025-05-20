//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maze structure
typedef struct {
    int width;
    int height;
    char **data;
} Maze;

// Read a maze from a file
Maze *read_maze(const char *filename) {
    FILE *fp;
    Maze *maze;
    char line[1024];

    // Open the file
    fp = fopen(filename, "r");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    // Read the first line to get the maze dimensions
    fgets(line, sizeof(line), fp);
    sscanf(line, "%d %d", &maze->width, &maze->height);

    // Allocate memory for the maze data
    maze->data = malloc(maze->height * sizeof(char *));
    for (int i = 0; i < maze->height; i++) {
        maze->data[i] = malloc(maze->width + 1);
    }

    // Read the maze data from the file
    for (int i = 0; i < maze->height; i++) {
        fgets(line, sizeof(line), fp);
        strcpy(maze->data[i], line);
    }

    // Close the file
    fclose(fp);

    return maze;
}

// Free the memory allocated for a maze
void free_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->data[i]);
    }
    free(maze->data);
    free(maze);
}

// Find a path through a maze using a depth-first search
int find_path(Maze *maze, int x, int y) {
    // Check if we have reached the exit
    if (maze->data[y][x] == 'E') {
        return 1;
    }

    // Mark the current position as visited
    maze->data[y][x] = 'V';

    // Try all possible moves from the current position
    int found = 0;
    if (!found && x > 0 && maze->data[y][x - 1] != 'X') {
        found = find_path(maze, x - 1, y);
    }
    if (!found && y > 0 && maze->data[y - 1][x] != 'X') {
        found = find_path(maze, x, y - 1);
    }
    if (!found && x < maze->width - 1 && maze->data[y][x + 1] != 'X') {
        found = find_path(maze, x + 1, y);
    }
    if (!found && y < maze->height - 1 && maze->data[y + 1][x] != 'X') {
        found = find_path(maze, x, y + 1);
    }

    // If no path was found, reset the current position to '0'
    if (!found) {
        maze->data[y][x] = '0';
    }

    return found;
}

// Print a maze to the console
void print_maze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        printf("%s\n", maze->data[i]);
    }
}

// Main function
int main(void) {
    Maze *maze;
    int x, y;

    // Read the maze from a file
    maze = read_maze("maze.txt");
    if (!maze) {
        return EXIT_FAILURE;
    }

    // Find the starting position
    for (y = 0; y < maze->height; y++) {
        for (x = 0; x < maze->width; x++) {
            if (maze->data[y][x] == 'S') {
                break;
            }
        }
        if (maze->data[y][x] == 'S') {
            break;
        }
    }

    // Find a path through the maze
    int found = find_path(maze, x, y);

    // Print the maze to the console
    print_maze(maze);

    // Free the memory allocated for the maze
    free_maze(maze);

    return EXIT_SUCCESS;
}