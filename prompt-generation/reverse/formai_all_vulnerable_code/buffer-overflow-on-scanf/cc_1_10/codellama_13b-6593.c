//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: safe
void main() {
  // Declare variables
  int i, j, k, n, m;
  int matrix[100][100];
  int visited[100];
  int queue[100];
  int head = 0, tail = 0;
  int source = 0;
  int destination = 0;
  int level = 0;
  int min_distance = 0;
  int min_node = 0;

  // Read input from user
  printf("Enter number of nodes: ");
  scanf("%d", &n);
  printf("Enter number of edges: ");
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    printf("Enter edge %d: ", i + 1);
    scanf("%d %d", &j, &k);
    matrix[j][k] = 1;
  }

  // Initialize variables
  for (i = 0; i < n; i++) {
    visited[i] = 0;
    queue[i] = 0;
  }

  // Breadth-First Search
  visited[source] = 1;
  queue[tail++] = source;
  while (head < tail) {
    i = queue[head++];
    for (j = 0; j < n; j++) {
      if (matrix[i][j] == 1 && visited[j] == 0) {
        visited[j] = 1;
        queue[tail++] = j;
        if (j == destination) {
          level = level + 1;
          min_distance = min_distance + 1;
        }
      }
    }
  }

  // Print output
  printf("Level of destination from source: %d\n", level);
  printf("Minimum distance between source and destination: %d\n", min_distance);
}