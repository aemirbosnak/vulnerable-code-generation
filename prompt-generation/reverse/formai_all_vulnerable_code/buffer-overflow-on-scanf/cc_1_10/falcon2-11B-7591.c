//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int graph[4][4] = {{0, 1, 0, 0},
                       {1, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};
    char name1[20], name2[20], name3[20], name4[20];

    // prompt user for names and create nodes in the graph
    printf("Enter names for four people:\n");
    scanf("%s %s %s %s", name1, name2, name3, name4);

    // check if names are valid and create nodes in the graph
    if (strcmp(name1, "Alice") == 0 &&
        strcmp(name2, "Bob") == 0 &&
        strcmp(name3, "Carol") == 0 &&
        strcmp(name4, "David") == 0) {
        graph[0][0] = 1; // Alice -> Bob
        graph[0][1] = 1; // Alice -> Carol
        graph[1][0] = 1; // Bob -> Alice
        graph[1][1] = 1; // Bob -> Carol
        graph[2][0] = 1; // Carol -> Alice
        graph[2][1] = 1; // Carol -> Bob
        graph[3][0] = 1; // David -> Alice
        graph[3][1] = 1; // David -> Bob
        graph[3][2] = 1; // David -> Carol
    } else {
        printf("Invalid names entered.\n");
        return 1;
    }

    // prompt user for starting and ending nodes
    printf("Enter starting and ending nodes:\n");
    scanf("%s %s", name1, name2);

    // find shortest path between starting and ending nodes
    int shortest_path[4][4] = {{0, 0, 0, 0}};
    int distance = 0;
    int current_node = 0;

    for (int i = 0; i < 4; i++) {
        if (graph[current_node][i]) {
            shortest_path[i][0] = current_node;
            shortest_path[i][1] = distance;
            distance++;
            current_node = i;
        }
    }

    printf("Shortest path from %s to %s is:\n", name1, name2);
    printf("    %s\n", name1);
    printf("    %s\n", name2);
    printf("    %s\n", name3);
    printf("    %s\n", name4);

    return 0;
}