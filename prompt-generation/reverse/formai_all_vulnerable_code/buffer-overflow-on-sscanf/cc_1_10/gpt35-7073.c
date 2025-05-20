//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROUTES 10
#define MAX_NODES 50
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    double longitude;
    double latitude;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int num_nodes;
} Route;

typedef struct {
    Route routes[MAX_ROUTES];
    int num_routes;
} Map;

Route create_route(char name[], Node nodes[], int num_nodes) {
    Route route = {
        .num_nodes = num_nodes
    };
    strcpy(route.nodes[0].name, name); // Set the route name
    for (int i = 0; i < num_nodes; i++) {
        route.nodes[i+1] = nodes[i]; // Add the nodes to the route
    }
    return route;
}

Map create_map(Route routes[], int num_routes) {
    Map map = {
        .num_routes = num_routes
    };
    for (int i = 0; i < num_routes; i++) {
        map.routes[i] = routes[i]; // Add the routes to the map
    }
    return map;
}

void print_node(Node node) {
    printf("%s: (%lf, %lf)\n", node.name, node.longitude, node.latitude);
}

void print_route(Route route) {
    printf("%s\n", route.nodes[0].name); // Print route name
    for (int i = 1; i <= route.num_nodes; i++) {
        print_node(route.nodes[i]); // Print nodes in route
    }
}

void print_map(Map map) {
    for (int i = 0; i < map.num_routes; i++) {
        print_route(map.routes[i]); // Print all routes in map
    }
}

Node parse_node(char line[]) {
    char name[MAX_NAME_LENGTH];
    double longitude, latitude;
    sscanf(line, "%s %lf %lf", name, &longitude, &latitude); // Parse the node from the input line
    Node node = {
        .longitude = longitude,
        .latitude = latitude
    };
    strcpy(node.name, name); // Set the node name
    return node;
}

Route parse_route(char line[]) {
    char name[MAX_NAME_LENGTH];
    sscanf(line, "%s", name); // Parse the route name
    char* node_tokens = strtok(line+strlen(name)+1, ","); // Tokenize the line to read in all nodes in the route
    int num_nodes = 0;
    Node nodes[MAX_NODES];
    while (node_tokens != NULL) {
        nodes[num_nodes++] = parse_node(node_tokens);
        node_tokens = strtok(NULL, ",");
    }
    return create_route(name, nodes, num_nodes);
}

Map parse_map(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) { // Check if file was successfully opened
        printf("Error opening file\n");
        exit(1);
    }
    char line[100];
    Map map = {
        .num_routes = 0
    };
    while (fgets(line, 100, fp)) {
        map.routes[map.num_routes++] = parse_route(line); // Parse each route from the input file
    }
    fclose(fp);
    return map;
}

Node get_nearest_node(Node current_location, Route route) {
    double shortest_distance = __DBL_MAX__;
    Node nearest_node;
    for (int i = 1; i <= route.num_nodes; i++) {
        double distance = sqrt(pow(route.nodes[i].longitude - current_location.longitude, 2) + pow(route.nodes[i].latitude - current_location.latitude, 2)); // Euclidean distance formula
        if (distance < shortest_distance) {
            shortest_distance = distance;
            nearest_node = route.nodes[i];
        }
    }
    return nearest_node;
}

int get_route_index(Map map, char name[]){
    for(int i = 0; i < map.num_routes; i++){
        if(strcmp(map.routes[i].nodes[0].name, name) == 0){
            return i;
        }
    }
    printf("Error: Route not found\n");
    exit(1);
}

void simulate_route(Map map, Node start, char end_route[]) {
    int current_route = 0;
    Node current_location = start;
    printf("Starting at: ");
    print_node(start);
    while (strcmp(map.routes[current_route].nodes[0].name, end_route) != 0) { // Keep simulating until end route is reached
        Node nearest_node = get_nearest_node(current_location, map.routes[current_route]);
        printf("Traveling to: ");
        print_node(nearest_node);
        current_location = nearest_node;
        if (nearest_node.name[0] == '#') { // Check if next node is a route change
            current_route = get_route_index(map, nearest_node.name+1);
            printf("Changing to route: %s\n", nearest_node.name+1);
        }
    }
    printf("Reached destination: %s\n", end_route);
}

int main(int argc, char* argv[]) {
    if (argc <= 2) { // Check if correct number of arguments are passed
        printf("Usage: %s <map file> <starting node> <ending route>\n", argv[0]);
        return 0;
    }
    Map map = parse_map(argv[1]);
    Node start = parse_node(argv[2]);
    simulate_route(map, start, argv[3]);
    return 0;
}