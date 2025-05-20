//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50

int main() {
    int num_devices;
    int adjacency_matrix[MAX_DEVICES][MAX_DEVICES]; // to store adjacency matrix
    char device_names[MAX_DEVICES][20]; // to store device names
    char input[20]; // to get user input
    int i, j;

    printf("Welcome to Network Topology Mapper\n\n");

    // get number of devices from user
    printf("Enter number of devices: ");
    scanf("%d", &num_devices);

    // get device names from user and store them in device_names array
    for (i = 0; i < num_devices; i++) {
        printf("Enter name of device %d: ", (i+1));
        scanf("%s", device_names[i]);
    }

    // initialize adjacency matrix with 0s
    for (i = 0; i < num_devices; i++) {
        for (j = 0; j < num_devices; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    // get connections between devices from user and store them in adjacency matrix
    for (i = 0; i < num_devices; i++) {
        printf("Does device %s have any connections? (y/n): ", device_names[i]);
        scanf("%s", input);

        if (strcmp(input, "y") == 0 || strcmp(input, "Y") == 0) {
            int num_connections;
            printf("How many connections does device %s have?: ", device_names[i]);
            scanf("%d", &num_connections);

            for (j = 0; j < num_connections; j++) {
                char connected_device[20];
                int k;

                printf("Enter name of connected device %d: ", (j+1));
                scanf("%s", connected_device);

                // find index of connected device in device_names array
                for (k = 0; k < num_devices; k++) {
                    if (strcmp(device_names[k], connected_device) == 0) {
                        adjacency_matrix[i][k] = 1;
                        adjacency_matrix[k][i] = 1; // since it is an undirected graph
                        break;
                    }
                }
            }
        }
    }

    // print adjacency matrix
    printf("\nAdjacency Matrix:\n\n");
    printf("  ");
    for (i = 0; i < num_devices; i++) {
        printf("%s ", device_names[i]);
    }
    printf("\n");

    for (i = 0; i < num_devices; i++) {
        printf("%s ", device_names[i]);
        for (j = 0; j < num_devices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nThank you for using Network Topology Mapper!\n");

    return 0;
}