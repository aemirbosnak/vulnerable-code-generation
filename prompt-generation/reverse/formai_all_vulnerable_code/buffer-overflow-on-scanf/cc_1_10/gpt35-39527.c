//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the Topology Mapper 3000!\n");
  printf("Please enter the number of devices on your network: ");
  int num_devices;
  scanf("%d", &num_devices);

  char** devices = malloc(num_devices * sizeof(char*));
  for (int i = 0; i < num_devices; i++) {
    devices[i] = malloc(20 * sizeof(char));
    printf("Please enter the name of device %d: ", i+1);
    scanf("%s", devices[i]);
  }

  printf("\nExcellent! Now, let's connect these devices.\n");
  int** connections = malloc(num_devices * sizeof(int*));
  for (int i = 0; i < num_devices; i++) {
    connections[i] = calloc(num_devices, sizeof(int));
    for (int j = 0; j < num_devices; j++) {
      printf("Is %s connected to %s? (1 for yes, 0 for no): ", devices[i], devices[j]);
      scanf("%d", &connections[i][j]);
    }
  }

  printf("\nAwesome! Here is your network topology:\n");
  printf("    ");
  for (int i = 0; i < num_devices; i++) {
    printf("%s ", devices[i]);
  }
  printf("\n");

  for (int i = 0; i < num_devices; i++) {
    printf("%s  ", devices[i]);
    for (int j = 0; j < num_devices; j++) {
      printf("%d  ", connections[i][j]);
    }
    printf("\n");
  }

  printf("\nGood job! Don't forget to buy a bouquet of flowers for your network engineer.\n");

  for (int i = 0; i < num_devices; i++) {
    free(devices[i]);
    free(connections[i]);
  }
  free(devices);
  free(connections);
  return 0;
}