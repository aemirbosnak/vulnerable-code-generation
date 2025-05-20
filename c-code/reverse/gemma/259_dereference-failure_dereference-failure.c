#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_MOVES 10

typedef struct Node {
  int move;
  struct Node** children;
} Node;

int minimax(Node* node, int player, int alpha, int beta) {
  if (node == NULL) {
    return 0;
  }

  int best_move = -1;
  int best_score = player * MAX_MOVES;

  for (int i = 0; i < MAX_MOVES; i++) {
    Node* child = malloc(sizeof(Node));
    child->move = i;
    child->children = NULL;

    int score = minimax(child, -player, alpha, beta);

    if (score > best_score) {
      best_score = score;
      best_move = i;
    }

    free(child);
  }

  node->move = best_move;
  return best_score;
}

int main() {
  Node* root = malloc(sizeof(Node));
  root->children = NULL;

  minimax(root, 1, -MAX_MOVES, MAX_MOVES);

  printf("Best move: %d\n", root->move);

  free(root);

  return 0;
}
