//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

// Define the maze structure
typedef struct {
  int width;
  int height;
  char **grid;
} Maze;

// Define the thread arguments structure
typedef struct {
  Maze *maze;
  int start_x;
  int start_y;
  int end_x;
  int end_y;
  bool *found;
} ThreadArgs;

// Create a new maze
Maze *create_maze(int width, int height) {
  Maze *maze = malloc(sizeof(Maze));
  maze->width = width;
  maze->height = height;
  maze->grid = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    maze->grid[i] = malloc(sizeof(char) * width);
  }
  return maze;
}

// Destroy a maze
void destroy_maze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    free(maze->grid[i]);
  }
  free(maze->grid);
  free(maze);
}

// Load a maze from a file
Maze *load_maze(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  int width, height;
  fscanf(file, "%d %d", &width, &height);

  Maze *maze = create_maze(width, height);

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      fscanf(file, " %c", &maze->grid[i][j]);
    }
  }

  fclose(file);

  return maze;
}

// Save a maze to a file
void save_maze(const char *filename, Maze *maze) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    return;
  }

  fprintf(file, "%d %d\n", maze->width, maze->height);

  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      fprintf(file, " %c", maze->grid[i][j]);
    }
    fprintf(file, "\n");
  }

  fclose(file);
}

// Print a maze
void print_maze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      printf("%c", maze->grid[i][j]);
    }
    printf("\n");
  }
}

// Check if a cell is valid
bool is_valid_cell(Maze *maze, int x, int y) {
  return x >= 0 && x < maze->width && y >= 0 && y < maze->height && maze->grid[y][x] != '#';
}

// Find a path through a maze using a recursive backtracking algorithm
bool find_path(Maze *maze, int start_x, int start_y, int end_x, int end_y) {
  // If we have reached the end of the maze, we have found a path
  if (start_x == end_x && start_y == end_y) {
    return true;
  }

  // Mark the current cell as visited
  maze->grid[start_y][start_x] = 'V';

  // Try all possible moves from the current cell
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      // Skip the current cell
      if (i == 0 && j == 0) {
        continue;
      }

      // Check if the move is valid
      int next_x = start_x + i;
      int next_y = start_y + j;
      if (!is_valid_cell(maze, next_x, next_y)) {
        continue;
      }

      // Recursively call the find_path function to explore the next move
      if (find_path(maze, next_x, next_y, end_x, end_y)) {
        return true;
      }
    }
  }

  // If no valid moves were found, backtrack and unmark the current cell
  maze->grid[start_y][start_x] = ' ';
  return false;
}

// Find a path through a maze using a multi-threaded approach
bool find_path_multithreaded(Maze *maze, int start_x, int start_y, int end_x, int end_y) {
  // Create a semaphore to protect the shared memory
  sem_t semaphore;
  sem_init(&semaphore, 0, 1);

  // Create a thread for each possible move from the starting cell
  pthread_t threads[4];
  ThreadArgs args[4];
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      // Skip the current cell
      if (i == 0 && j == 0) {
        continue;
      }

      // Check if the move is valid
      int next_x = start_x + i;
      int next_y = start_y + j;
      if (!is_valid_cell(maze, next_x, next_y)) {
        continue;
      }

      args[1] = (ThreadArgs){maze, next_x, next_y, end_x, end_y, NULL};
      pthread_create(&threads[i], NULL, (void *(*)(void *))find_path_multithreaded, &args[1]);
    }
  }

  // Wait for all threads to finish
  for (int i = 0; i < 4; i++) {
    pthread_join(threads[i], NULL);
  }

  // Check if any of the threads found a path
  for (int i = 0; i < 4; i++) {
    if (args[i].found != NULL) {
      return true;
    }
  }

  // If no paths were found, return false
  return false;
}

// Main function
int main() {
  // Load a maze from a file
  Maze *maze = load_maze("maze.txt");

  // Print the maze
  print_maze(maze);

  // Find a path through the maze using a recursive backtracking algorithm
  bool found = find_path(maze, 0, 0, maze->width - 1, maze->height - 1);

  // Print the result
  if (found) {
    printf("Path found!\n");
  } else {
    printf("No path found.\n");
  }

  // Destroy the maze
  destroy_maze(maze);

  return 0;
}