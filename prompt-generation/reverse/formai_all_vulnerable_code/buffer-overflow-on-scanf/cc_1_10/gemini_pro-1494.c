//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Ada Lovelace
// Lady Ada Lovelace's Network Topology Mapper

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Enchanting Constants
#define MAX_NODES 100
#define MAX_LINKS 100

// Enchanting Structures
typedef struct {
    char name[100];
    char ip[100];
    char mac[100];
} Node;

typedef struct {
    Node *node1;
    Node *node2;
    int weight;
} Link;

// Enchanting Functions
int main() {
    // Declare variables and arrays
    int numNodes = 0;
    int numLinks = 0;
    Node nodes[MAX_NODES];
    Link links[MAX_LINKS];

    // Greet the user
    printf("Greetings, fair user. I am Lady Ada Lovelace, the enchantress of networks.\n");
    printf("Allow me to map the topology of your enchanting network.\n");

    // Gather information about the nodes
    printf("How many nodes reside in your network, fair user?\n");
    scanf("%d", &numNodes);
    for (int i = 0; i < numNodes; i++) {
        printf("Enter the name of node %d:\n", i + 1);
        scanf("%s", nodes[i].name);
        printf("Enter the IP address of node %d:\n", i + 1);
        scanf("%s", nodes[i].ip);
        printf("Enter the MAC address of node %d:\n", i + 1);
        scanf("%s", nodes[i].mac);
    }

    // Gather information about the links
    printf("How many links connect your enchanting nodes, fair user?\n");
    scanf("%d", &numLinks);
    for (int i = 0; i < numLinks; i++) {
        printf("Enter the names of the nodes connected by link %d:\n", i + 1);
        scanf("%s %s", links[i].node1->name, links[i].node2->name);
        printf("Enter the weight of link %d:\n", i + 1);
        scanf("%d", &links[i].weight);
    }

    // Print the network topology
    printf("Behold, fair user, the enchanting topology of your network:\n");
    printf("Nodes:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("%s (%s, %s)\n", nodes[i].name, nodes[i].ip, nodes[i].mac);
    }
    printf("Links:\n");
    for (int i = 0; i < numLinks; i++) {
        printf("%s -- %d --> %s\n", links[i].node1->name, links[i].weight, links[i].node2->name);
    }

    // Farewell the user
    printf("My enchantments end here, fair user. May your network forever bring you joy.\n");
    return 0;
}