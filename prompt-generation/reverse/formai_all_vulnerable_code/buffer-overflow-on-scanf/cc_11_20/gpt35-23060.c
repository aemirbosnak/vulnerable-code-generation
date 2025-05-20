//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_routers, num_hosts, max_connections;
  printf("Enter the number of routers in the network: ");
  scanf("%d", &num_routers);
  printf("Enter the number of hosts in the network: ");
  scanf("%d", &num_hosts);
  printf("Enter the maximum number of connections each router can have: ");
  scanf("%d", &max_connections);

  printf("\n");

  printf("Welcome to the Surrealist Network Topology Mapper!\n\n");
  printf("We will now generate a surreal network map...\n\n");
  printf("Please wait while we quantum entangle the routers and hosts...\n\n");

  srand(time(0));

  // Generate random connections between routers and hosts
  int router[num_routers][max_connections];
  for (int i = 0; i < num_routers; i++) {
    for (int j = 0; j < max_connections; j++) {
      router[i][j] = -1;
    }
  }

  for (int i = 0; i < num_hosts; i++) {
    int num_connections = rand() % max_connections + 1;
    printf("Host %d is connected to routers: ", i+1);

    for (int j = 0; j < num_connections; j++) {
      int router_index = rand() % num_routers;
      while (1) {
        int flag = 1;
        for (int k = 0; k < max_connections; k++) {
          if (router[router_index][k] == i) {
            flag = 0;
          }
        }
        if (flag) {
          break;
        }
        router_index = rand() % num_routers;
      }
      router[router_index][j] = i;
      printf("%d ", router_index);
    }
    printf("\n");
  }

  printf("\n");
  printf("Surreal network map generated!\n\n");

  // Print out the connections
  printf("Routers\t\tHosts\n");
  for (int i = 0; i < num_routers; i++) {
    printf("%d\t\t", i+1);
    for (int j = 0; j < max_connections; j++) {
      if (router[i][j] != -1) {
        printf("%d ", router[i][j]+1);
      }
    }
    printf("\n");
  }

  return 0;
}