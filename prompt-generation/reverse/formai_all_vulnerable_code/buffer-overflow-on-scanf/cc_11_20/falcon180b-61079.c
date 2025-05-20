//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100

typedef struct{
    char name[20];
    int num_connections;
    int connections[10];
}Node;

int main(){

    int num_nodes, i, j, k, conn_count, valid_input;
    char input_line[100];
    char delimiter = ',';
    Node nodes[MAX_NODES];

    printf("Enter the number of nodes in the network: ");
    scanf("%d", &num_nodes);

    for(i=0; i<num_nodes; i++){
        printf("Enter node name for node %d: ", i+1);
        scanf("%s", nodes[i].name);

        printf("Enter the number of connections for node %s: ", nodes[i].name);
        scanf("%d", &nodes[i].num_connections);

        if(nodes[i].num_connections > 10 || nodes[i].num_connections < 0){
            printf("Invalid number of connections for node %s\n", nodes[i].name);
            exit(1);
        }

        printf("Enter the connections for node %s (separated by commas): ", nodes[i].name);
        scanf("%s", input_line);

        conn_count = 0;
        valid_input = 1;

        for(j=0; j<strlen(input_line); j++){
            if(input_line[j] == delimiter){
                if(conn_count >= nodes[i].num_connections){
                    printf("Invalid number of connections for node %s\n", nodes[i].name);
                    exit(1);
                }
                else{
                    conn_count++;
                }
            }
            else{
                if(isdigit(input_line[j]) == 0){
                    printf("Invalid input for node %s\n", nodes[i].name);
                    valid_input = 0;
                    break;
                }
                else{
                    nodes[i].connections[conn_count] = input_line[j] - '0';
                }
            }
        }

        if(valid_input == 0){
            exit(1);
        }
    }

    printf("Enter the topology of the network (e.g. ring, star, mesh): ");
    scanf("%s", input_line);

    if(strcmp(input_line, "ring") == 0){
        // Code for ring topology
    }
    else if(strcmp(input_line, "star") == 0){
        // Code for star topology
    }
    else if(strcmp(input_line, "mesh") == 0){
        // Code for mesh topology
    }
    else{
        printf("Invalid topology entered\n");
        exit(1);
    }

    return 0;
}