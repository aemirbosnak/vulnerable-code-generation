//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

int map[ROWS][COLUMNS] = { { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                           { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                           { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                           { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

typedef struct Node {
  int x, y;
  int F, G, H;
  struct Node* parent;
} Node;

Node* start;
Node* end;
Node* openSet[ROWS*COLUMNS];
Node* closedSet[ROWS*COLUMNS];
int openSetCount = 0;
int closedSetCount = 0;

//Heuristic function that calculates the distance between the current node and the end node
int heuristic(Node* current) {
  int dx = abs(current->x - end->x);
  int dy = abs(current->y - end->y);
  return dx + dy;
}

//Find the lowest F cost in the open set
Node* lowestFCost() {
  Node* lowestNode = openSet[0];
  for (int i = 0; i < openSetCount; i++) {
    if (openSet[i]->F < lowestNode->F) {
      lowestNode = openSet[i];
    }
  }
  return lowestNode;
}

//Check if a node is in the closed set
int isInClosedSet(Node* node) {
  for (int i = 0; i < closedSetCount; i++) {
    if (node->x == closedSet[i]->x && node->y == closedSet[i]->y) {
      return 1;
    }
  }
  return 0;
}

//Check if a node is in the open set
int isInOpenSet(Node* node) {
  for (int i = 0; i < openSetCount; i++) {
    if (node->x == openSet[i]->x && node->y == openSet[i]->y) {
      return 1;
    }
  }
  return 0;
}

//Add a node to the open set
void addToOpenSet(Node* node) {
  openSet[openSetCount] = node;
  openSetCount++;
}

//Remove a node from the open set
void removeFromOpenSet(Node* node) {
  int index = -1;
  for (int i = 0; i < openSetCount; i++) {
    if (node->x == openSet[i]->x && node->y == openSet[i]->y) {
      index = i;
      break;
    }
  }
  if (index != -1) {
    for (int i = index; i < openSetCount-1; i++) {
      openSet[i] = openSet[i+1];
    }
    openSetCount--;
  }
}

//Add a node to the closed set
void addToClosedSet(Node* node) {
  closedSet[closedSetCount] = node;
  closedSetCount++;
}

//Reconstruct the path from start node to end node
void reconstructPath(Node* current) {
  printf("Path from start to end:\n");
  while (current != NULL) {
    printf("(%d,%d) -> ", current->x, current->y);
    current = current->parent;
  }
  printf("Done.\n");
}

//A* search algorithm
void AStar() {
  addToOpenSet(start);
  while (openSetCount > 0) {
    Node* current = lowestFCost();
    if (current->x == end->x && current->y == end->y) {
      reconstructPath(current);
      return;
    }
    removeFromOpenSet(current);
    addToClosedSet(current);
    //Check all neighbors
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        int neighborX = current->x + i;
        int neighborY = current->y + j;
        int neighborG = current->G + 1;
        if (neighborX < 0 || neighborX >= ROWS || neighborY < 0 || neighborY >= COLUMNS) {
          continue;
        }
        if (isInClosedSet(&map[neighborX][neighborY])) {
          continue;
        }
        if (map[neighborX][neighborY] == 1) {
          continue;
        }
        Node* neighbor;
        if (!isInOpenSet(&map[neighborX][neighborY])) {
          neighbor = (Node*)malloc(sizeof(Node));
          neighbor->x = neighborX;
          neighbor->y = neighborY;
          neighbor->parent = current;
          neighbor->G = neighborG;
          neighbor->H = heuristic(neighbor);
          neighbor->F = neighbor->G + neighbor->H;
          addToOpenSet(neighbor);
        } else {
          neighbor = &map[neighborX][neighborY];
          if (neighborG >= neighbor->G) {
            continue;
          }
          neighbor->G = neighborG;
          neighbor->F = neighbor->G + neighbor->H;
          neighbor->parent = current;
        }
      }
    }
  }
  printf("Path not found.\n");
}

int main() {
  //Initialize start node and end node
  start = (Node*)malloc(sizeof(Node));
  start->x = 0;
  start->y = 0;
  start->parent = NULL;
  start->G = 0;
  start->H = heuristic(start);
  start->F = start->G + start->H;

  end = (Node*)malloc(sizeof(Node));
  end->x = 9;
  end->y = 9;
  end->parent = NULL;
  end->G = 0;
  end->H = heuristic(end);
  end->F = end->G + end->H;

  AStar();

  return 0;
}