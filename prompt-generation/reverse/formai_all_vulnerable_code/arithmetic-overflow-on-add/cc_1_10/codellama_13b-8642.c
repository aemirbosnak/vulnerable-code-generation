//Code Llama-13B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int x, y;
} Position;

typedef struct {
  Position position;
  int cost;
  int heuristic;
} Node;

int heuristic(Position start, Position end) {
  return abs(end.x - start.x) + abs(end.y - start.y);
}

void print_path(Node* path, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d %d\n", path[i].position.x, path[i].position.y);
  }
}

void a_star(Node* start, Node* end) {
  Node* closed_list[MAX_SIZE];
  Node* open_list[MAX_SIZE];

  int open_size = 0;
  int closed_size = 0;

  Node* current = start;

  while (current != end) {
    open_list[open_size++] = current;
    for (int i = 0; i < open_size; i++) {
      Node* neighbor = open_list[i];
      if (neighbor->cost + heuristic(neighbor->position, end->position) < current->cost) {
        current = neighbor;
      }
    }
    closed_list[closed_size++] = current;
    open_list[open_size--] = open_list[open_size];
  }

  print_path(closed_list, closed_size - 1);
}

int main() {
  Position start = {0, 0};
  Position end = {5, 5};

  Node* start_node = malloc(sizeof(Node));
  start_node->position = start;
  start_node->cost = 0;
  start_node->heuristic = heuristic(start, end);

  Node* end_node = malloc(sizeof(Node));
  end_node->position = end;
  end_node->cost = 0;
  end_node->heuristic = heuristic(end, start);

  a_star(start_node, end_node);

  return 0;
}