//Code Llama-13B DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define INF 10000000

typedef struct {
  int x;
  int y;
} Coord;

typedef struct {
  Coord start;
  Coord goal;
} Problem;

typedef struct {
  int **dist;
  int **prev;
} Solution;

void init_dist(Problem problem, Solution *solution) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      solution->dist[i][j] = INF;
    }
  }
}

void init_prev(Problem problem, Solution *solution) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      solution->prev[i][j] = -1;
    }
  }
}

void dijkstra(Problem problem, Solution *solution) {
  init_dist(problem, solution);
  init_prev(problem, solution);

  solution->dist[problem.start.x][problem.start.y] = 0;

  while (1) {
    int x = -1, y = -1;
    int min_dist = INF;

    for (int i = 0; i < WIDTH; i++) {
      for (int j = 0; j < HEIGHT; j++) {
        if (solution->dist[i][j] < min_dist) {
          x = i;
          y = j;
          min_dist = solution->dist[i][j];
        }
      }
    }

    if (x == -1 && y == -1) {
      break;
    }

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }

        int x1 = x + i;
        int y1 = y + j;

        if (x1 < 0 || x1 >= WIDTH || y1 < 0 || y1 >= HEIGHT) {
          continue;
        }

        int new_dist = solution->dist[x][y] + 1;

        if (new_dist < solution->dist[x1][y1]) {
          solution->dist[x1][y1] = new_dist;
          solution->prev[x1][y1] = x;
        }
      }
    }
  }
}

void print_path(Problem problem, Solution *solution) {
  int x = problem.goal.x;
  int y = problem.goal.y;

  while (x != -1 && y != -1) {
    printf("(%d, %d) -> ", x, y);
    x = solution->prev[x][y];
    y = solution->prev[x][y];
  }

  printf("(%d, %d)\n", x, y);
}

int main() {
  Problem problem;
  Solution solution;

  problem.start.x = 0;
  problem.start.y = 0;
  problem.goal.x = 9;
  problem.goal.y = 9;

  solution.dist = (int**)malloc(sizeof(int*) * WIDTH);
  solution.prev = (int**)malloc(sizeof(int*) * WIDTH);

  for (int i = 0; i < WIDTH; i++) {
    solution.dist[i] = (int*)malloc(sizeof(int) * HEIGHT);
    solution.prev[i] = (int*)malloc(sizeof(int) * HEIGHT);
  }

  dijkstra(problem, &solution);
  print_path(problem, &solution);

  for (int i = 0; i < WIDTH; i++) {
    free(solution.dist[i]);
    free(solution.prev[i]);
  }
  free(solution.dist);
  free(solution.prev);

  return 0;
}