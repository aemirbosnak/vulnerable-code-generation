//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

/* Structure to store information about a node */
typedef struct {
    char name[20];
    int connections[MAX_NODES]; /* Stores indices of connected nodes */
    int num_connections;
} Node;

int main(int argc, char *argv[]) {
    int num_nodes = 0;
    Node nodes[MAX_NODES];

    /* Check if input file was provided */
    if(argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    /* Open input file */
    FILE *input_file = fopen(argv[1], "r");
    if(input_file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }

    /* Read information about each node */
    char line[100];
    while(fgets(line, sizeof(line), input_file) != NULL) {
        char *name = strtok(line, ":");
        if(name == NULL) {
            printf("Invalid input file format!\n");
            return 1;
        }
        strcpy(nodes[num_nodes].name, name);

        /* Read connections */
        char *connections = strtok(NULL, "\n");
        if(connections != NULL && strlen(connections) > 0) {
            char *connection = strtok(connections, ",");
            while(connection != NULL) {
                int index = atoi(connection);
                if(index < 0 || index >= num_nodes || index == num_nodes) {
                    printf("Invalid input file format!\n");
                    return 1;
                }
                nodes[num_nodes].connections[nodes[num_nodes].num_connections++] = index;
                connection = strtok(NULL, ",");
            }
        }

        num_nodes++;
        if(num_nodes == MAX_NODES) {
            printf("Too many nodes!\n");
            return 1;
        }
    }

    /* Print network topology */
    printf("Network Topology:\n");
    for(int i = 0; i < num_nodes; i++) {
        printf("%s -> ", nodes[i].name);
        for(int j = 0; j < nodes[i].num_connections - 1; j++) {
            printf("%s, ", nodes[nodes[i].connections[j]].name);
        }
        if(nodes[i].num_connections > 0) {
            printf("%s", nodes[nodes[i].connections[nodes[i].num_connections - 1]].name);
        }
        printf("\n");
    }

    return 0;
}