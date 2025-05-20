//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_NAME 100

int main()
{
  int i, j, k, l, m, n;
  char s[MAX_NAME];
  int num_nodes, num_elements, num_iterations;
  double edges[MAX_NODES][MAX_NODES], currents[MAX_NODES][MAX_NODES];
  double voltages[MAX_NODES], resistances[MAX_NODES];
  double prev[MAX_NODES], cur[MAX_NODES];

  printf("Enter the number of nodes in the circuit: ");
  scanf("%d", &num_nodes);

  printf("Enter the number of elements in the circuit: ");
  scanf("%d", &num_elements);

  printf("Enter the number of iterations to perform: ");
  scanf("%d", &num_iterations);

  for (i = 1; i <= num_elements; ++i)
  {
    printf("Enter element %d (ex: R1 1 2 1k): ", i);
    scanf("%s", s);

    if (s[0] == 'R')
    {
      sscanf(s + 1, "%d %d %lf", &j, &k, &resistances[i]);
      edges[j][k] += 1.0 / resistances[i];
      edges[k][j] += 1.0 / resistances[i];
    }
    else if (s[0] == 'V')
    {
      sscanf(s + 1, "%d %d %lf", &j, &k, &voltages[i]);
      edges[j][k] += 1;
      edges[k][j] += -1;
    }
    else if (s[0] == 'I')
    {
      sscanf(s + 1, "%d %d %lf", &j, &k, &currents[i][j]);
      currents[i][k] = -currents[i][j];
    }
    else
    {
      printf("Error: unknown element type\n");
      exit(1);
    }
  }

  printf("Input the initial guess of node voltages (ex: V0 5.0): ");
  for (i = 0; i < num_nodes; ++i)
  {
    scanf("%s", s);
    sscanf(s + 1, "%d %lf", &j, &voltages[j]);
  }

  for (n = 0; n < num_iterations; ++n)
  {
    for (i = 0; i < num_nodes; ++i)
    {
      prev[i] = voltages[i];

      for (j = 0; j < num_nodes; ++j)
      {
        if (i != j)
          cur[i] += edges[i][j] * voltages[j];
      }

      for (j = 1; j <= num_elements; ++j)
      {
        if (currents[j][i])
          cur[i] += currents[j][i];
      }

      voltages[i] = cur[i] / edges[i][i];
      cur[i] = 0;
    }

    if (n > 0)
    {
      m = 0;

      for (i = 0; i < num_nodes; ++i)
        if (fabs(voltages[i] - prev[i]) > 1e-6)
          m = 1;

      if (m == 0)
        break;
    }
  }

  printf("\nNode voltages:\n");
  for (i = 0; i < num_nodes; ++i)
    printf("V%d = %.4lf\n", i, voltages[i]);

  return 0;
}