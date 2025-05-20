//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  // First, let's define our variables
  int num_devices, num_connections, i, j, device_num, conn_num;

  // Now, let's prompt the user to input the number of devices on the network
  printf("Please enter the number of devices on the network: ");
  scanf("%d", &num_devices);

  // Create an array to hold information about each device
  int devices[num_devices][num_devices];

  // Initialize all elements in this array to 0
  for (i = 0; i < num_devices; i++) {
    for (j = 0; j < num_devices; j++) {
      devices[i][j] = 0;
    }
  }

  // Prompt the user to input the number of connections between devices
  printf("Please enter the number of connections between devices: ");
  scanf("%d", &num_connections);

  // Loop through and collect information on each connection
  for (i = 0; i < num_connections; i++) {
    printf("Please enter the connection number %d:\n", i + 1);
    printf("Device number: ");
    scanf("%d", &device_num);
    printf("Connected to device number: ");
    scanf("%d", &conn_num);

    // Record the connection in the devices array
    devices[device_num][conn_num] = 1;
    devices[conn_num][device_num] = 1;
  }

  // Print out the resulting network topology map
  printf("Network Topology Map:\n\n");
  for (i = 0; i < num_devices; i++) {
    printf("Device %d is connected to devices: ", i);
    for (j = 0; j < num_devices; j++) {
      if (devices[i][j] == 1) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }

  return 0;
}