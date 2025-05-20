//Code Llama-13B DATASET v1.0 Category: Pathfinding algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_NODES 100
#define MAX_LINKS 100
#define MAX_DATA 100

typedef struct {
  int id;
  int data;
} node_t;

typedef struct {
  int src;
  int dest;
  int weight;
} link_t;

void read_nodes(node_t *nodes, int *n) {
  // Read the number of nodes
  scanf("%d", n);
  // Read the nodes
  for (int i = 0; i < *n; i++) {
    scanf("%d %d", &nodes[i].id, &nodes[i].data);
  }
}

void read_links(link_t *links, int *m) {
  // Read the number of links
  scanf("%d", m);
  // Read the links
  for (int i = 0; i < *m; i++) {
    scanf("%d %d %d", &links[i].src, &links[i].dest, &links[i].weight);
  }
}

void print_path(link_t *links, int m, int start, int end) {
  int path[MAX_NODES];
  int path_size = 0;
  int current = start;
  while (current != end) {
    path[path_size++] = current;
    current = links[current].dest;
  }
  path[path_size++] = end;
  for (int i = 0; i < path_size; i++) {
    printf("%d ", path[i]);
  }
  printf("\n");
}

int main() {
  node_t nodes[MAX_NODES];
  link_t links[MAX_LINKS];
  int n, m;
  read_nodes(nodes, &n);
  read_links(links, &m);
  int start = 0;
  int end = n - 1;
  print_path(links, m, start, end);
  return 0;
}