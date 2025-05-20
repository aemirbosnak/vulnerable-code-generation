//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void main()
{
  int i, j, k, l, m, n, x, y, z;
  char network[MAX][MAX];

  // Create a 2D array to represent the network topology
  for (i = 0; i < MAX; i++)
  {
    for (j = 0; j < MAX; j++)
    {
      network[i][j] = '\0';
    }
  }

  // Get the number of nodes and links in the network
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the number of links: ");
  scanf("%d", &m);

  // Create the network topology
  for (l = 0; l < m; l++)
  {
    printf("Enter the source node: ");
    scanf("%d", &x);

    printf("Enter the destination node: ");
    scanf("%d", &y);

    network[x][y] = '1';
  }

  // Print the network topology
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%c ", network[i][j]);
    }

    printf("\n");
  }
}