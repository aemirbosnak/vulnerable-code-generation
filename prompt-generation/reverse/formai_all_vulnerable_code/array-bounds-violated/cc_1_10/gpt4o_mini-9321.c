//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_CONNECTIONS 10

typedef struct {
    char name[20];
    int id;
    int connections[MAX_CONNECTIONS];
    int connection_count;
} Node;

Node network[MAX_NODES];
int node_count = 0;

void add_node(char *name) {
    if (node_count < MAX_NODES) {
        strcpy(network[node_count].name, name);
        network[node_count].id = node_count;
        network[node_count].connection_count = 0;
        node_count++;
    } else {
        printf("Maximum node limit reached!\n");
    }
}

void add_connection(int id1, int id2) {
    if (id1 < node_count && id2 < node_count) {
        if (network[id1].connection_count < MAX_CONNECTIONS &&
            network[id2].connection_count < MAX_CONNECTIONS) {
            network[id1].connections[network[id1].connection_count++] = id2;
            network[id2].connections[network[id2].connection_count++] = id1;
        } else {
            printf("Maximum connection limit reached for nodes %d and %d!\n", id1, id2);
        }
    } else {
        printf("Invalid node IDs: %d, %d\n", id1, id2);
    }
}

void list_network() {
    for (int i = 0; i < node_count; i++) {
        printf("Node %d (%s): ", network[i].id, network[i].name);
        for (int j = 0; j < network[i].connection_count; j++) {
            printf("%d ", network[i].connections[j]);
        }
        printf("\n");
    }
}

void remove_node(int id) {
    if (id >= 0 && id < node_count) {
        for (int i = 0; i < node_count; i++) {
            for (int j = 0; j < network[i].connection_count; j++) {
                if (network[i].connections[j] == id) {
                    network[i].connections[j] = network[i].connections[network[i].connection_count - 1];
                    network[i].connection_count--;
                    break;
                }
            }
        }
        for (int i = id; i < node_count - 1; i++) {
            network[i] = network[i + 1];
            network[i].id--;
        }
        node_count--;
    } else {
        printf("Invalid node ID to remove: %d\n", id);
    }
}

void clear_network() {
    node_count = 0;
}

int main() {
    char command[50];
    char name[20];
    int id1, id2;

    while (1) {
        printf("Network Topology Mapper Menu:\n");
        printf("1. Add Node\n");
        printf("2. Add Connection\n");
        printf("3. List Network\n");
        printf("4. Remove Node\n");
        printf("5. Clear Network\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        fgets(command, sizeof(command), stdin);

        switch (atoi(command)) {
            case 1:
                printf("Enter Node Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline
                add_node(name);
                break;
            case 2:
                printf("Enter IDs of nodes to connect (e.g. 0 1): ");
                scanf("%d %d", &id1, &id2);
                add_connection(id1, id2);
                // Clear newline character left by scanf
                while (getchar() != '\n');
                break;
            case 3:
                list_network();
                break;
            case 4:
                printf("Enter Node ID to remove: ");
                scanf("%d", &id1);
                remove_node(id1);
                while (getchar() != '\n');
                break;
            case 5:
                clear_network();
                printf("Network cleared!\n");
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}