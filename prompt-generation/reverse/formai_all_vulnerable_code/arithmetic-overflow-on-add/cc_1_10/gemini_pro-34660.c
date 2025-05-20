//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
  int row;
  int col;
} Position;

typedef struct {
  Position position;
  int distance;
  bool visited;
} Node;

typedef struct {
  Node grid[MAX_ROWS][MAX_COLS];
  int rows;
  int cols;
} Grid;

bool is_valid_position(Grid* grid, Position position) {
  return position.row >= 0 && position.row < grid->rows && position.col >= 0 &&
         position.col < grid->cols && !grid->grid[position.row][position.col].visited;
}

int get_distance(Position a, Position b) {
  return abs(a.row - b.row) + abs(a.col - b.col);
}

Node* get_next_node(Grid* grid, Position position) {
  Node* next = NULL;
  int minDistance = INT_MAX;
  Position adjacentPositions[4] = {
    {position.row - 1, position.col},
    {position.row + 1, position.col},
    {position.row, position.col - 1},
    {position.row, position.col + 1},
  };
  for (int i = 0; i < 4; i++) {
    Position adjacentPosition = adjacentPositions[i];
    if (is_valid_position(grid, adjacentPosition)) {
      Node* adjacentNode = &grid->grid[adjacentPosition.row][adjacentPosition.col];
      if (adjacentNode->distance < minDistance) {
        minDistance = adjacentNode->distance;
        next = adjacentNode;
      }
    }
  }
  return next;
}

void pathfind(Grid* grid, Position start, Position end) {
  grid->grid[start.row][start.col].visited = true;
  grid->grid[start.row][start.col].distance = 0;
  while (true) {
    Node* next = get_next_node(grid, start);
    if (next == NULL) {
      break;
    }
    start = next->position;
    if (start.row == end.row && start.col == end.col) {
      break;
    }
    grid->grid[start.row][start.col].visited = true;
    grid->grid[start.row][start.col].distance = get_distance(start, end);
  }
}

void print_grid(Grid* grid) {
  for (int i = 0; i < grid->rows; i++) {
    for (int j = 0; j < grid->cols; j++) {
      Node node = grid->grid[i][j];
      printf("%d ", node.distance);
    }
    printf("\n");
  }
}

int main() {
  Grid grid;
  grid.rows = 10;
  grid.cols = 10;
  Position start = {0, 0};
  Position end = {9, 9};
  pathfind(&grid, start, end);
  print_grid(&grid);
  return 0;
}