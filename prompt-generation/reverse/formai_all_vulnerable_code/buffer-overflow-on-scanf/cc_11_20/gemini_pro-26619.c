//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define MAX_NUM_STR 1000

int main() {
  // Declare variables
  char strs[MAX_NUM_STR][MAX_STR_LEN];
  int num_strs;
  int i, j, k;
  int num_clusters;
  int clusters[MAX_NUM_STR][MAX_NUM_STR];
  int cluster_sizes[MAX_NUM_STR];
  int max_cluster_size;
  int max_cluster_index;

  // Read input
  printf("Enter the number of strings: ");
  scanf("%d", &num_strs);
  for (i = 0; i < num_strs; i++) {
    printf("Enter string %d: ", i + 1);
    scanf("%s", strs[i]);
  }

  // Initialize clusters
  for (i = 0; i < MAX_NUM_STR; i++) {
    for (j = 0; j < MAX_NUM_STR; j++) {
      clusters[i][j] = 0;
    }
  }

  // Compute clusters
  for (i = 0; i < num_strs; i++) {
    for (j = i + 1; j < num_strs; j++) {
      if (strcmp(strs[i], strs[j]) == 0) {
        clusters[i][j] = 1;
        clusters[j][i] = 1;
      }
    }
  }

  // Find the number of clusters
  num_clusters = 0;
  for (i = 0; i < num_strs; i++) {
    if (cluster_sizes[i] == 0) {
      num_clusters++;
      cluster_sizes[i] = 1;
      for (j = i + 1; j < num_strs; j++) {
        if (clusters[i][j] == 1) {
          cluster_sizes[i]++;
          cluster_sizes[j] = 0;
        }
      }
    }
  }

  // Find the largest cluster
  max_cluster_size = 0;
  max_cluster_index = -1;
  for (i = 0; i < num_strs; i++) {
    if (cluster_sizes[i] > max_cluster_size) {
      max_cluster_size = cluster_sizes[i];
      max_cluster_index = i;
    }
  }

  // Print the results
  printf("The number of clusters is: %d\n", num_clusters);
  printf("The largest cluster is:\n");
  for (i = 0; i < num_strs; i++) {
    if (clusters[max_cluster_index][i] == 1) {
      printf("%s\n", strs[i]);
    }
  }

  return 0;
}