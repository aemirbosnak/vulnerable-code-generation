//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Watson's map of the maze
char **map;

// The dimensions of the maze
int height, width;

// Sherlock's current position in the maze
int x, y;

// A stack to keep track of Sherlock's path
int *path;
int path_size;

// Function to initialize the maze
void initialize_maze(char **map, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = ' ';
        }
    }
}

// Function to print the maze
void print_maze(char **map, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Function to find the exit of the maze
int find_exit(char **map, int height, int width) {
    // Start at the entrance of the maze
    x = 0;
    y = 0;

    // Push the entrance to the stack
    path_size = 0;
    path = malloc(sizeof(int) * height * width);
    path[path_size++] = x * width + y;

    // While Sherlock has not found the exit
    while (map[y][x] != 'E') {
        // Check if Sherlock can move north
        if (y > 0 && map[y - 1][x] != '#') {
            y--;
            path[path_size++] = x * width + y;
        }
        // Check if Sherlock can move east
        else if (x < width - 1 && map[y][x + 1] != '#') {
            x++;
            path[path_size++] = x * width + y;
        }
        // Check if Sherlock can move south
        else if (y < height - 1 && map[y + 1][x] != '#') {
            y++;
            path[path_size++] = x * width + y;
        }
        // Check if Sherlock can move west
        else if (x > 0 && map[y][x - 1] != '#') {
            x--;
            path[path_size++] = x * width + y;
        }
        // If Sherlock cannot move in any direction, he is stuck
        else {
            return 0;
        }
    }

    // Sherlock has found the exit
    return 1;
}

// Function to print Sherlock's path through the maze
void print_path(int *path, int path_size) {
    for (int i = 0; i < path_size; i++) {
        int x = path[i] % width;
        int y = path[i] / width;
        map[y][x] = '*';
    }

    print_maze(map, height, width);
}

// Function to free the memory allocated for the maze and the stack
void free_memory(char **map, int height, int width) {
    for (int i = 0; i < height; i++) {
        free(map[i]);
    }
    free(map);
    free(path);
}

int main() {
    // Get the dimensions of the maze
    printf("Enter the height of the maze: ");
    scanf("%d", &height);
    printf("Enter the width of the maze: ");
    scanf("%d", &width);

    // Allocate memory for the maze
    map = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(char) * width);
    }

    // Initialize the maze
    initialize_maze(map, height, width);

    // Get the maze from the user
    printf("Enter the maze layout:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    // Find the exit of the maze
    int found_exit = find_exit(map, height, width);

    // Print the maze with Sherlock's path
    if (found_exit) {
        printf("Sherlock's path through the maze:\n");
        print_path(path, path_size);
    } else {
        printf("Sherlock could not find the exit of the maze.\n");
    }

    // Free the memory allocated for the maze and the stack
    free_memory(map, height, width);

    return 0;
}