//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int nodes[MAX_NODES];
int colors[MAX_COLORS];
int n, m, k;

int main() {
  // Input the number of nodes, edges, and colors
  scanf("%d %d %d", &n, &m, &k);

  // Input the edges
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    nodes[u] |= 1 << v;
    nodes[v] |= 1 << u;
  }

  // Input the colors
  for (int i = 0; i < k; i++) {
    int c;
    scanf("%d", &c);
    colors[c] = 1;
  }

  // Solve the graph coloring problem
  int best_score = -1;
  int best_color[MAX_NODES];
  for (int mask = 0; mask < (1 << k); mask++) {
    // Check if the mask is valid
    int valid = 1;
    for (int i = 0; i < n; i++) {
      if ((nodes[i] & mask) == 0) {
        valid = 0;
        break;
      }
    }

    if (!valid) {
      continue;
    }

    // Calculate the score of the mask
    int score = 0;
    for (int i = 0; i < k; i++) {
      if ((mask & (1 << i)) != 0) {
        score += colors[i];
      }
    }

    // Update the best score and color
    if (score > best_score) {
      best_score = score;
      for (int i = 0; i < n; i++) {
        best_color[i] = mask >> (i + 1);
      }
    }
  }

  // Output the best color
  for (int i = 0; i < n; i++) {
    printf("%d ", best_color[i]);
  }

  printf("\n");

  return 0;
}