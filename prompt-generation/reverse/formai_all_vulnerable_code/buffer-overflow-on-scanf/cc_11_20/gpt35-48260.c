//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
#include <stdio.h>

#define MAX_CONNECTIONS 10
#define MAX_DRONES 5

struct Drone {
  int id;
  float battery;
  int connected;
} drones[MAX_DRONES];

int main() {
  int numConnections = 0;
  int numDrones = 0;
  int i;

  while (numDrones < MAX_DRONES && numConnections < MAX_CONNECTIONS) {
    int connection;
    float battery;
    
    printf("Enter drone ID: ");
    scanf("%d", &drones[numDrones].id);

    if (drones[numDrones].id == -1) break;

    printf("Enter drone battery: ");
    scanf("%f", &battery);

    if (battery < 0 || battery > 100) {
      printf("Battery value must be between 0 and 100. Try again.\n");
      continue;
    }

    printf("Enter connection number: ");
    scanf("%d", &connection);

    if (connection < 0 || connection >= MAX_CONNECTIONS) {
      printf("Invalid connection number. Try again.\n");
      continue;
    }
    
    if (drones[numDrones].id == drones[connection].id) {
      printf("A drone cannot connect to itself. Try again.\n");
      continue;
    }

    if (drones[connection].connected != 0) {
      printf("Connection is already occupied. Try again.\n");
      continue;
    }

    drones[numDrones].battery = battery;
    drones[numDrones].connected = 1;
    drones[connection].connected = 1;

    numDrones++;
    numConnections++;
  }

  printf("Connected drones:\n");
  for (i = 0; i < numDrones; i++) {
    printf("Drone %d (Battery: %.2f%%)\n", drones[i].id, drones[i].battery);
  }

  printf("Unconnected drones:\n");
  for (i = 0; i < MAX_DRONES; i++) {
    if (drones[i].connected == 0) {
      printf("Drone %d\n", drones[i].id);
    }
  }

  return 0;
}