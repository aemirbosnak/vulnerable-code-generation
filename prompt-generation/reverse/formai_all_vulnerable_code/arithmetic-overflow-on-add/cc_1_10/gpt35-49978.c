//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1000000

int n, m;

int fx, fy;  // Final position
int sx, sy;  // Starting position

char map[505][505];  // 2D array to represent the map
int g[505][505];     // Array to store the cost of a path from starting to current position
int h[505][505];     // Array to store the cost of a path from current to final position
bool visited[505][505];     // Array to keep track of visited positions during traversal
bool closed_list[505][505];  // Array to keep track of closed positions during traversal

int dx[] = {-1, 0, 1, 0};  // Arrays to define the four possible movements
int dy[] = {0, 1, 0, -1};

typedef struct Node {  // Structure to represent a node
  int x, y, f, g, h;
} Node;

Node *new_node(int x, int y, int f, int g, int h) {  // Function to create a new node
  Node *node = (Node *) malloc(sizeof(Node));
  node->x = x;
  node->y = y;
  node->f = f;
  node->g = g;
  node->h = h;
  return node;
}

Node **initialize_nodes() {  // Function to initialize array of nodes
  Node **nodes = (Node **) malloc(n * sizeof(Node *));
  for (int i = 0; i < n; i++) {
    nodes[i] = (Node *) malloc(m * sizeof(Node));
  }
  return nodes;
}

void initialize_arrays() {  // Function to initialize arrays
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      g[i][j] = INF;
      h[i][j] = INF;
      visited[i][j] = false;
      closed_list[i][j] = false;
    }
  }
}

bool is_valid(int x, int y) {  // Function to check if a position is valid
  return (x >= 0 && y >= 0 && x < n && y < m && map[x][y] != '#');
}

int manhattan(int x1, int y1, int x2, int y2) {  // Function to calculate manhattan distance
  return abs(x1 - x2) + abs(y1 - y2);
}

Node *find_min_f_node(Node **nodes) {  // Function to find the node with the minimum f value
  Node *min_node = NULL;
  int min_f = INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j] == true || closed_list[i][j] == true) continue;
      if (nodes[i][j].f < min_f) {
        min_f = nodes[i][j].f;
        min_node = &nodes[i][j];
      }
    }
  }
  return min_node;
}

void a_star() {  // Function to perform A* pathfinding algorithm
  Node **nodes = initialize_nodes();

  nodes[sx][sy].f = h[sx][sy] = manhattan(sx, sy, fx, fy);  // Initialize starting node
  nodes[sx][sy].g = 0;

  while (1) {
    Node *current_node = find_min_f_node(nodes);  // Find the node with the minimum f value
    if (current_node == NULL) break; // End condition
    if (current_node->x == fx && current_node->y == fy) break;  // If final node is reached

    visited[current_node->x][current_node->y] = true;  // Mark current node as visited

    for (int i = 0; i < 4; i++) {  // Traverse neighbors of current node
      int neighbor_x = current_node->x + dx[i];
      int neighbor_y = current_node->y + dy[i];

      if (!is_valid(neighbor_x, neighbor_y)) continue;

      if (!visited[neighbor_x][neighbor_y]) {
        if (g[current_node->x][current_node->y] + 1 < g[neighbor_x][neighbor_y]) {
          g[neighbor_x][neighbor_y] = g[current_node->x][current_node->y] + 1;
          h[neighbor_x][neighbor_y] = manhattan(neighbor_x, neighbor_y, fx, fy);
          nodes[neighbor_x][neighbor_y].f = g[neighbor_x][neighbor_y] + h[neighbor_x][neighbor_y];
          nodes[neighbor_x][neighbor_y].g = g[neighbor_x][neighbor_y];
        }
        if (!closed_list[neighbor_x][neighbor_y]) {
          nodes[neighbor_x][neighbor_y].f = g[neighbor_x][neighbor_y] + h[neighbor_x][neighbor_y];
          nodes[neighbor_x][neighbor_y].g = g[neighbor_x][neighbor_y];
        }
      }
    }
    closed_list[current_node->x][current_node->y] = true;  // Add current node to the closed list
  }
  printf("The shortest path between (%d, %d) and (%d, %d) is %d", sx, sy, fx, fy, g[fx][fy]);
}

int main() {
  scanf("%d%d", &n, &m);
  scanf("%d%d%d%d", &sx, &sy, &fx, &fy);

  for (int i = 0; i < n; i++) {
    scanf("%s", map[i]);
  }

  initialize_arrays();
  a_star();
  return 0;
}