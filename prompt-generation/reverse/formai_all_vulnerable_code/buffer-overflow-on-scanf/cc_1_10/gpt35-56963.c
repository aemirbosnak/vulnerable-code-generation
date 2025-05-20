//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTES 100
#define MAX_NODES 50

struct node {
    int id;
    char name[50];
    double latitude;
    double longitude;
};

struct route {
    int id;
    char name[50];
    int num_nodes;
    struct node nodes[MAX_NODES];
};

int main() {
    struct route routes[MAX_ROUTES];
    int num_routes = 0;
    
    // ADD NEW ROUTE
    struct route new_route;
    new_route.id = num_routes + 1;
    printf("Enter name of new route: ");
    fgets(new_route.name, 50, stdin);
    strtok(new_route.name, "\n"); // remove newline character
    printf("Enter number of nodes in route: ");
    scanf("%d", &new_route.num_nodes);
    getchar(); // consume newline character
    
    for (int i = 0; i < new_route.num_nodes; i++) {
        printf("Enter name of node %d: ", i+1);
        fgets(new_route.nodes[i].name, 50, stdin);
        strtok(new_route.nodes[i].name, "\n"); // remove newline character
        printf("Enter latitude of node %d: ", i+1);
        scanf("%lf", &new_route.nodes[i].latitude);
        printf("Enter longitude of node %d: ", i+1);
        scanf("%lf", &new_route.nodes[i].longitude);
        getchar(); // consume newline character
    }
    
    routes[num_routes] = new_route;
    num_routes++;
    
    // SEARCH FOR NODE
    char search_name[50];
    printf("Enter name of node to search for: ");
    fgets(search_name, 50, stdin);
    strtok(search_name, "\n"); // remove newline character
    
    int found = 0;
    for (int i = 0; i < num_routes; i++) {
        for (int j = 0; j < routes[i].num_nodes; j++) {
            if (strcmp(routes[i].nodes[j].name, search_name) == 0) {
                printf("Node found in route %s\n", routes[i].name);
                printf("Latitude: %lf\n", routes[i].nodes[j].latitude);
                printf("Longitude: %lf\n", routes[i].nodes[j].longitude);
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    
    if (!found) {
        printf("Node not found.\n");
    }
    
    return 0;
}