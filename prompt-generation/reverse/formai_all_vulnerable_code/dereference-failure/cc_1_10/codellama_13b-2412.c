//Code Llama-13B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: romantic
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  struct Node {
    int x;
    int y;
    int cost;
    struct Node *next;
  };

  struct Node *createNode(int x, int y, int cost) {
    struct Node *node = malloc(sizeof(struct Node));
    node->x = x;
    node->y = y;
    node->cost = cost;
    node->next = NULL;
    return node;
  }

  struct Node *createPath(int x, int y) {
    struct Node *path = createNode(x, y, 0);
    while (path->next != NULL) {
      path = path->next;
    }
    return path;
  }

  int calculateCost(struct Node *node, struct Node *goal) {
    int dx = abs(node->x - goal->x);
    int dy = abs(node->y - goal->y);
    return dx + dy;
  }

  struct Node *findNextNode(struct Node *node, struct Node *goal) {
    struct Node *nextNode = NULL;
    if (node->x == goal->x && node->y == goal->y) {
      nextNode = NULL;
    } else if (node->x == goal->x && node->y < goal->y) {
      nextNode = createNode(node->x, node->y + 1, node->cost + 1);
    } else if (node->x < goal->x && node->y == goal->y) {
      nextNode = createNode(node->x + 1, node->y, node->cost + 1);
    } else if (node->x < goal->x && node->y < goal->y) {
      nextNode = createNode(node->x + 1, node->y + 1, node->cost + 1);
    }
    return nextNode;
  }

  struct Node *aStar(struct Node *start, struct Node *goal) {
    struct Node *path = createPath(start->x, start->y);
    struct Node *node = start;
    while (node != NULL) {
      struct Node *nextNode = findNextNode(node, goal);
      if (nextNode == NULL) {
        break;
      }
      int cost = calculateCost(nextNode, goal);
      if (cost < nextNode->cost) {
        nextNode->cost = cost;
        nextNode->next = path;
        path = nextNode;
      }
      node = nextNode;
    }
    return path;
  }

  int main() {
    struct Node *start = createNode(0, 0, 0);
    struct Node *goal = createNode(10, 10, 0);
    struct Node *path = aStar(start, goal);
    while (path != NULL) {
      printf("%d %d\n", path->x, path->y);
      path = path->next;
    }
    return 0;
  }