//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NODES 10

typedef struct node {
    char name[10];
    int status;
} node;

void map_topology(node* topology, int size);

int main() {
    int size, i;
    node topology[MAX_NODES];

    printf("Enter number of nodes in your network topology (max %d): ", MAX_NODES);
    scanf("%d", &size);

    if (size > MAX_NODES || size <= 0) {
        printf("Invalid number of nodes, please try again.\n");
        exit(1);
    }

    for (i = 0; i < size; i++) {
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", topology[i].name);
        topology[i].status = -1;
    }

    map_topology(topology, size);

    printf("\nNode status:\n");
    for (i = 0; i < size; i++) {
        printf("%s: %d\n", topology[i].name, topology[i].status);
    }

    return 0;
}

void map_topology(node* topology, int size) {
    int i;
    printf("Mapping network topology...\n");
    sleep(2);

    for (i = 0; i < size; i++) {
        printf("Pinging %s...\n", topology[i].name);
        sleep(1);
        topology[i].status = rand() % 2;
    }
  
    printf("Network topology mapping completed.\n");
}