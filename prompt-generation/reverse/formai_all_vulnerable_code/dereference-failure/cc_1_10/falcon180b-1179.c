//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_LINKS 1000
#define MAX_DIST 1000

typedef struct _Node {
    char name[20];
    int id;
    int x, y;
    int visited;
    struct _Node* link[MAX_LINKS];
    int link_count;
    double dist[MAX_NODES];
} Node;

Node* CreateNode(char* name, int id, int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->id = id;
    node->x = x;
    node->y = y;
    node->visited = 0;
    node->link_count = 0;
    for (int i = 0; i < MAX_NODES; i++) {
        node->dist[i] = MAX_DIST;
    }
    return node;
}

void AddLink(Node* node1, Node* node2) {
    node1->link[node1->link_count++] = node2;
    node2->link[node2->link_count++] = node1;
}

void Dijkstra(Node* start_node) {
    int i, j, k, min_dist, u, v;
    for (i = 0; i < start_node->link_count; i++) {
        Node* node = start_node->link[i];
        node->dist[node->id] = 0;
    }
    for (i = 1; i < start_node->link_count; i++) {
        for (j = 0; j < start_node->link_count; j++) {
            if (start_node->dist[j] + start_node->link[j]->dist[i] < start_node->link[i]->dist[i]) {
                start_node->link[i]->dist[i] = start_node->dist[j] + start_node->link[j]->dist[i];
            }
        }
    }
}

void PrintSolution(Node* node) {
    printf("Node %s (%d) has the shortest distance of %d\n", node->name, node->id, node->dist[0]);
}

int main() {
    Node* node1 = CreateNode("Node1", 1, 0, 0);
    Node* node2 = CreateNode("Node2", 2, 0, 1);
    Node* node3 = CreateNode("Node3", 3, 1, 1);
    Node* node4 = CreateNode("Node4", 4, 1, 0);
    AddLink(node1, node2);
    AddLink(node1, node3);
    AddLink(node2, node4);
    Dijkstra(node1);
    PrintSolution(node1);
    return 0;
}