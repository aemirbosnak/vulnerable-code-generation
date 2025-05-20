//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_STEPS 100

typedef struct {
  int x;
  int y;
} coordinate;

typedef struct {
  int row;
  int col;
} location;

typedef struct {
  location start;
  location goal;
  int steps;
  int path[MAX_STEPS][MAX_ROWS][MAX_COLS];
} maze;

int is_valid_coord(int row, int col, int max_row, int max_col);
void print_maze(maze maze);
int find_path(maze maze);

int main() {
  int row, col, max_row, max_col, i, j, k, x, y;
  maze maze;

  printf("Enter the number of rows and columns in the maze: ");
  scanf("%d %d", &max_row, &max_col);
  printf("Enter the starting location: ");
  scanf("%d %d", &maze.start.row, &maze.start.col);
  printf("Enter the goal location: ");
  scanf("%d %d", &maze.goal.row, &maze.goal.col);

  maze.steps = find_path(maze);
  if (maze.steps == -1) {
    printf("No path found\n");
  } else {
    printf("Path found with %d steps\n", maze.steps);
    for (i = 0; i < maze.steps; i++) {
      for (j = 0; j < max_row; j++) {
        for (k = 0; k < max_col; k++) {
          if (maze.path[i][j][k] == 1) {
            printf("%c", 'A' + k);
          } else {
            printf(" ");
          }
        }
        printf("\n");
      }
      printf("\n");
    }
  }

  return 0;
}

int find_path(maze maze) {
  int row, col, i, j, k, x, y, max_row, max_col;
  int visited[MAX_ROWS][MAX_COLS];
  location current, next;

  max_row = maze.start.row;
  max_col = maze.start.col;

  maze.path[0][maze.start.row][maze.start.col] = 1;
  maze.path[0][maze.start.row][maze.start.col] = 1;

  for (i = 0; i < maze.steps; i++) {
    for (j = 0; j < max_row; j++) {
      for (k = 0; k < max_col; k++) {
        if (maze.path[i][j][k] == 1) {
          current.row = j;
          current.col = k;
        }
      }
    }

    current.row = maze.start.row;
    current.col = maze.start.col;

    for (j = 0; j < max_row; j++) {
      for (k = 0; k < max_col; k++) {
        if (maze.path[i][j][k] == 1) {
          next.row = j;
          next.col = k;
        }
      }
    }

    if (next.row == maze.goal.row && next.col == maze.goal.col) {
      return i + 1;
    }

    for (j = 0; j < max_row; j++) {
      for (k = 0; k < max_col; k++) {
        if (maze.path[i][j][k] == 1) {
          visited[j][k] = 1;
        } else {
          visited[j][k] = 0;
        }
      }
    }

    for (j = 0; j < max_row; j++) {
      for (k = 0; k < max_col; k++) {
        if (is_valid_coord(j, k, max_row, max_col) &&!visited[j][k]) {
          maze.path[i + 1][j][k] = 1;
          maze.path[i + 1][maze.start.row][maze.start.col] = 1;
          maze.start.row = j;
          maze.start.col = k;
          maze.steps = i + 1;
          break;
        }
      }
    }
  }

  return -1;
}

int is_valid_coord(int row, int col, int max_row, int max_col) {
  return (row >= 0 && row < max_row && col >= 0 && col < max_col);
}

void print_maze(maze maze) {
  int row, col, i, j, k;

  for (row = 0; row < maze.start.row; row++) {
    for (col = 0; col < maze.start.col; col++) {
      if (maze.path[0][row][col] == 1) {
        printf(" %c", 'A' + col);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  for (i = 0; i < maze.steps; i++) {
    for (j = 0; j < maze.start.row; j++) {
      for (k = 0; k < maze.start.col; k++) {
        if (maze.path[i][j][k] == 1) {
          printf(" %c", 'A' + k);
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
    printf("\n");
  }
}